import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Oyun {

    public static void main(String[] args) {
        // Kartları oluşturma
        List<SavasAraci> oyuncuKartlar = new ArrayList<>();
        List<SavasAraci> bilgisayarKartlar = new ArrayList<>();
        List<SavasAraci> kilitliKartlar = new ArrayList<>(); // Yeni kartlar burada saklanacak
        int oyuncuKontrol = 0, bilgisayarKontrol = 0;

        // Hava Araçları
        oyuncuKartlar.add(new Ucak(20, 0, "Hava", 10, 10, "Ucak"));
        bilgisayarKartlar.add(new Ucak(20, 0, "Hava", 10, 10, "Ucak"));
        kilitliKartlar.add(new Siha(15, 0, "Hava", 10, 10, 10, "Siha"));

        // Kara Araçları
        oyuncuKartlar.add(new Obus(20, 0, "Kara", 10, 5, "Obus"));
        bilgisayarKartlar.add(new Obus(20, 0, "Kara", 10, 5, "Obus"));
        kilitliKartlar.add(new KFS(10, 0, "Kara", 10, 10, 20, "KFS"));

        // Deniz Araçları
        oyuncuKartlar.add(new Firkateyn(25, 0, "Deniz", 10, 5, "Firkateyn"));
        bilgisayarKartlar.add(new Firkateyn(25, 0, "Deniz", 10, 5, "Firkateyn"));
        kilitliKartlar.add(new Sida(15, 0, "Deniz", 10, 10, 10, "Sida"));

        // Kartları rastgele dağıt
        List<SavasAraci> oyuncuKartlari = kartDagit(oyuncuKartlar);
        List<SavasAraci> bilgisayarKartlari = kartDagit(bilgisayarKartlar);

        // Oyuncu ve Bilgisayar Nesnelerini Oluştur
        Oyuncu oyuncu = new Oyuncu(1, "Kullanici", 0, oyuncuKartlari);
        Oyuncu bilgisayar = new Oyuncu(2, "Bilgisayar", 0, bilgisayarKartlari);

        // Oyuncu ve Bilgisayar Kartlarını Yazdır
        System.out.println("Oyuncu Kartları:");
        yazdirKartlar(oyuncuKartlari);

        System.out.println("\nBilgisayar Kartları:");
        yazdirKartlar(bilgisayarKartlari);

        // Oyun Döngüsü
        while (true) {
            // Bilgisayarın Kart Seçmesi
            List<SavasAraci> bilgisayarSecilenKartlar = bilgisayarKartSec(bilgisayar);

            // Kullanıcının Kart Seçmesi
            List<SavasAraci> oyuncuSecilenKartlar = kullaniciKartSec(oyuncu);

            // Kart Karşılaştırması
            System.out.println("\n--- Kart Karşılaştırma Başlıyor ---");
            kartKarsilastir(oyuncuSecilenKartlar, bilgisayarSecilenKartlar, oyuncu, bilgisayar);

            // Kilitli Kartları Açma Kontrolü
            if (oyuncu.getSkor() == 20 && oyuncuKontrol == 0) {
                oyuncuKontrol = 1;
                oyuncuKartlar.addAll(kilitliKartlar); // Kilitli kartları oyuna dahil et
                System.out.println("\nYeni Kartlar Açıldı! Artık Siha, KFS ve Sida oyuncu tarafından kullanılabilir.");
            }
            if (bilgisayar.getSkor() == 20 && bilgisayarKontrol == 0) {
                bilgisayarKontrol = 1;
                bilgisayarKartlar.addAll(kilitliKartlar); // Kilitli kartları oyuna dahil et
                System.out.println("\nYeni Kartlar Açıldı! Artık Siha, KFS ve Sida bilgisayar tarafından kullanılabilir.");
            }
            if (oyuncuKontrol == 1 && bilgisayarKontrol == 1){
                kilitliKartlar.clear(); // Kilitli kart listesini temizle
            }

            // Skorları Yazdır
            System.out.println("\nSon Skorlar:");
            System.out.println("Oyuncu Skoru: " + oyuncu.getSkor());
            System.out.println("Bilgisayar Skoru: " + bilgisayar.getSkor());

            // Oyunu Bitirme Kontrolü
            if (oyuncu.getSkor() >= 50 || bilgisayar.getSkor() >= 50) {
                System.out.println("\nOyun Bitti!");
                if (oyuncu.getSkor() > bilgisayar.getSkor()) {
                    System.out.println("Kazanan: Oyuncu");
                } else {
                    System.out.println("Kazanan: Bilgisayar");
                }
                break;
            }
        }
    }

    // Kartları rastgele dağıtan fonksiyon
    public static List<SavasAraci> kartDagit(List<SavasAraci> tumKartlar) {
        List<SavasAraci> kartlar = new ArrayList<>();
        Random rand = new Random();

        // 6 kart dağıtılacak
        for (int i = 0; i < 6; i++) {
            SavasAraci secilenKart = tumKartlar.get(rand.nextInt(tumKartlar.size())).clone();
            kartlar.add(secilenKart);
        }
        return kartlar;
    }

    // Bilgisayarın kart seçmesi
    public static List<SavasAraci> bilgisayarKartSec(Oyuncu bilgisayar) {
        List<SavasAraci> kartlar = new ArrayList<>(bilgisayar.getKartListesi());
        List<SavasAraci> secilenKartlar = new ArrayList<>();
        List<SavasAraci> aktifKartlar = new ArrayList<>();

        // Dayanıklılığı 0 olmayan kartları aktifKartlar listesine ekle
        for (SavasAraci kart : kartlar) {
            if (kart.getDayaniklilik() > 0) {
                aktifKartlar.add(kart);
            }
        }
        for (int i = 0; i < 3; i++) {
            Random rand = new Random();
            SavasAraci secilenKart = aktifKartlar.get(rand.nextInt(kartlar.size()));
            kartlar.remove(secilenKart); // Kartı seçtikten sonra listeden çıkar
            aktifKartlar.remove(secilenKart);
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
        List<SavasAraci> aktifKartlar = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Dayanıklılığı 0 olmayan kartları aktifKartlar listesine ekle
        for (SavasAraci kart : kartlar) {
            if (kart.getDayaniklilik() > 0) {
                aktifKartlar.add(kart);
            }
        }
        for (int i = 0; i < 3; i++) {
            System.out.println("\nKullanıcı Kart Seçin:");
            yazdirKartlar(aktifKartlar);

            System.out.print("Bir kart seçin (1-" + aktifKartlar.size() + "): ");
            int secim = scanner.nextInt() - 1; // Index 0'dan başladığı için bir azaltıyoruz
            SavasAraci secilenKart = aktifKartlar.get(secim);
            secilenKartlar.add(secilenKart);
            kartlar.remove(secilenKart);
            aktifKartlar.remove(secilenKart);
        }

        System.out.println("\nKullanıcının Seçtiği Kartlar:");
        yazdirKartlar(secilenKartlar);
        return secilenKartlar;
    }

    // Kartları yazdıran fonksiyon
    public static void yazdirKartlar(List<SavasAraci> kartlar) {
        for (int i = 0; i < kartlar.size(); i++) {
            SavasAraci kart = kartlar.get(i);
            System.out.println((i + 1) + ". " + kart.getClass().getSimpleName());
        }
    }

    public static void kartKarsilastir(List<SavasAraci> oyuncuKartlari, List<SavasAraci> bilgisayarKartlari, Oyuncu oyuncu, Oyuncu bilgisayar) {
        for (int i = oyuncuKartlari.size() - 1; i >= 0; i--) {
            SavasAraci oyuncuKart = oyuncuKartlari.get(i);
            SavasAraci bilgisayarKart = bilgisayarKartlari.get(i);

            System.out.println("\nSavaş Başlıyor:");
            System.out.println("Oyuncunun Kartı: " + oyuncuKart.getClass().getSimpleName());
            System.out.println("Bilgisayarın Kartı: " + bilgisayarKart.getClass().getSimpleName());

            // Saldırı avantajlarını hesapla
            int oyuncuSaldiri = oyuncuKart.getVurus();
            int bilgisayarSaldiri = bilgisayarKart.getVurus();

            if (oyuncuKart instanceof KaraAraci && bilgisayarKart instanceof DenizAraci) {
                oyuncuSaldiri += ((KaraAraci) oyuncuKart).getDenizVurusAvantaji();
            } else if (oyuncuKart instanceof DenizAraci && bilgisayarKart instanceof HavaAraci) {
                oyuncuSaldiri += ((DenizAraci) oyuncuKart).getHavaVurusAvantaji();
            } else if (oyuncuKart instanceof HavaAraci && bilgisayarKart instanceof KaraAraci) {
                oyuncuSaldiri += ((HavaAraci) oyuncuKart).getKaraVurusAvantaji();
            }

            if (bilgisayarKart instanceof KaraAraci && oyuncuKart instanceof DenizAraci) {
                bilgisayarSaldiri += ((KaraAraci) bilgisayarKart).getDenizVurusAvantaji();
            } else if (bilgisayarKart instanceof DenizAraci && oyuncuKart instanceof HavaAraci) {
                bilgisayarSaldiri += ((DenizAraci) bilgisayarKart).getHavaVurusAvantaji();
            } else if (bilgisayarKart instanceof HavaAraci && oyuncuKart instanceof KaraAraci) {
                bilgisayarSaldiri += ((HavaAraci) bilgisayarKart).getKaraVurusAvantaji();
            }

            // Dayanıklılığı güncelle
            oyuncuKart.setDayaniklilik(oyuncuKart.getDayaniklilik() - bilgisayarSaldiri);
            bilgisayarKart.setDayaniklilik(bilgisayarKart.getDayaniklilik() - oyuncuSaldiri);

            // Kartları kontrol et
            if (bilgisayarKart.getDayaniklilik() <= 0) {
                bilgisayarKart.setDayaniklilik(0); // Negatif değer sıfıra sabitlenir
                oyuncu.setSkor(oyuncu.getSkor() + bilgisayarKart.getSeviyePuani() + 10);
                System.out.println("Bilgisayarın " + bilgisayarKart.getClass().getSimpleName() + " kartı elendi!");
                bilgisayarKartlari.remove(i);

            } else {
                System.out.println("Bilgisayarın " + bilgisayarKart.getClass().getSimpleName() + " dayanıklılık: " + bilgisayarKart.getDayaniklilik());
            }

            if (oyuncuKart.getDayaniklilik() <= 0) {
                oyuncuKart.setDayaniklilik(0); // Negatif değer sıfıra sabitlenir
                bilgisayar.setSkor(bilgisayar.getSkor() + oyuncuKart.getSeviyePuani() + 10);
                System.out.println("Oyuncunun " + oyuncuKart.getClass().getSimpleName() + " kartı elendi!");
                oyuncuKartlari.remove(i);
            } else {
                System.out.println("Oyuncunun " + oyuncuKart.getClass().getSimpleName() + " dayanıklılık: " + oyuncuKart.getDayaniklilik());
            }
        }
    }
}
