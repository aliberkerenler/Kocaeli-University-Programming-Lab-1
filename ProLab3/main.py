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


# Node ve Edge yapılarını manuel olarak oluşturma
def create_manual_graph(data):
    nodes = {}  # Anahtar: node_id, Değer: Node bilgileri
    edges = {}  # Kenarları (source, target) çiftleri olarak saklayacağız.
    main_authors = set()  # Ana düğüm yazarlarını saklamak için
    author_paper_count = {}  # Her yazarın makale sayısını tutacağız

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
                "paper_title": paper_title,
                "doi": doi,
                "papers": set(),
                "color": "orange"
            }
            main_authors.add(node_id)  # Ana düğümleri kaydediyoruz.
            nodes[node_id]["papers"].add(paper_title)

            # Yazarın makale sayısını kaydet
            author_paper_count[author] = author_paper_count.get(author, 0) + 1

        # Yardımcı yazar düğümleri ve kenarları ekleme
        for coauthor in coauthors:
            if not coauthor:  # Boş yazar ismini atla
                continue
            coauthor_id = coauthor
            if coauthor_id not in nodes:
                nodes[coauthor_id] = {
                    "label": coauthor,
                    "orcid": "N/A",
                    "papers": set(),
                    "color": "lightblue"
                }
            # Ana yazar ile yardımcı yazar arasında kenar ekleme
            edge = tuple(sorted((node_id, coauthor_id)))  # Kenar yönsüz olduğu için sıralı tutuyoruz
            if edge not in edges:
                edges[edge] = 0
            edges[edge] += 1  # Kenar ağırlığını artır

    return nodes, edges, main_authors, author_paper_count


def visualize_graph(nodes, edges, author_paper_count, output_file="manual_graph_visualization.html"):
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
    avg_paper_count = sum(author_paper_count.values()) / len(author_paper_count)

    # Düğümleri ekleme
    for node_id, node_data in nodes.items():
        paper_count = len(node_data["papers"])
        if paper_count > avg_paper_count * 1.2:  # %20 üzerinde olanlar
            size = 40
            color = "darkorange"
        elif paper_count < avg_paper_count * 0.8:  # %20 altında olanlar
            size = 20
            color = "lightblue"
        else:  # Ortalama civarında olanlar
            size = 30
            color = "gray"

        graph.add_node(
            node_id,
            label=node_data['label'],
            title=f"""
                <b>Yazar:</b> {node_data['label']}<br>
                <b>ORCID:</b> {node_data['orcid']}<br>
                <b>Toplam Makale Sayısı:</b> {paper_count}<br>
                <b>Makaleler:</b><br>{'<br>'.join(node_data['papers'])}
            """,
            color=color,
            size=size
        )

    # Kenarları ekleme
    for (source, target), weight in edges.items():
        graph.add_edge(source, target, value=weight, width=weight * 2, title=f"Ortak Makale Sayısı: {weight}",color="white")

    # Grafı görselleştir
    graph.show(output_file, notebook=False)


# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyasının yolu
    data = read_excel_data(excel_file)
    nodes, edges, main_authors, author_paper_count = create_manual_graph(data)

    # Toplam düğüm sayısı, kenar sayısı ve ana düğüm sayısını yazdırma
    print("Graf Bilgileri:")
    print(f"Toplam Düğüm Sayısı: {len(nodes)}")
    print(f"Toplam Kenar Sayısı: {len(edges)}")
    print(f"Toplam Ana Düğüm Sayısı: {len(main_authors)}")

    # Yazarların toplam makale sayılarını yazdır
    print("\nYazarların Toplam Makale Sayıları:")
    for author, count in author_paper_count.items():
        print(f"{author}: {count}")

    # Grafı görselleştir
    visualize_graph(nodes, edges, author_paper_count)


if __name__ == "__main__":
    main()
