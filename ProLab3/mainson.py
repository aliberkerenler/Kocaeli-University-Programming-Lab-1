import pandas as pd
from pyvis.network import Network
from collections import defaultdict
import webbrowser


# Excel'den veri okuma
def read_excel_data(file_path):
    df = pd.read_excel(file_path)
    return df[['paper_title', 'coauthors']]


# Graf oluşturma
def create_graph(data):
    graph = Network(
        height="1000px", width="100%", bgcolor="#ffffff", font_color="#333333", notebook=False
    )

    author_papers = defaultdict(list)
    coauthorship = defaultdict(int)

    # Veriyi düğümler ve kenarlara ayırma
    for _, row in data.iterrows():
        title = row['paper_title']
        coauthors = [author.strip() for author in row['coauthors'].split(',')]

        for author in coauthors:
            author_papers[author].append(title)

        for i in range(len(coauthors)):
            for j in range(i + 1, len(coauthors)):
                pair = tuple(sorted([coauthors[i], coauthors[j]]))
                coauthorship[pair] += 1

    # Düğümleri ekleme
    for author, papers in author_papers.items():
        graph.add_node(
            author,
            label=author,
            title=f"<b>{author}</b><br>Makaleler:<br>" + "<br>".join(papers),
            value=len(papers),
            color="#6DAEDB",  # Düğüm rengi
        )

    # Kenarları ekleme
    for (author1, author2), weight in coauthorship.items():
        graph.add_edge(author1, author2, value=weight, width=1, color="rgba(150,150,150,0.5)")

    return graph



def configure_graph(graph):
    graph.set_options("""
       {
           "physics": {
               "enabled": true,
               "barnesHut": {
                   "gravitationalConstant": -100000,   
                   "centralGravity": 0.00001,         
                   "springLength": 6000,             
                   "springConstant": 0.01,        
                   "damping": 0.1                   
               },
               "minVelocity": 0.75,
               "solver": "barnesHut"
           },
           "interaction": {
               "dragNodes": true,
               "hideEdgesOnDrag": false,
               "zoomView": true
           },
           "edges": {
               "smooth": {
                   "type": "continuous"
               },
               "width": 2,                         
               "color": {
                   "inherit": false
               },
               "length": 200                         
           },
           "nodes": {
               "shape": "dot",                     
               "scaling": {
                   "min": 10,
                   "max": 100                     
               },
               "font": {
                   "size": 16,
                   "color": "#333333"
               },
               "color": {
                   "background": "#6DAEDB",
                   "border": "#333333"
               }
           }
       }
       """)


# Grafi tarayıcıda açma
def visualize_graph(graph, output_file="graph_visualization.html"):
    graph.show(output_file,notebook=False)
    print(f"Grafik görselleştirmesi oluşturuldu: {output_file}")
    webbrowser.open(output_file)

def print_graph_statistics(graph):
    total_nodes = len(graph.nodes)
    total_edges = len(graph.edges)
    print(f"Toplam Node Sayısı: {total_nodes}")
    print(f"Toplam Edge Sayısı: {total_edges}")

# Ana işlem
def main():
    excel_file = "dataset.xlsx"  # Excel dosyasının yolu
    data = read_excel_data(excel_file)

    # Grafı oluştur ve yapılandır
    graph = create_graph(data)
    configure_graph(graph)

    # Görselleştir ve aç
    visualize_graph(graph)

    print_graph_statistics(graph)


if __name__ == "__main__":
    main()
