import pandas as pd
from pyvis.network import Network
import ast  # String'i listeye dönüştürmek için kullanılacak
from flask import Flask, request, render_template_string,jsonify
import os

app = Flask(__name__)

# Global değişkenler
nodes = {}
edges = {}


# Excel'den veri okuma fonksiyonu
def read_excel_data(file_path):
    df = pd.read_excel(file_path)
    required_columns = ['orcid', 'doi', 'author_position', 'author_name', 'coauthors', 'paper_title']
    for col in required_columns:
        if col not in df.columns:
            raise ValueError(f"Excel dosyasında '{col}' sütunu eksik!")
    return df[required_columns]


# Excel dosyasını burada okuyoruz, örneğin 'data.xlsx' dosyasını kullanarak
data = read_excel_data('dataset.xlsx')


# Tüm yazarların toplam makale sayısını hesaplayan fonksiyon
def calculate_author_total_papers(data):
    author_total_papers = {}
    for _, row in data.iterrows():
        try:
            coauthors = ast.literal_eval(row['coauthors'])  # Coauthors listesini parse et
        except (ValueError, SyntaxError):
            coauthors = []
        coauthors = [coauthor.strip() for coauthor in coauthors if coauthor]  # Boş alanları temizle
        main_author = row['author_name'].strip()  # Ana yazarın ismi
        all_authors = set(coauthors)
        all_authors.add(main_author)
        for author in all_authors:
            author_total_papers[author] = author_total_papers.get(author, 0) + 1
    return author_total_papers



# A yazarı ve işbirliği yaptığı yazarların düğüm ağırlıklarına göre sıralanması
def calculate_node_weights(data, author_id):
    # Tüm yazarların toplam makale sayısını hesapla
    author_total_papers = calculate_author_total_papers(data)

    # A yazarı ile işbirliği yapan diğer yazarları belirle
    coauthors = set()
    for _, row in data.iterrows():
        if row['author_name'].strip() == author_id:
            try:
                row_coauthors = ast.literal_eval(row['coauthors'])
                coauthors.update([coauthor.strip() for coauthor in row_coauthors])
            except (ValueError, SyntaxError):
                continue

    # A yazarı ile işbirliği yapan yazarların makale sayısını al
    node_weights = []
    for coauthor in coauthors:
        if coauthor in author_total_papers:
            node_weights.append((coauthor, author_total_papers[coauthor]))

    # Düğüm ağırlıklarına göre sıralama
    node_weights.sort(key=lambda x: x[1], reverse=True)  # Ağırlığa göre azalan sırada sıralanır

    return node_weights

@app.route('/calculate_node_weights/<author_id>', methods=['GET'])
def calculate_node_weights_route(author_id):
    weights = calculate_node_weights(data, author_id)
    return jsonify({'weights': [{'name': author, 'articles': count} for author, count in weights]})


# En çok işbirliği yapan yazarı belirleme
def find_most_collaborative_author(edges):
    collaboration_count = {}
    for (source, target), weight in edges.items():
        collaboration_count[source] = collaboration_count.get(source, 0) + weight
        collaboration_count[target] = collaboration_count.get(target, 0) + weight
    most_collaborative_author = max(collaboration_count, key=collaboration_count.get)
    max_collaborations = collaboration_count[most_collaborative_author]
    return most_collaborative_author, max_collaborations


# Node ve Edge yapılarını manuel olarak oluşturma
def create_manual_graph(data):
    global nodes, edges  # global olarak tanımlıyoruz
    nodes = {}
    edges = {}
    main_authors = set()
    for _, row in data.iterrows():
        author = row['author_name'].strip()
        orcid = row['orcid']
        paper_title = row['paper_title']
        doi = row['doi']
        position = row['author_position']
        try:
            coauthors = ast.literal_eval(row['coauthors'])  # Coauthors listesini parse et
        except (ValueError, SyntaxError):
            coauthors = []
        coauthors = [coauthor.strip() for coauthor in coauthors]
        if 1 <= position <= len(coauthors):
            position -= 1
            main_author_in_coauthors = coauthors[position]
            coauthors.remove(main_author_in_coauthors)
        node_id = f"{author}-{orcid}"
        if node_id not in nodes:
            nodes[node_id] = {
                "label": author,
                "orcid": orcid,
                "papers": {},
                "color": "orange"
            }
            main_authors.add(node_id)
        nodes[node_id]["papers"][doi] = paper_title
        for coauthor in coauthors:
            if not coauthor:
                continue
            coauthor_id = coauthor
            if coauthor_id not in nodes:
                nodes[coauthor_id] = {
                    "label": coauthor,
                    "orcid": "N/A",
                    "papers": {},
                    "color": "lightblue"
                }
            edge = tuple(sorted((node_id, coauthor_id)))
            if edge not in edges:
                edges[edge] = 0
            edges[edge] += 1
    return nodes, edges, main_authors



# Graf görselleştirme ve HTML oluşturma
def visualize_graph_with_output(nodes, edges, author_total_papers):
    graph = Network(height="800px", width="100%", bgcolor="#222222", font_color="white")
    graph.set_options(""" 
    var options = {
      "nodes": {
        "scaling": {
          "min": 10,
          "max": 50
        }
      },
      "edges": {
        "arrows": {
          "to": false
        },
        "color": {
          "inherit": true
        },
        "smooth": false
      },
      "physics": {
        "enabled": true,
        "solver": "forceAtlas2Based",
        "forceAtlas2Based": {
          "gravitationalConstant": -300,
          "centralGravity": 0.005,
          "springLength": 200,
          "springConstant": 0.03
        },
        "minVelocity": 0.5,
        "timestep": 0.35
      }
    }
    """)
    avg_paper_count = sum(author_total_papers.values()) / len(author_total_papers)
    for node_id, node_data in nodes.items():
        author_name = node_data['label']
        paper_count = author_total_papers.get(author_name, 0)
        paper_info = node_data.get("papers", {})
        paper_details = "<br>".join(
            [f"<b>DOI:</b> {doi} - <b>Başlık:</b> {title}" for doi, title in paper_info.items()]
        )
        if paper_count > avg_paper_count * 1.2:
            size = 80
            color = "darkorange"
        elif paper_count < avg_paper_count * 0.8:
            size = 40
            color = "lightblue"
        else:
            size = 60
            color = "gray"
        graph.add_node(
            node_id,
            label=node_data['label'],
            title=f"""
                <b>Yazar:</b> {node_data['label']}<br>
                <b>ORCID:</b> {node_data['orcid']}<br>
                <b>Toplam Makale Sayısı:</b> {paper_count}<br>
                <b>Makaleler:</b><br>{paper_details if paper_details else 'Bu yazar için makale bilgisi yok.'}
            """,
            color=color,
            size=size
        )
    for (source, target), weight in edges.items():
        graph.add_edge(source, target, value=weight, width=weight * 2, title=f"Ortak Makale Sayısı: {weight}",
                       color="white")
    return graph

# En uzun yolu bulma fonksiyonu
def find_longest_path(start_node, visited=None, current_path=None):
    if visited is None:
        visited = set()
    if current_path is None:
        current_path = []

    visited.add(start_node)
    current_path.append(start_node)

    longest_path = current_path.copy()  # Şu ana kadarki en uzun yol
    for (source, target) in edges:
        if source == start_node and target not in visited:
            new_path = find_longest_path(target, visited, current_path)
            if len(new_path) > len(longest_path):
                longest_path = new_path
        elif target == start_node and source not in visited:
            new_path = find_longest_path(source, visited, current_path)
            if len(new_path) > len(longest_path):
                longest_path = new_path

    # Backtracking (geri alma)
    visited.remove(start_node)
    current_path.pop()

    return longest_path

# En kısa yol bulma algoritması (BFS uygulanarak)
def find_shortest_path_between_authors(start_author, end_author, nodes, edges):
    # BFS için bir kuyruk ve ziyaret edilen düğümler listesi
    queue = [(start_author, [start_author])]  # (current_node, path_so_far)
    visited = set()

    while queue:
        current_node, path = queue.pop(0)
        if current_node in visited:
            continue
        visited.add(current_node)

        # Eğer hedef düğüme ulaşırsak yolu döndür
        if current_node == end_author:
            return path

        # Komşu düğümleri sıraya ekle
        for edge in edges:
            if current_node in edge:
                neighbor = edge[0] if edge[1] == current_node else edge[1]
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

    # Eğer hedef düğüme ulaşılamazsa boş liste döndür
    return []

@app.route('/shortest_path/<start_author>/<end_author>', methods=['GET'])
def shortest_path_route(start_author, end_author):
    start_author = start_author.strip().lower()
    end_author = end_author.strip().lower()

    # Kullanıcı girdisine göre düğüm ID'lerini bul
    start_node = next((node_id for node_id, node_data in nodes.items()
                       if start_author in node_id.lower() or start_author in node_data['label'].lower()), None)
    end_node = next((node_id for node_id, node_data in nodes.items()
                     if end_author in node_id.lower() or end_author in node_data['label'].lower()), None)

    if not start_node or not end_node:
        return f"Hata: '{start_author}' veya '{end_author}' girdisiyle eşleşen bir yazar bulunamadı."

    # En kısa yol algoritmasını çağır
    path = find_shortest_path_between_authors(start_node, end_node, nodes, edges)

    if not path:
        return f"{start_author} ile {end_author} arasında bir bağlantı bulunamadı."

    # Yol detaylarını döndür
    path_details = " ➔ ".join([nodes[node]['label'] for node in path])
    path_length = len(path)

    return f"En kısa yol: {path_details} (Uzunluk: {path_length})"

# Flask route for finding the longest path
@app.route('/longest_path', methods=['POST'])
def get_longest_path():
    author_id = request.form.get('author_id')  # Kullanıcıdan yazar ID'si alınır
    if not author_id or author_id not in nodes:
        return f"Geçersiz veya bulunamayan yazar ID: {author_id}"

    longest_path = find_longest_path(author_id)
    path_labels = " ➔ ".join([nodes[node]['label'] for node in longest_path])
    path_length = len(longest_path)

    return f"Yazar {nodes[author_id]['label']} için en uzun yol: {path_labels} (Uzunluk: {path_length})"


# Kullanıcıdan gelen yazar ID'sine göre işbirliği sayısını hesaplama route'u
@app.route('/calculate_collaborators/<author_input>', methods=['GET'])
def calculate_collaborators(author_input):
    author_input = author_input.strip().lower()  # Kullanıcı girdisini temizle
    matching_node_ids = []  # Kullanıcının girdisine uygun düğüm ID'lerini toplayacağımız liste

    # Kullanıcının girdisiyle eşleşen node ID'lerini bul
    for node_id, node_data in nodes.items():
        if author_input in node_id.lower() or author_input in node_data['label'].lower():
            matching_node_ids.append(node_id)

    # Eğer eşleşen düğüm bulunamazsa hata mesajı döndür
    if not matching_node_ids:
        return f"Hata: '{author_input}' girdisiyle eşleşen bir yazar bulunamadı."

    # İşbirliği yapan yazarları toplamak için bir set kullanıyoruz
    collaborators = set()

    # edges üzerinden matching_node_ids ile işbirliği yapılan yazarları bul
    for (source, target) in edges:
        if any(node_id.lower() == source.lower() or node_id.lower() == target.lower() for node_id in matching_node_ids):
            collaborators.add(source)
            collaborators.add(target)

    # Seçilen yazarı işbirliği listesinden çıkar
    for node_id in matching_node_ids:
        collaborators.discard(node_id)

    # İşbirliği yapan toplam yazar sayısını hesapla
    total_collaborators = len(collaborators)

    # Sonuç mesajını döndür
    return f"'{author_input}' yazarının işbirliği yaptığı toplam yazar sayısı: {total_collaborators}"

# Flask route for file upload
@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        if 'file' not in request.files:
            return 'No file part'
        file = request.files['file']
        if file.filename == '':
            return 'No selected file'
        if file:
            file_path = os.path.join('uploads', file.filename)
            file.save(file_path)
            data = read_excel_data(file_path)
            author_total_papers = calculate_author_total_papers(data)
            nodes, edges, main_authors = create_manual_graph(data)
            graph = visualize_graph_with_output(nodes, edges, author_total_papers)
            most_collaborative_author, max_collaborations = find_most_collaborative_author(edges)
            # HTML şablonunu oluştur
            html_template = f"""
            <!DOCTYPE html>
            <html>
            <head>
                <title>Interactive Graph Visualization</title>
                <style>
                    body {{
                        display: flex;
                        margin: 0;
                        font-family: Arial, sans-serif;
                    }}
                    #sidebar {{
                        width: 20%;
                        background: #333;
                        color: white;
                        display: flex;
                        flex-direction: column;
                        padding: 10px;
                        height: 100vh;
                        box-sizing: border-box;
                    }}
                    #sidebar h3 {{
                        text-align: center;
                        margin-bottom: 10px;
                    }}
                    #buttons {{
                        flex: 1;
                        display: flex;
                        flex-direction: column;
                        justify-content: space-evenly;
                    }}
                    .button {{
                        margin: 5px 0;
                        padding: 10px;
                        text-align: center;
                        background: #444;
                        color: white;
                        border: 1px solid white;
                        cursor: pointer;
                        border-radius: 5px;
                    }}
                    .button:hover {{
                        background: #555;
                    }}
                    #output {{
                        flex: 1;
                        background: #222;
                        color: white;
                        padding: 10px;
                        overflow-y: auto;
                        border: 1px solid #444;
                        border-radius: 5px;
                        height: 30%;
                    }}
                    #graph-container {{
                        width: 80%;
                        height: 100vh;
                    }}
                </style>
                <script>
                    function updateOutput(content) {{
                        document.getElementById('output').innerHTML = content;
                    }}

                    function showMostCollaborativeAuthor() {{
                        const content = "En çok işbirliği yapan yazar: {most_collaborative_author} (Toplam İşbirliği: {max_collaborations})";
                        updateOutput(content);
                    }}

                    
                    function calculateNodeWeights() {{
            const authorId = prompt("Lütfen A yazarının ID'sini girin:");
            if (authorId) {{
                fetch(`/calculate_node_weights/${{authorId}}`)
                    .then(response => response.json())
                    .then(data => {{
                        let content = 'Düğüm ağırlıkları hesaplandı:<br>';
                        data.weights.forEach(weight => {{
                            content += `${{weight.name}}: ${{weight.articles}} makale<br>`;
                        }});
                        updateOutput(content);
                    }})
                    .catch(error => updateOutput('Bir hata oluştu: ' + error));
            }}
        }}

                    function createBSTFromQueue() {{
                        updateOutput('Kuyruktan BST oluşturuluyor...');
                        // Buraya kuyruktan BST oluşturma işlemi ekleyin
                    }}

                     function calculateShortestPath() {{
                        const startAuthor = prompt("Lütfen başlangıç yazarının ID'sini veya adını girin:");
                        const endAuthor = prompt("Lütfen bitiş yazarının ID'sini veya adını girin:");
                           if (startAuthor && endAuthor) {{
                               fetch(`/shortest_path/${{startAuthor}}/${{endAuthor}}`)
                               .then(response => response.text())
                           .then(data => updateOutput(data))
                            .catch(error => updateOutput('Bir hata oluştu: ' + error));
                        }}
                   }}

                    function calculateCollaborators() {{
                        const authorId = prompt("Lütfen yazar ID'sini girin (örneğin: 'John Doe-1234'):");
                        if (authorId) {{
                            fetch(`/calculate_collaborators/${{authorId}}`)
                                .then(response => response.text())
                                .then(data => updateOutput(data))
                                .catch(error => updateOutput('Bir hata oluştu: ' + error));
                        }}
                    }}

                    function findLongestPath() {{
                        const authorId = prompt("Lütfen bir yazar ID'si girin:");
                        if (!authorId) {{
                            updateOutput("Yazar ID'si girilmedi.");
                            return;
                        }}
                        fetch('/longest_path', {{
                            method: 'POST',
                            headers: {{
                                'Content-Type': 'application/x-www-form-urlencoded',
                            }},
                            body: `author_id=${{authorId}}`,
                        }})
                        .then(response => response.text())
                        .then(data => {{
                            updateOutput(data);
                        }})
                        .catch(error => {{
                            updateOutput("Hata: " + error.message);
                        }});
                    }}
                </script>
            </head>
            <body>
                <div id="sidebar">
                    <h3>İsterler</h3>
                    <div id="buttons">
                        <div class="button" onclick="calculateShortestPath()">1. A ile B yazarı arasındaki en kısa yol</div>
                        <div class="button" onclick="calculateNodeWeights()">2. A yazarı için düğüm ağırlıkları</div>
                        <div class="button" onclick="createBSTFromQueue()">3. Kuyruktan BST oluşturma</div>
                        <div class="button" onclick="calculateShortestPath()">4. Kısa yolları hesaplama</div>
                        <div class="button" onclick="calculateCollaborators()">5. İşbirliği yapan yazar sayısı</div>
                        <div class="button" onclick="showMostCollaborativeAuthor()">6. En çok işbirliği yapan yazar</div>
                        <div class="button" onclick="findLongestPath()">7. En uzun yolun bulunması</div>
                    </div>
                    <div id="output">Çıktılar burada görüntülenecek.</div>
                </div>
                <div id="graph-container">
                    {graph.generate_html()}
                </div>
            </body>
            </html>
            """
            return render_template_string(html_template)

    return '''
    <!doctype html>
    <title>Excel Dosyasını Yükle</title>
    <h1>Excel Dosyasını Yükle</h1>
    <form method=post enctype=multipart/form-data>
      <input type=file name=file>
      <input type=submit value=Yükle>
    </form>
    '''


if __name__ == '__main__':
    os.makedirs('uploads', exist_ok=True)
    app.run(debug=True)
