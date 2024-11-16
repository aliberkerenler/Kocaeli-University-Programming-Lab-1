import java.util.ArrayList;
import java.util.List;
import java.util.Random;
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

        // Dağıtılan kartları yazdırma
        System.out.println("Oyuncu Kartları:");
        yazdirKartlar(oyuncuKartlari);

        System.out.println("\nBilgisayar Kartları:");
        yazdirKartlar(bilgisayarKartlari);

        // Bilgisayarın Kart Seçmesi

        bilgisayarKartSec(bilgisayar);

        // Kullanıcının Kart Seçmesi

        kullaniciKartSec(oyuncu);
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

    // Bilgisayarın kart seçmesi
    public static void bilgisayarKartSec(Oyuncu bilgisayar) {
        List<SavasAraci> kartlar = new ArrayList<>(bilgisayar.getKartListesi());
        List<SavasAraci> secilenKartlar = new ArrayList<>(); // Seçilen kartları tutmak için liste

        for (int i = 0; i < 3; i++) {
            Random rand = new Random();
            SavasAraci secilenKart = kartlar.get(rand.nextInt(kartlar.size()));
            kartlar.remove(secilenKart);  // Kartı seçtikten sonra listeden çıkar

            // Seçilen kartı listeye ekle
            secilenKartlar.add(secilenKart);

        }

        // Seçilen kartları yazdır
        System.out.println("\nBilgisayarın Seçtiği Kartlar:");
        for (SavasAraci kart : secilenKartlar) {
            System.out.println("- " + kart.getClass().getSimpleName());
        }
        System.out.println("");
    }

    // Kullanıcının kart seçmesi
    public static void kullaniciKartSec(Oyuncu oyuncu) {
        List<SavasAraci> kartlar = new ArrayList<>(oyuncu.getKartListesi());
        List<SavasAraci> secilenKartlar = new ArrayList<>(); // Seçilen kartları tutmak için liste

        for (int i = 0; i < 3; i++) {
            // Kartları yazdır
            System.out.println("Kullanıcı Kart Seçin:");
            for (int j = 0; j < kartlar.size(); j++) {
                System.out.println((j + 1) + ". " + kartlar.get(j).getClass().getSimpleName());
            }

            // Kullanıcının kart seçmesi
            Scanner scanner = new Scanner(System.in);
            System.out.print("Bir kart seçin (1-" + kartlar.size() + " arasında bir numara girin): ");
            int secim = scanner.nextInt();
            secim = secim - 1;  // Index 0'dan başladığı için bir azaltıyoruz

            // Seçilen kartı yazdır
            SavasAraci secilenKart = kartlar.get(secim);
            System.out.println("Kullanıcı " + secilenKart.getClass().getSimpleName() + " kartını seçti.");

            // Seçilen kartı listeye ekle
            secilenKartlar.add(secilenKart);

            // Kartı listeden çıkarma
            kartlar.remove(secim);
        }

        // Seçilen kartları yazdır
        System.out.println("\nKullanıcının Seçtiği Kartlar:");
        for (SavasAraci kart : secilenKartlar) {
            System.out.println("- " + kart.getClass().getSimpleName());
        }
    }


    // Kartları yazdıran fonksiyon
    public static void yazdirKartlar(List<SavasAraci> kartlar) {
        for (int i = 0; i < kartlar.size(); i++) {
            SavasAraci kart = kartlar.get(i);
            System.out.println((i + 1) + ". " + kart.getClass().getSimpleName());
        }
    }




}


