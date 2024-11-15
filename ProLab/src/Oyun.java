import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Oyun {

    public static void main(String[] args) {

        //Kartları olusturma
        List<SavasAraci> tumKartlar = new ArrayList<>();

        //Hava Araclari
        tumKartlar.add(new Ucak(20,0,"Hava",10,10,"Ucak"));
        tumKartlar.add(new Siha(15,0,"Hava",10,10,10,"Siha"));

        //Kara Araclari
        tumKartlar.add(new Obus(20,0,"Kara",10,5,"Obus"));
        tumKartlar.add(new KFS(10,0,"Kara",10,10,20,"KFS"));

        //Deniz Araclari
        tumKartlar.add(new Firkateyn(25,0,"Deniz",10,5,"Firkateyn"));
        tumKartlar.add(new Sida(15,0,"Deniz",10,10,10,"Sida"));



        // Kartları rastgele dağıt
        List<SavasAraci> oyuncuKartlari = kartDagit(tumKartlar);
        List<SavasAraci> bilgisayarKartlari = kartDagit(tumKartlar);

        // Oyuncu ve Bilgisayar Nesnelerini Oluştur
        Oyuncu oyuncu = new Oyuncu(1, "Kullanici", 0, oyuncuKartlari);
        Oyuncu bilgisayar = new Oyuncu(2, "Bilgisayar", 0, bilgisayarKartlari);

        // Kartları yazdır
        System.out.println("Oyuncu Kartları:");
        yazdirKartlar(oyuncuKartlari);

        System.out.println("\nBilgisayar Kartları:");
        yazdirKartlar(bilgisayarKartlari);

        // Bilgisayarın kart seçmesi
        kartSec(bilgisayarKartlari, true);

        // Oyuncunun kart seçmesi
        kartSec(oyuncuKartlari, false);

        // Skorları göster
        System.out.println("\nOyuncunun Skoru: " + oyuncu.getSkor());
        System.out.println("Bilgisayarın Skoru: " + bilgisayar.getSkor());
    }

    // Kartları rastgele dağıtan fonksiyon
    public static List<SavasAraci> kartDagit(List<SavasAraci> tumKartlar) {
        List<SavasAraci> kartlar = new ArrayList<>();
        Random rand = new Random();

        // 6 kart dağıtılacak
        for (int i = 0; i < 6; i++) {
            // Rastgele bir kart seç
            SavasAraci secilenKart = tumKartlar.get(rand.nextInt(tumKartlar.size()));
            kartlar.add(secilenKart);
        }
        return kartlar;
    }

    // Kartları yazdıran fonksiyon
    public static void yazdirKartlar(List<SavasAraci> kartlar) {
        // Kart türlerine göre sayaçları başlat
        Map<String, Integer> kartSayilari = new HashMap<>();

        // Kart türlerine göre sayıları arttırarak yazdır
        for (SavasAraci kart : kartlar) {
            String kartTuru = kart.getClass().getSimpleName(); // Kartın türünü al

            // Kart türüne göre sayıyı arttır
            kartSayilari.put(kartTuru, kartSayilari.getOrDefault(kartTuru, 0) + 1);

            // Kart türü + sayısı yazdır
            System.out.println(kartTuru + " " + kartSayilari.get(kartTuru));
        }
    }

    // Bilgisayar ve Kullanıcı kart seçimi
    public static void kartSec(List<SavasAraci> kartlar, boolean bilgisayar) {
        List<SavasAraci> secilenKartlar = new ArrayList<>(); // Seçilen kartları tutacak liste
        List<SavasAraci> secilecekKartlar = new ArrayList<>(kartlar); // Tüm kartların bir kopyasını alıyoruz

        // Bilgisayar için rastgele kart seçme
        if (bilgisayar) {
            Random rand = new Random();
            for (int i = 0; i < 3; i++) {
                int index = rand.nextInt(secilecekKartlar.size());
                secilenKartlar.add(secilecekKartlar.get(index));
                secilecekKartlar.remove(index); // Seçilen kartı listeden çıkar
            }

            System.out.println("Bilgisayarın Seçtiği Kartlar:");
            for (SavasAraci kart : secilenKartlar) {
                System.out.println("Bilgisayar " + kart.getClass().getSimpleName() + " kartını seçti.");
            }
        }
        // Kullanıcı için kart seçme
        else {
            List<String> secilenKartlarStr = new ArrayList<>(); // Kullanıcı tarafından seçilen kartları tutacak liste

            while (secilenKartlarStr.size() < 3) {
                System.out.println("Kullanici Kart Seçin:");
                Map<String, Integer> kartNumaralari = new HashMap<>();
                for (int i = 0; i < secilecekKartlar.size(); i++) {
                    SavasAraci kart = secilecekKartlar.get(i);
                    String kartTuru = kart.getClass().getSimpleName();
                    kartNumaralari.put(kartTuru, kartNumaralari.getOrDefault(kartTuru, 0) + 1);
                    System.out.println((i + 1) + ". " + kartTuru + " " + kartNumaralari.get(kartTuru)); // Kart türü ve numara
                }

                // Kullanıcıdan seçim almak
                Scanner scanner = new Scanner(System.in);
                int secim = scanner.nextInt() - 1; // Kullanıcıdan gelen seçim

                SavasAraci secilenKart = secilecekKartlar.get(secim);
                secilenKartlarStr.add(secilenKart.getClass().getSimpleName()); // Seçilen kartı listeye ekle
                secilecekKartlar.remove(secim); // Seçilen kartı listeden çıkar

                System.out.println("Kullanıcı " + secilenKart.getClass().getSimpleName() + " kartını seçti.");
            }
        }
    }
}


