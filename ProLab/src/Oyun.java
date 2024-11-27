import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Oyun {

    public static void main(String[] args) {
        // Kartları oluşturma
        List<SavasAraci> tumKartlar = new ArrayList<>();
        List<SavasAraci> kilitliKartlar = new ArrayList<>(); // Yeni kartlar burada saklanacak

        // Hava Araçları
        tumKartlar.add(new Ucak(20, 0, "Hava", 10, 10, "Ucak"));
        kilitliKartlar.add(new Siha(15, 0, "Hava", 10, 10, 10, "Siha"));

        // Kara Araçları
        tumKartlar.add(new Obus(20, 0, "Kara", 10, 5, "Obus"));
        kilitliKartlar.add(new KFS(10, 0, "Kara", 10, 10, 20, "KFS"));

        // Deniz Araçları
        tumKartlar.add(new Firkateyn(25, 0, "Deniz", 10, 5, "Firkateyn"));
        kilitliKartlar.add(new Sida(15, 0, "Deniz", 10, 10, 10, "Sida"));

        // Kartları rastgele dağıt
        List<SavasAraci> oyuncuKartlari = kartDagit(tumKartlar);
        List<SavasAraci> bilgisayarKartlari = kartDagit(tumKartlar);

        // Oyuncu ve Bilgisayar Nesnelerini Oluştur
        Oyuncu oyuncu = new Oyuncu(1, "Kullanici", 0, oyuncuKartlari);
        Oyuncu bilgisayar = new Oyuncu(2, "Bilgisayar", 0, bilgisayarKartlari);

        // Oyuncu ve Bilgisayar Kartlarını Yazdır
        System.out.println("Oyuncu Kartları:");
        yazdirKartlar(oyuncuKartlari);

        System.out.println("\nBilgisayar Kartları:");
        yazdirKartlar(bilgisayarKartlari);

        // Bilgisayarın kart seçmesi
        List<SavasAraci> bilgisayarSecilenKartlar = bilgisayarKartSec(bilgisayar);

        // Kullanıcının kart seçmesi
        List<SavasAraci> oyuncuSecilenKartlar = kullaniciKartSec(oyuncu);

        // Kartları karşılaştırma (savaş)
        kartKarsilastir(oyuncuSecilenKartlar, bilgisayarSecilenKartlar);
    }

    // Kartları rastgele dağıtan fonksiyon
    public static List<SavasAraci> kartDagit(List<SavasAraci> tumKartlar) {
        List<SavasAraci> kartlar = new ArrayList<>();
        Random rand = new Random();

        // 6 kart dağıtılacak
        for (int i = 0; i < 6; i++) {
            SavasAraci secilenKart = tumKartlar.get(rand.nextInt(tumKartlar.size()));
            kartlar.add(secilenKart);
        }
        return kartlar;
    }

    // Bilgisayarın kart seçmesi
    public static List<SavasAraci> bilgisayarKartSec(Oyuncu bilgisayar) {
        List<SavasAraci> kartlar = new ArrayList<>(bilgisayar.getKartListesi());
        List<SavasAraci> secilenKartlar = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            Random rand = new Random();
            SavasAraci secilenKart = kartlar.get(rand.nextInt(kartlar.size()));
            kartlar.remove(secilenKart); // Kartı seçtikten sonra listeden çıkar
            secilenKartlar.add(secilenKart);
        }

        System.out.println("\nBilgisayarın Seçtiği Kartlar:");
        yazdirKartlar(secilenKartlar);
        return secilenKartlar;
    }

    // Kullanıcının kart seçmesi
    public static List<SavasAraci> kullaniciKartSec(Oyuncu oyuncu) {
        List<SavasAraci> kartlar = new ArrayList<>(oyuncu.getKartListesi());
        List<SavasAraci> secilenKartlar = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            System.out.println("\nKullanıcı Kart Seçin:");
            yazdirKartlar(kartlar);

            System.out.print("Bir kart seçin (1-" + kartlar.size() + "): ");
            int secim = scanner.nextInt() - 1; // Index 0'dan başladığı için bir azaltıyoruz
            SavasAraci secilenKart = kartlar.get(secim);
            secilenKartlar.add(secilenKart);
            kartlar.remove(secilenKart);
        }

        System.out.println("\nKullanıcının Seçtiği Kartlar:");
        yazdirKartlar(secilenKartlar);
        return secilenKartlar;
    }

    // Kartları yazdıran fonksiyon
    public static void yazdirKartlar(List<SavasAraci> kartlar) {
        for (int i = 0; i < kartlar.size(); i++) {
            SavasAraci kart = kartlar.get(i);
            System.out.println((i + 1) + ". " + kart.getClass().getSimpleName() + " | Dayanıklılık: " + kart.getDayaniklilik() + " | Vuruş: " + kart.getVurus());
        }
    }

    public static void kartKarsilastir(List<SavasAraci> oyuncuKartlari, List<SavasAraci> bilgisayarKartlari) {
        // Her iki oyuncunun kartlarını sırayla karşılaştırıyoruz
        for (int i = 0; i < oyuncuKartlari.size(); i++) {
            // Kartların başta orijinal değerlerini alıyoruz
            SavasAraci oyuncuKart = oyuncuKartlari.get(i);
            SavasAraci bilgisayarKart = bilgisayarKartlari.get(i);

            // Savaş başlatmadan önce her kartın orijinal değerlerini saklayalım
            int oyuncuDayaniklilik = oyuncuKart.getDayaniklilik();
            int bilgisayarDayaniklilik = bilgisayarKart.getDayaniklilik();

            // Her iki kartın savaşındaki değerlerini gösterelim
            System.out.println("\nSavaş Başlıyor:");
            System.out.println("Oyuncunun Kartı: " + oyuncuKart.getClass().getSimpleName() + " | Dayanıklılık: " + oyuncuDayaniklilik);
            System.out.println("Bilgisayarın Kartı: " + bilgisayarKart.getClass().getSimpleName() + " | Dayanıklılık: " + bilgisayarDayaniklilik);

            // Kartların savaşması (vurusu kadar dayanıklılık düşürülür)
            int oyuncuSaldiri = oyuncuKart.getVurus();
            int bilgisayarSaldiri = bilgisayarKart.getVurus();

            // Dayanıklılıkları geçici olarak güncelle
            oyuncuKart.DurumGuncelle(bilgisayarSaldiri); // Oyuncuya bilgisayarın vurduğu kadar zarar ver
            bilgisayarKart.DurumGuncelle(oyuncuSaldiri); // Bilgisayara oyuncunun vurduğu kadar zarar ver

            // Sonuçları yazdır
            System.out.println("Oyuncunun " + oyuncuKart.getClass().getSimpleName() + " Dayanıklılığı: " + oyuncuKart.getDayaniklilik());
            System.out.println("Bilgisayarın " + bilgisayarKart.getClass().getSimpleName() + " Dayanıklılığı: " + bilgisayarKart.getDayaniklilik());

            // Kartların savaş sonrası durumunu kontrol et
            if (oyuncuKart.getDayaniklilik() == 0) {
                System.out.println("Oyuncunun " + oyuncuKart.getClass().getSimpleName() + " kartı elendi!");
                oyuncuKartlari.remove(i); // Kart oyuncudan elenir
                i--; // Bir kart silindiği için i'yi geri alıyoruz
            }

            if (bilgisayarKart.getDayaniklilik() == 0) {
                System.out.println("Bilgisayarın " + bilgisayarKart.getClass().getSimpleName() + " kartı elendi!");
                bilgisayarKartlari.remove(i); // Kart bilgisayardan elenir
                i--; // Bir kart silindiği için i'yi geri alıyoruz
            }

            // Kartları eski hallerine döndür
            oyuncuKart.setDayaniklilik(oyuncuDayaniklilik); // Oyuncu kartını eski haline getir
            bilgisayarKart.setDayaniklilik(bilgisayarDayaniklilik); // Bilgisayar kartını eski haline getir
        }
    }

}



