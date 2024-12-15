import pandas as pd
from pyvis.network import Network
from collections import defaultdict
import webbrowser  # Tarayıcıda açmak için gerekli kütüphane


# Excel'den veri okuma
def read_excel_data(file_path):
    df = pd.read_excel(file_path)
    return df[['paper_title', 'coauthors']]


# Graf oluşturma
def create_graph(data):
    graph = Network(
        height="800px", width="100%", bgcolor="#222222", font_color="white", notebook=False
    )

    author_papers = defaultdict(list)  # Her yazarın katıldığı makaleler
    coauthorship = defaultdict(int)  # Yazarlar arası ortaklık sayısı

    # Düğümleri ve kenarları işleme
    for _, row in data.iterrows():
        title = row['paper_title']
        coauthors = [author.strip() for author in row['coauthors'].split(',')]

        # Her yazarın makalesini sakla
        for author in coauthors:
            author_papers[author].append(title)

        # Yazarlar arasında kenarları oluştur
        for i in range(len(coauthors)):
            for j in range(i + 1, len(coauthors)):
                pair = tuple(sorted([coauthors[i], coauthors[j]]))
                coauthorship[pair] += 1

    # Tüm düğümleri ekleme
    for author, papers in author_papers.items():
        graph.add_node(
            author,
            label=author,
            title=f"<b>{author}</b><br>Makaleler:<br>" + "<br>".join(papers),
            value=len(papers)  # Düğüm boyutunu makale sayısına göre ayarla
        )

    # Kenarları ekleme
    for (author1, author2), weight in coauthorship.items():
        if weight > 1:  # En az 2 ortak makalesi olan kenarlar gösterilsin
            graph.add_edge(author1, author2, value=weight, title=f"Ortak Makale Sayısı: {weight}")

    return graph, author_papers


# Ortalama makale sayısına göre düğüm stilini güncelleme
def update_node_styles(graph, author_papers):
    paper_counts = [len(papers) for papers in author_papers.values()]
    avg_paper_count = sum(paper_counts) / len(paper_counts) if paper_counts else 0

    for node in graph.nodes:
        paper_count = node['value']
        if paper_count > avg_paper_count * 1.2:  # %20 üzerinde
            node['color'] = 'darkred'
            node['size'] = 100
        elif paper_count < avg_paper_count * 0.8:  # %20 altında
            node['color'] = 'lightblue'
            node['size'] = 50
        else:
            node['color'] = 'orange'
            node['size'] = 70


# Graf görselleştirme ve tarayıcıda açma
def visualize_graph(graph, output_file="graph_visualization.html"):
    # Grafik fiziksel simülasyonu başlat ve düzenlemeyi aktif et
    graph.toggle_physics(True)

    # Physics için parametre ayarları
    graph.set_options("""
        var options = {
            "physics": {
                "enabled": true,
                "barnesHut": {
                    "gravitationalConstant": -10000,
                    "centralGravity": 0.0001,
                    "springLength": 5000,
                    "springConstant": 0.0001,
                    "damping": 0.09
                },
                "minVelocity": 0.75
            },
            "nodes": {
                "shape": "dot",
                "size": 70
            },
            "edges": {
                "color": "#ffffff",
                "smooth": {
                    "type": "continuous",
                    "forceDirection": "none"
                }
            }
        }
    """)

    # HTML içeriği oluştur
    html_content = graph.generate_html(notebook=False)

    # HTML dosyasını kaydet
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(html_content)

    print(f"Grafik görselleştirmesi oluşturuldu: {output_file}")

    # Tarayıcıda aç
    webbrowser.open(output_file)


# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyasının yolunu buraya yazın
    data = read_excel_data(excel_file)

    # Grafı oluştur ve yazarları al
    graph, author_papers = create_graph(data)

    # Düğüm stilini güncelle
    update_node_styles(graph, author_papers)

    # Grafi görselleştir ve tarayıcıda aç
    visualize_graph(graph)


if __name__ == "__main__":
    main()
