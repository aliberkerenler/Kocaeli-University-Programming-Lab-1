#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int saldiri;
    int savunma;
    int saglik;
    int kritik_sans;
    int sayi;
} Unit;

typedef struct {
    Unit piyadeler;
    Unit okcular;
    Unit suvariler;
    Unit kusatma_makineleri;
} Human_Unit;

typedef struct {
    Unit ork_dovusculeri;
    Unit mizrakcilar;
    Unit varg_binicileri;
    Unit troller;
} Ork_Unit;

typedef struct {
    char bonus_turu[50];
    char etkiledigi_birim[50];
    int bonus_degeri;
    int sayi;
} Hero;

typedef struct {
    Hero alparslan;
    Hero fsm;
    Hero yss;
    Hero tugrul_bey;
} Human_Hero;

typedef struct {
    Hero goruk;
    Hero thruk;
    Hero vrog;
    Hero ugar;
} Ork_Hero;

typedef struct {
    int etki_degeri;
    char etki_turu[50];
    char etkiledigi_birim[256];
    int sayi;
} Creature;

typedef struct {
    Creature ejderha;
    Creature agri_dagi;
    Creature tepegoz;
    Creature karakurt;
    Creature samur;
} Human_Creature;

typedef struct {
    Creature troll;
    Creature golge;
    Creature camur;
    Creature ates_iblisi;
    Creature buz_devi;
} Ork_Creature;

typedef struct {
    int deger;
    char aciklama[100];
    int sayi;
} Seviye;

typedef struct {
    Seviye seviye_1;
    Seviye seviye_2;
    Seviye seviye_3;
} Research_Type;

typedef struct {
    Research_Type savunma_ustaligi;
    Research_Type saldiri_gelistirmesi;
    Research_Type elit_egitim;
    Research_Type kusatma_ustaligi;
} Research;

typedef struct {
    Research Human_Research;
    Research Ork_Research;
} Research_Side;

// Global değişkenler
Human_Unit HU;
Ork_Unit OU;
Human_Hero HH;
Ork_Hero OH;
Human_Creature HC;
Ork_Creature OC;
Research_Type RT;
Research R;
Research_Side RS;

// Fonksiyon prototipleri
void parse_unit_json(const char *filename, Human_Unit HU, Ork_Unit OU);
void parse_hero_json(const char *filename, Human_Hero HH, Ork_Hero OH);
void parse_creature_json(const char *filename, Human_Creature HC, Ork_Creature OC);
void parse_skill_json(const char *filename, Research R);
void parse_scenario_file(FILE *file, Human_Unit HU, Ork_Unit OU, Human_Hero HH, Ork_Hero OH, Human_Creature HC, Ork_Creature OC, Research_Side RS);

int main() {
    // JSON dosyalarını analiz etme
    parse_unit_json("unit_types.json", HU, OU);
    parse_hero_json("heroes.json", HH, OH);
    parse_creature_json("creatures.json", HC, OC);
    parse_skill_json("research.json", R);

    // Senaryo dosyasını açma ve analiz etme
    FILE *file = fopen("main_scenario_1.json", "r");
    parse_scenario_file(file, HU, OU, HH, OH, HC, OC, RS);

    // Burada, doldurulan verileri kullanarak işlemler yapabilirsin.
    // Örneğin, İnsan birimlerinin sayılarını yazdırma
    printf("İnsan Birimleri:\n");
    printf("Piyadeler: %d\n", HU.piyadeler.sayi);
    printf("Okçular: %d\n", HU.okcular.sayi);
    printf("Süvariler: %d\n", HU.suvariler.sayi);
    printf("Kuşatma Makineleri: %d\n", HU.kusatma_makineleri.sayi);
    

    // Ork birimlerinin sayılarını yazdırma
    printf("\nOrk Birimleri:\n");
    printf("Ork Dövüşçüleri: %d\n", OU.ork_dovusculeri.sayi);
    printf("Mızrakçılar: %d\n", OU.mizrakcilar.sayi);
    printf("Varg Binicileri: %d\n", OU.varg_binicileri.sayi);
    printf("Troller: %d\n", OU.troller.sayi);

    // Belleği temizle ve çık
    fclose(file);
    return 0;
}

void parse_creature_json(const char *filename, Human_Creature HC, Ork_Creature OC)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char etki_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Ejderha\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            HC.ejderha.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &HC.ejderha.etki_turu);
            
        }
        if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            HC.agri_dagi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &HC.agri_dagi.etki_turu);
            
        }
        if (strstr(line, "\"Tepegoz\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            HC.tepegoz.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &HC.tepegoz.etki_turu);
            ;
        }
        if (strstr(line, "\"Karakurt\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            HC.karakurt.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &HC.karakurt.etki_turu);
            
        }
        if (strstr(line, "\"Samur\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            HC.samur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &HC.samur.etki_turu);
            
        }
        if (strstr(line, "\"Kara_Troll\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            OC.troll.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &OC.troll.etki_turu);
            
        }
        if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            OC.golge.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &OC.golge.etki_turu);
            
        }
        if (strstr(line, "\"Camur_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            OC.camur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &OC.camur.etki_turu);
            
        }
        if (strstr(line, "\"Ates_Iblisi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            OC.ates_iblisi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &OC.ates_iblisi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &OC.ates_iblisi.etkiledigi_birim);
            
        }
        if (strstr(line, "\"Buz_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            OC.buz_devi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &OC.buz_devi.etki_turu);
            
        }
    }    
    fclose(file);
}

void parse_skill_json(const char *filename, Research R)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"savunma_ustaligi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.savunma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.savunma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.savunma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.savunma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.savunma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.savunma_ustaligi.seviye_3.aciklama);
        }
        if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.saldiri_gelistirmesi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.saldiri_gelistirmesi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.saldiri_gelistirmesi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.saldiri_gelistirmesi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.saldiri_gelistirmesi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.saldiri_gelistirmesi.seviye_3.aciklama);
        }
        if (strstr(line, "\"elit_egitim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.elit_egitim.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.elit_egitim.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.elit_egitim.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.elit_egitim.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.elit_egitim.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.elit_egitim.seviye_3.aciklama);
        }
        if (strstr(line, "\"kusatma_ustaligi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.kusatma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.kusatma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.kusatma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.kusatma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R.kusatma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", R.kusatma_ustaligi.seviye_3.aciklama);
        }
    }

    fclose(file);
}

void parse_scenario_file(FILE *file, Human_Unit HU, Ork_Unit OU, Human_Hero HH, Ork_Hero OH, Human_Creature HC, Ork_Creature OC, Research_Side RS)
{
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "piyadeler"))
        {
            sscanf(line, " \"piyadeler\": %d,", &HU.piyadeler.sayi);
        }
        if (strstr(line, "okcular"))
        {
            sscanf(line, " \"okcular\": %d,", &HU.okcular.sayi);
        }
        if (strstr(line, "suvariler"))
        {
            sscanf(line, " \"suvariler\": %d,", &HU.suvariler.sayi);
        }
        if (strstr(line, "kusatma_makineleri"))
        {
            sscanf(line, " \"kusatma_makineleri\": %d,", &HU.kusatma_makineleri.sayi);
        }
        if (strstr(line, "ork_dovusculeri"))
        {
            sscanf(line, " \"ork_dovusculeri\": %d,", &OU.ork_dovusculeri.sayi);
        }
        if (strstr(line, "mizrakcilar"))
        {
            sscanf(line, " \"mizrakcilar\": %d,", &OU.mizrakcilar.sayi);
        }
        if (strstr(line, "varg_binicileri"))
        {
            sscanf(line, " \"varg_binicileri\": %d,", &OU.varg_binicileri.sayi);
        }
        if (strstr(line, "troller"))
        {
            sscanf(line, " \"troller\": %d,", &OU.troller.sayi);
        }

        if (strstr(line, "\"insan_imparatorlugu\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Alparslan\""))
                {
                    HH.alparslan.sayi++;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\""))
                {
                    HH.fsm.sayi++;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\""))
                {
                    HH.yss.sayi++;
                }
                if (strstr(line, "\"Tugrul_Bey\""))
                {
                    HH.tugrul_bey.sayi++;
                }
            }
        }

        if (strstr(line, "\"ork_legi\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Goruk_Vahsi\""))
                {
                    OH.goruk.sayi++;
                }
                if (strstr(line, "\"Thruk_Kemikkiran\""))
                {
                    OH.thruk.sayi++;
                }
                if (strstr(line, "\"Vrog_Kafakiran\""))
                {
                    OH.vrog.sayi++;
                }
                if (strstr(line, "\"Ugar_Zalim\""))
                {
                    OH.ugar.sayi++;
                }
            }
        }
            if (strstr(line, "\"canavarlar\": [")) {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Ejderha\""))
                {
                    HC.ejderha.sayi++;
                }
                if (strstr(line, "\"Agri_Dagi\""))
                {
                    HC.agri_dagi.sayi++;
                }
                if (strstr(line, "\"Tepegoz\""))
                {
                    HC.tepegoz.sayi++;
                }
                if (strstr(line, "\"Karakurt\""))
                {
                    HC.karakurt.sayi++;
                }
                if (strstr(line, "\"Samur\"")) 
                {
                    HC.samur.sayi++;
                }
            }
        }

        if (strstr(line, "\"ork_legi\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Troll\""))
                {
                    OC.troll.sayi++;
                }
                if (strstr(line, "\"Golge\""))
                {
                    OC.golge.sayi++;
                }
                if (strstr(line, "\"Camur\""))
                {
                    OC.camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\""))
                {
                    OC.ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devi\""))
                {
                    OC.buz_devi.sayi++;
                }
            }
        }

        int value;
        if (strstr(line, "\"insan_imparatorlugu\": {") )
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
            {
                if (strstr(line, "savunma_ustaligi"))
                {
                    sscanf(line, " \"savunma_ustaligi\": %d,", &value);
                
                    if (value == 1)
                    {
                        RS.Human_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Human_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Human_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi"))
                {
                    sscanf(line, " \"saldiri_gelistirmesi\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Human_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Human_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Human_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim"))
                {
                    sscanf(line, " \"elit_egitim\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Human_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Human_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Human_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi"))
                {
                    sscanf(line, " \"kusatma_ustaligi\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Human_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Human_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Human_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
        
        if (strstr(line, "\"ork_legi\": {") )
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
            {
                if (strstr(line, "savunma_ustaligi"))
                {
                    sscanf(line, " \"savunma_ustaligi\": %d,", &value);
                
                    if (value == 1)
                    {
                        RS.Ork_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Ork_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Ork_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi"))
                {
                    sscanf(line, " \"saldiri_gelistirmesi\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Ork_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Ork_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Ork_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim"))
                {
                    sscanf(line, " \"elit_egitim\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Ork_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Ork_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Ork_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi"))
                {
                    sscanf(line, " \"kusatma_ustaligi\": %d,", &value);
                    if (value == 1)
                    {
                        RS.Ork_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS.Ork_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS.Ork_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }

    }
    fclose(file);
}

void parse_unit_json(const char *filename, Human_Unit HU, Ork_Unit OU)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"piyadeler\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU.piyadeler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU.piyadeler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU.piyadeler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU.piyadeler.kritik_sans);
        }
        if (strstr(line, "\"okcular\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU.okcular.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU.okcular.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU.okcular.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU.okcular.kritik_sans);
        }
        if (strstr(line, "\"suvariler\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU.suvariler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU.suvariler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU.suvariler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU.suvariler.kritik_sans);
        }
        if (strstr(line, "\"kusatma_makineleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU.kusatma_makineleri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU.kusatma_makineleri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU.kusatma_makineleri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU.kusatma_makineleri.kritik_sans);
        }
        if (strstr(line, "\"ork_dovusculeri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU.ork_dovusculeri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU.ork_dovusculeri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU.ork_dovusculeri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU.ork_dovusculeri.kritik_sans);
        }
        if (strstr(line, "\"mizrakcilar\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU.mizrakcilar.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU.mizrakcilar.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU.mizrakcilar.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU.mizrakcilar.kritik_sans);
        }
        if (strstr(line, "\"varg_binicileri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU.varg_binicileri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU.varg_binicileri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU.varg_binicileri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU.varg_binicileri.kritik_sans);
        }
        if (strstr(line, "\"troller\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU.troller.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU.troller.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU.troller.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU.troller.kritik_sans);
        }
    }

    fclose(file);
}

void parse_hero_json(const char *filename, Human_Hero HH, Ork_Hero OH)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char bonus_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Alparslan\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &HH.alparslan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &HH.alparslan.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            HH.alparslan.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &HH.fsm.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &HH.fsm.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            HH.fsm.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &HH.yss.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &HH.yss.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            HH.yss.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Tugrul_Bey\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &HH.tugrul_bey.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &HH.tugrul_bey.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            HH.tugrul_bey.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &OH.goruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &OH.goruk.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            OH.goruk.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &OH.thruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &OH.thruk.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            OH.thruk.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &OH.vrog.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &OH.vrog.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            OH.vrog.bonus_degeri = atoi(bonus_str);
        }
        if (strstr(line, "\"Ugar_Zalim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &OH.ugar.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &OH.ugar.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            OH.ugar.bonus_degeri = atoi(bonus_str);
        }
    }    
    fclose(file);
}