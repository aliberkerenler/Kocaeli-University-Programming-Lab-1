module com.example.prolab3 {
    requires javafx.controls;
    requires javafx.fxml;
    requires org.apache.poi.poi;  // Apache POI modülünü ekleyin
    requires org.apache.poi.ooxml;  // Apache POI OOXML modülünü ekleyin
    requires org.apache.xmlbeans;  // Apache POI XMLBeans modülünü ekleyin
    requires jdk.httpserver;  // HTTP Server için bu satırı ekleyin

    opens com.example.prolab3 to javafx.fxml;
    exports com.example.prolab3;
}
