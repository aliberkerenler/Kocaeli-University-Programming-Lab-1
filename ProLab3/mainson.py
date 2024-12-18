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

# Graf oluşturma
def create_graph(data):
    graph = Network(height="800px", width="100%", bgcolor="#222222", font_color="white")
    added_nodes = set()  # Benzersiz düğümleri kontrol etmek için

    # Ana yazarları ve ilişkilerini işleme
    for _, row in data.iterrows():
        author = row['author_name'].strip()
        orcid = row['orcid']
        paper_title = row['paper_title']
        doi = row['doi']
        position = row['author_position']

        try:
            # coauthors sütununu Python listesine dönüştür
            coauthors = ast.literal_eval(row['coauthors'])
        except (ValueError, SyntaxError):
            # Düzgün parse edilemezse boş liste olarak ele al
            coauthors = []

        coauthors = [coauthor.strip() for coauthor in coauthors]

        # Ana yazarı coauthors listesinden kaldır
        if 1 <= position <= len(coauthors):  # Pozisyonun geçerli olduğundan emin ol
            position -= 1  # 1 tabanlıyı 0 tabanlı hale getir
            main_author_in_coauthors = coauthors[position]
            coauthors.remove(main_author_in_coauthors)

        # Ana düğümü ekleme
        node_id = f"{author}-{orcid}"
        if node_id not in added_nodes:
            graph.add_node(
                node_id,
                label=author,
                title=f"""
                    <b>Yazar:</b> {author} <br>
                    <b>ORCID:</b> {orcid} <br>
                    <b>Makale Başlığı:</b> {paper_title} <br>
                    <b>DOI:</b> {doi}
                """,
                value=1,
                color="orange"
            )
            added_nodes.add(node_id)

        # Yardımcı düğümleri ekleme ve kenar oluşturma
        for coauthor in coauthors:
            if not coauthor:
                continue
            coauthor_id = f"{coauthor}"
            if coauthor_id not in added_nodes:
                graph.add_node(
                    coauthor_id,
                    label=coauthor,
                    title=f"Yardımcı Yazar: {coauthor}",
                    value=1,
                    color="lightblue"
                )
                added_nodes.add(coauthor_id)

            # Kenar ekleme (ana yazar -> yardımcı yazar)
            graph.add_edge(
                node_id,
                coauthor_id,
                title=f"Makale: {paper_title} <br> DOI: {doi}",
                color="gray"
            )
    return graph

# Graf görselleştirme
def visualize_graph(graph, output_file="graph_visualization.html"):
    graph.toggle_physics(True)
    graph.show(output_file, notebook=False)

# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyanızın yolu
    data = read_excel_data(excel_file)
    graph = create_graph(data)
    visualize_graph(graph)

if __name__ == "__main__":
    main()
