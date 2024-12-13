package com.example.prolab3;

import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.io.OutputStream;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.InetSocketAddress;

public class SimpleHttpServer {

    public static void main(String[] args) throws Exception {
        // HTTP Server başlatılıyor
        HttpServer server = HttpServer.create(new InetSocketAddress(8080), 0); // Port 8080 üzerinden çalışacak
        server.createContext("/", new HttpHandler() {
            @Override
            public void handle(HttpExchange exchange) throws IOException {
                // HTML dosyasını okuma
                String htmlResponse = getHTMLResponse();

                // HTTP cevabını gönderme
                exchange.sendResponseHeaders(200, htmlResponse.getBytes().length); // HTTP 200 OK
                OutputStream os = exchange.getResponseBody();
                os.write(htmlResponse.getBytes());
                os.close();
            }
        });
        server.start(); // Server başlatılıyor
        System.out.println("Server başlatıldı. http://localhost:8080 adresini ziyaret edin.");
    }

    // HTML içeriğini döndüren metot
    private static String getHTMLResponse() {
        return "<html><body>" +
                "<h1>Yazarlar Arası İş Birliği Grafiği</h1>" +
                "<canvas id='collaborationChart' width='400' height='400'></canvas>" +
                "<script src='https://cdn.jsdelivr.net/npm/chart.js'></script>" +
                "<script>" +
                "   const data = [{" +
                "       'title': 'Makale 1'," +
                "       'coAuthors': 'Yazar A, Yazar B'," +
                "       'doi': '10.1234/abcd'" +
                "   }, {" +
                "       'title': 'Makale 2'," +
                "       'coAuthors': 'Yazar A, Yazar C'," +
                "       'doi': '10.5678/efgh'" +
                "   }];" +
                "   const authorCollaborations = {};" +
                "   data.forEach(item => {" +
                "       const authors = item.coAuthors.split(', ');" +
                "       authors.forEach(author => {" +
                "           if (!authorCollaborations[author]) {" +
                "               authorCollaborations[author] = 0;" +
                "           }" +
                "           authorCollaborations[author] += 1;" +
                "       });" +
                "   });" +
                "   const labels = Object.keys(authorCollaborations);" +
                "   const collaborationCounts = Object.values(authorCollaborations);" +
                "   const ctx = document.getElementById('collaborationChart').getContext('2d');" +
                "   const collaborationChart = new Chart(ctx, {" +
                "       type: 'bar'," +
                "       data: {" +
                "           labels: labels," +
                "           datasets: [{" +
                "               label: 'Yazarlar Arası İş Birliği Sayısı'," +
                "               data: collaborationCounts," +
                "               backgroundColor: 'rgba(54, 162, 235, 0.2)'," +
                "               borderColor: 'rgba(54, 162, 235, 1)'," +
                "               borderWidth: 1" +
                "           }]" +
                "       }," +
                "       options: {" +
                "           scales: {" +
                "               y: {" +
                "                   beginAtZero: true" +
                "               }" +
                "           }" +
                "       }" +
                "   });" +
                "</script>" +
                "</body></html>";
    }
}

