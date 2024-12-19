import pandas as pd
from pyvis.network import Network
import ast  # String'i listeye dönüştürmek için kullanılacak


# Excel'den veri okuma
def read_excel_data(file_path):
    df = pd.read_excel(file_path)
    required_columns = ['orcid', 'doi', 'author_position', 'author_name', 'coauthors', 'paper_title']
    for col in required_columns:
        if col not in df.columns:
            raise ValueError(f"Excel dosyasında '{col}' sütunu eksik!")
    return df[required_columns]


# Tüm yazarların toplam makale sayısını hesaplama
def calculate_author_total_papers(data):
    author_total_papers = {}

    for _, row in data.iterrows():
        try:
            coauthors = ast.literal_eval(row['coauthors'])  # Coauthors listesini parse et
        except (ValueError, SyntaxError):
            coauthors = []

        coauthors = [coauthor.strip() for coauthor in coauthors if coauthor]  # Boş alanları temizle
        main_author = row['author_name'].strip()  # Ana yazarın ismi

        # Tüm yazarları bir araya getir (ana yazar + yardımcı yazarlar)
        all_authors = set(coauthors)
        all_authors.add(main_author)

        # Her yazar için toplam makale sayısını artır
        for author in all_authors:
            author_total_papers[author] = author_total_papers.get(author, 0) + 1

    return author_total_papers


# Node ve Edge yapılarını manuel olarak oluşturma
def create_manual_graph(data):
    nodes = {}  # Anahtar: node_id, Değer: Node bilgileri
    edges = {}  # Kenarları (source, target) çiftleri olarak saklayacağız.
    main_authors = set()  # Ana düğüm yazarlarını saklamak için

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

        # Ana yazarı coauthors listesinden kaldır
        if 1 <= position <= len(coauthors):
            position -= 1  # 1 tabanlıyı 0 tabanlıya dönüştür
            main_author_in_coauthors = coauthors[position]
            coauthors.remove(main_author_in_coauthors)

        # Ana yazar düğümünü ekleme
        node_id = f"{author}-{orcid}"
        if node_id not in nodes:
            nodes[node_id] = {
                "label": author,
                "orcid": orcid,
                "papers": {},  # Yer aldığı makaleler için bir dictionary: {doi: paper_title}
                "color": "orange"
            }
            main_authors.add(node_id)  # Ana düğümleri kaydediyoruz.

        # Ana yazarın bulunduğu makaleyi set'e ekle
        nodes[node_id]["papers"][doi] = paper_title

        # Yardımcı yazar düğümleri ve kenarları ekleme
        for coauthor in coauthors:
            if not coauthor:  # Boş yazar ismini atla
                continue
            coauthor_id = coauthor
            if coauthor_id not in nodes:
                nodes[coauthor_id] = {
                    "label": coauthor,
                    "orcid": "N/A",
                    "papers": {},  # Yardımcı yazarın makaleleri için dictionary
                    "color": "lightblue"
                }
            # Ana yazar ile yardımcı yazar arasında kenar ekleme
            edge = tuple(sorted((node_id, coauthor_id)))  # Kenar yönsüz olduğu için sıralı tutuyoruz
            if edge not in edges:
                edges[edge] = 0
            edges[edge] += 1  # Kenar ağırlığını artır

    return nodes, edges, main_authors


def visualize_graph_with_output(nodes, edges, author_total_papers, output_file="interactive_graph.html"):
    graph = Network(height="800px", width="100%", bgcolor="#222222", font_color="white")

    # Fizik ayarlarını doğrudan set_options ile belirliyoruz
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

    # Ortalama makale sayısını hesapla
    avg_paper_count = sum(author_total_papers.values()) / len(author_total_papers)

    # Düğümleri ekleme
    for node_id, node_data in nodes.items():
        author_name = node_data['label']
        paper_count = author_total_papers.get(author_name, 0)

        # Makale bilgileri
        paper_info = node_data.get("papers", {})
        paper_details = "<br>".join(
            [f"<b>DOI:</b> {doi} - <b>Başlık:</b> {title}" for doi, title in paper_info.items()]
        )

        # Boyut ve renk belirleme
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

    # Kenarları ekleme
    for (source, target), weight in edges.items():
        graph.add_edge(source, target, value=weight, width=weight * 2, title=f"Ortak Makale Sayısı: {weight}", color="white")

    # HTML şablonu
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
        </script>
    </head>
    <body>
        <div id="sidebar">
            <h3>İsterler</h3>
            <div id="buttons">
                <div class="button" onclick="updateOutput('A ile B yazarı arasındaki en kısa yol hesaplaniyor...')">1. A ile B yazarı arasındaki en kısa yol</div>
                <div class="button" onclick="updateOutput('A yazarı için düğüm ağırlıkları hesaplandı.')">2. A yazarı için düğüm ağırlıkları</div>
                <div class="button" onclick="updateOutput('Kuyruktan BST oluşturuluyor...')">3. Kuyruktan BST oluşturma</div>
                <div class="button" onclick="updateOutput('Kısa yollar hesaplanıyor...')">4. Kısa yolları hesaplama</div>
                <div class="button" onclick="updateOutput('İşbirliği yapan yazar sayısı hesaplandı.')">5. İşbirliği yapan yazar sayısı</div>
                <div class="button" onclick="updateOutput('En çok işbirliği yapan yazar: [Sonuç].')">6. En çok işbirliği yapan yazar</div>
                <div class="button" onclick="updateOutput('En uzun yol bulunuyor...')">7. En uzun yolun bulunması</div>
            </div>
            <div id="output">Çıktılar burada görüntülenecek.</div>
        </div>
        <div id="graph-container">
            {graph.generate_html()}
        </div>
    </body>
    </html>
    """

    with open(output_file, "w", encoding="utf-8") as f:
        f.write(html_template)

    print(f"Graf çıktısı '{output_file}' olarak kaydedildi.")


# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyasının yolu
    data = read_excel_data(excel_file)
    author_total_papers = calculate_author_total_papers(data)
    nodes, edges, main_authors = create_manual_graph(data)

    # Toplam düğüm sayısı, kenar sayısı ve ana düğüm sayısını yazdırma
    print("Graf Bilgileri:")
    print(f"Toplam Düğüm Sayısı: {len(nodes)}")
    print(f"Toplam Kenar Sayısı: {len(edges)}")
    print(f"Toplam Ana Düğüm Sayısı: {len(main_authors)}")

    # Yazarların toplam makale sayılarını yazdır
    print("\nYazarların Toplam Makale Sayıları:")
    for author, count in author_total_papers.items():
        print(f"{author}: {count}")

    # Grafı görselleştir
    visualize_graph_with_output(nodes, edges, author_total_papers)


if __name__ == "__main__":
    main()
