import java.util.ArrayList;
import java.util.List;
import java.util.Random;

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



        List<SavasAraci> oyuncuKartlari = kartDagit(tumKartlar);
        List<SavasAraci> bilgisayarKartlari = kartDagit(tumKartlar);

        // Dağıtılan kartları ekrana yazdıralım
        System.out.println("Oyuncu Kartları:");
        yazdirKartlar(oyuncuKartlari);

        System.out.println("\nBilgisayar Kartları:");
        yazdirKartlar(bilgisayarKartlari);
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

    // Kartları yazdıran fonksiyon (Kartları sıralı olarak yazdıracak)
    public static void yazdirKartlar(List<SavasAraci> kartlar) {
        // Kart türlerine göre sayılar ekleyelim
        int ucakSayisi = 1, sihaSayisi = 1, obusSayisi = 1, kfsSayisi = 1, firkateynSayisi = 1, sidaSayisi = 1;

        for (SavasAraci kart : kartlar) {
            if (kart instanceof Ucak) {
                System.out.println("Ucak" + ucakSayisi++);
            } else if (kart instanceof Siha) {
                System.out.println("Siha" + sihaSayisi++);
            } else if (kart instanceof Obus) {
                System.out.println("Obus" + obusSayisi++);
            } else if (kart instanceof KFS) {
                System.out.println("KFS" + kfsSayisi++);
            } else if (kart instanceof Firkateyn) {
                System.out.println("Firkateyn" + firkateynSayisi++);
            } else if (kart instanceof Sida) {
                System.out.println("Sida" + sidaSayisi++);
            }
        }
    }
}


