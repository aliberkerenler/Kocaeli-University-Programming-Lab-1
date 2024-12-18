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
    edges = []  # Kenarları (source, target) çiftleri olarak saklayacağız.

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
                "color": "orange"
            }

        # Yardımcı yazar düğümleri ve kenarları ekleme
        for coauthor in coauthors:
            if not coauthor:  # Boş yazar ismini atla
                continue
            coauthor_id = coauthor
            if coauthor_id not in nodes:
                nodes[coauthor_id] = {
                    "label": coauthor,
                    "orcid": "N/A",
                    "paper_title": "N/A",
                    "doi": "N/A",
                    "color": "lightblue"
                }
            # Ana yazar ile yardımcı yazar arasında kenar ekleme
            edges.append((node_id, coauthor_id))

    return nodes, edges


# Pyvis kullanarak grafı görselleştirme
def visualize_graph(nodes, edges, output_file="manual_graph_visualization.html"):
    graph = Network(height="800px", width="100%", bgcolor="#222222", font_color="white")

    # Düğümleri ekleme
    for node_id, node_data in nodes.items():
        graph.add_node(
            node_id,
            label=node_data['label'],
            title=f"""
                <b>Yazar:</b> {node_data['label']}<br>
                <b>ORCID:</b> {node_data['orcid']}<br>
                <b>Makale Başlığı:</b> {node_data['paper_title']}<br>
                <b>DOI:</b> {node_data['doi']}
            """,
            color=node_data['color']
        )

    # Kenarları ekleme
    for source, target in edges:
        graph.add_edge(source, target, color="gray")

    # Grafı görselleştir
    graph.toggle_physics(True)
    graph.show(output_file, notebook=False)


# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyasının yolu
    data = read_excel_data(excel_file)
    nodes, edges = create_manual_graph(data)
    visualize_graph(nodes, edges)


if __name__ == "__main__":
    main()
