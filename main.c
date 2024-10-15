#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int saldiri;
    int savunma;
    int saglik;
    int kritik_sans;
    int sayi;
    int vurus_sayisi;
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
    char aciklama[256];
    int bonus_degeri;
    int sayi;
} Hero;

typedef struct {
    Hero alparslan;
    Hero fsm;
    Hero metehan;
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
    char aciklama[256];
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
    Creature makrog;
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

Human_Unit HU;
Ork_Unit OU;
Human_Hero HH;
Ork_Hero OH;
Human_Creature HC;
Ork_Creature OC;
Research_Type RT;
Research HR;
Research OR;
 
void parse_creature_json(const char *filename, Human_Creature *HC, Ork_Creature *OC)
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
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->ejderha.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->ejderha.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->ejderha.aciklama);
            
        }
        if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->agri_dagi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->agri_dagi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->agri_dagi.aciklama);
            
        }
        if (strstr(line, "\"Tepegoz\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->tepegoz.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->tepegoz.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->tepegoz.aciklama);
            ;
        }
        if (strstr(line, "\"Karakurt\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->karakurt.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->karakurt.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->karakurt.aciklama);
            
        }
        if (strstr(line, "\"Samur\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->samur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->samur.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->samur.aciklama);
            
        }
        if (strstr(line, "\"Kara_Troll\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->troll.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->troll.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->troll.aciklama);
            
        }
        if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->golge.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->golge.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->golge.aciklama);
            
        }
        if (strstr(line, "\"Camur_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->camur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->camur.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->camur.aciklama);
            
        }
        if (strstr(line, "\"Ates_Iblisi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->ates_iblisi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->ates_iblisi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->ates_iblisi.aciklama);
            
        }
        if (strstr(line, "\"Makrog_Savas_Beyi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->makrog.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->makrog.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->makrog.etki_turu);
            
        }
        if (strstr(line, "\"Buz_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->buz_devi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->buz_devi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->buz_devi.aciklama);
            
        }
    }    
    fclose(file);
}

void yazdir_human_unit(Human_Unit *hu) {
    printf("Piyadeler - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->piyadeler.saldiri, hu->piyadeler.savunma, hu->piyadeler.saglik, hu->piyadeler.kritik_sans, hu->piyadeler.sayi);
    printf("Okcular - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->okcular.saldiri, hu->okcular.savunma, hu->okcular.saglik, hu->okcular.kritik_sans, hu->okcular.sayi);
    printf("Suvariler - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->suvariler.saldiri, hu->suvariler.savunma, hu->suvariler.saglik, hu->suvariler.kritik_sans, hu->suvariler.sayi);
    printf("Kusatma Makineleri - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->kusatma_makineleri.saldiri, hu->kusatma_makineleri.savunma, hu->kusatma_makineleri.saglik, hu->kusatma_makineleri.kritik_sans, hu->kusatma_makineleri.sayi);
}

void yazdir_ork_unit(Ork_Unit *ou) {
    printf("Ork Dövüşçüleri - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Şans: %d, Sayi: %d\n", 
            ou->ork_dovusculeri.saldiri, ou->ork_dovusculeri.savunma, ou->ork_dovusculeri.saglik, ou->ork_dovusculeri.kritik_sans, ou->ork_dovusculeri.sayi);
    printf("Mizrakcilar - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Şans: %d, Sayi: %d\n", 
            ou->mizrakcilar.saldiri, ou->mizrakcilar.savunma, ou->mizrakcilar.saglik, ou->mizrakcilar.kritik_sans, ou->mizrakcilar.sayi);
    printf("Varg Binicileri - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Şans: %d, Sayi: %d\n", 
            ou->varg_binicileri.saldiri, ou->varg_binicileri.savunma, ou->varg_binicileri.saglik, ou->varg_binicileri.kritik_sans, ou->varg_binicileri.sayi);
    printf("Troller - Saldiri: %d, Savunma: %d, Saglik: %d, Kritik Şans: %d, Sayi: %d\n", 
            ou->troller.saldiri, ou->troller.savunma, ou->troller.saglik, ou->troller.kritik_sans, ou->troller.sayi);
}

void yazdir_hero(Hero *hero) {
    printf("Bonus Turu: %s, Aciklama: %s, Bonus Değeri: %d, Sayi: %d\n", 
            hero->bonus_turu, hero->aciklama, hero->bonus_degeri, hero->sayi);
}

void yazdir_human_hero(Human_Hero *hh) {
    printf("Alparslan:\n");
    yazdir_hero(&hh->alparslan);
    printf("FSM:\n");
    yazdir_hero(&hh->fsm);
    printf("Metehan:\n");
    yazdir_hero(&hh->metehan);
    printf("YSS:\n");
    yazdir_hero(&hh->yss);
    printf("Tugrul Bey:\n");
    yazdir_hero(&hh->tugrul_bey);
}

void yazdir_ork_hero(Ork_Hero *oh) {
    printf("Goruk:\n");
    yazdir_hero(&oh->goruk);
    printf("Thruk:\n");
    yazdir_hero(&oh->thruk);
    printf("Vrog:\n");
    yazdir_hero(&oh->vrog);
    printf("Ugar:\n");
    yazdir_hero(&oh->ugar);
}

void yazdir_creature(Creature *creature) {
    printf("Etki Degeri: %d, Etki Turu: %s, Aciklama: %s, Sayi: %d\n", 
            creature->etki_degeri, creature->etki_turu, creature->aciklama, creature->sayi);
}

void yazdir_human_creature(Human_Creature *hc) {
    printf("Ejderha:\n");
    yazdir_creature(&hc->ejderha);
    printf("Agri Dagi:\n");
    yazdir_creature(&hc->agri_dagi);
    printf("Tepegoz:\n");
    yazdir_creature(&hc->tepegoz);
    printf("Karakurt:\n");
    yazdir_creature(&hc->karakurt);
    printf("Samur:\n");
    yazdir_creature(&hc->samur);
}

void yazdir_ork_creature(Ork_Creature *oc) {
    printf("Troll:\n");
    yazdir_creature(&oc->troll);
    printf("Golge:\n");
    yazdir_creature(&oc->golge);
    printf("Camur:\n");
    yazdir_creature(&oc->camur);
    printf("Ates Iblisi:\n");
    yazdir_creature(&oc->ates_iblisi);
    printf("Makrog:\n");
    yazdir_creature(&oc->makrog);
    printf("Buz Devi:\n");
    yazdir_creature(&oc->buz_devi);
}

void yazdir_seviye(Seviye *seviye) {
    printf("Deger: %d, Aciklama: %s, Sayi: %d\n", seviye->deger, seviye->aciklama, seviye->sayi);
}

void yazdir_human_research(Research *HR) {
    printf("Insan Arastirma: \n");
    printf("Savunma Ustaligi Seviye 1:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_1);
    printf("Savunma Ustaligi Seviye 2:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_2);
    printf("Savunma Ustaligi Seviye 3:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_3);
    
    printf("Saldiri Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_1);
    printf("Saldiri Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_2);
    printf("Saldiri Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_3);

    printf("Elit Egitim Seviye 1:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_1);
    printf("Elit Egitim Seviye 2:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_2);
    printf("Elit Egitim Seviye 3:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_3);

    printf("Kusatma Ustaligi Seviye 1:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_1);
    printf("Kusatma Ustaligi Seviye 2:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_2);
    printf("Kusatma Ustaligi Seviye 3:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_3);
}

void yazdir_ork_research(Research *OR) {
    printf("Ork Arastirma: \n");
    printf("Savunma Ustaligi Seviye 1:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_1);
    printf("Savunma Ustaligi Seviye 2:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_2);
    printf("Savunma Ustaligi Seviye 3:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_3);
    
    printf("Saldiri Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_1);
    printf("Saldiri Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_2);
    printf("Saldiri Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_3);

    printf("Elit Egitim Seviye 1:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_1);
    printf("Elit Egitim Seviye 2:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_2);
    printf("Elit Egitim Seviye 3:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_3);

    printf("Kusatma Ustaligi Seviye 1:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_1);
    printf("Kusatma Ustaligi Seviye 2:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_2);
    printf("Kusatma Ustaligi Seviye 3:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_3);
}

void parse_hero_json(const char *filename, Human_Hero *HH, Ork_Hero *OH)
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
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->alparslan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->alparslan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->alparslan.aciklama);
            
        }
        if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->fsm.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->fsm.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->fsm.aciklama);
            
        }
        if (strstr(line, "\"Mete_Han\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->metehan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->metehan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->metehan.aciklama);
            
        }
        if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->yss.bonus_turu);            
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->yss.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->yss.aciklama);
        }
        if (strstr(line, "\"Tugrul_Bey\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->tugrul_bey.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->tugrul_bey.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->tugrul_bey.aciklama);
            
        }
        if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->goruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->goruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->goruk.aciklama);
            
        }
        if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->thruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->thruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->thruk.aciklama);
            
        }
        if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->vrog.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->vrog.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->vrog.aciklama);
            
        }
        if (strstr(line, "\"Ugar_Zalim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->ugar.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->ugar.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->ugar.aciklama);
            
        }
    }    
    fclose(file);
}

void parse_research_json(const char *filename, Research *HR, Research *OR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    Research_Type *current_research_type = NULL;
    Seviye *current_level = NULL;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"savunma_ustaligi\""))
        {
            current_research_type = &HR->savunma_ustaligi;
        }
        else if (strstr(line, "\"saldiri_gelistirmesi\""))
        {
            current_research_type = &HR->saldiri_gelistirmesi;
        }
        else if (strstr(line, "\"elit_egitim\""))
        {
            current_research_type = &HR->elit_egitim;
        }
        else if (strstr(line, "\"kusatma_ustaligi\""))
        {
            current_research_type = &HR->kusatma_ustaligi;
        }
        else if (strstr(line, "\"deger\""))
        {
            if (current_level)
            {
                sscanf(line, " \"deger\": \"%d\"", &current_level->deger);
            }
        }
        else if (strstr(line, "\"aciklama\""))
        {
            if (current_level)
            {
                char *start = strchr(line, ':') + 3;
                strncpy(current_level->aciklama, start, strlen(start) - 2);
                current_level->aciklama[strlen(start) - 2] = '\0';
            }
        }
        else if (strstr(line, "\"seviye_1\""))
        {
            current_level = &current_research_type->seviye_1;
        }
        else if (strstr(line, "\"seviye_2\""))
        {
            current_level = &current_research_type->seviye_2;
        }
        else if (strstr(line, "\"seviye_3\""))
        {
            current_level = &current_research_type->seviye_3;
        }
    }

    fclose(file);

    // OR için verileri kopyalama
    memcpy(&OR->savunma_ustaligi, &HR->savunma_ustaligi, sizeof(Research_Type));
    memcpy(&OR->saldiri_gelistirmesi, &HR->saldiri_gelistirmesi, sizeof(Research_Type));
    memcpy(&OR->elit_egitim, &HR->elit_egitim, sizeof(Research_Type));
    memcpy(&OR->kusatma_ustaligi, &HR->kusatma_ustaligi, sizeof(Research_Type));
}

void parse_scenario_file(FILE *file, Human_Unit *HU, Ork_Unit *OU, Human_Hero *HH, Ork_Hero *OH, Human_Creature *HC, Ork_Creature *OC, Research *HR, Research *OR)
{
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    char line[256];
    int value = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"insan_imparatorlugu\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "ork_legi"))
            {
                if (strstr(line, "\"piyadeler\"") != NULL)
                {
                    sscanf(line, " \"piyadeler\": %d,", &HU->piyadeler.sayi);
                }
                if (strstr(line, "okcular") != NULL)
                {
                    sscanf(line, " \"okcular\": %d,", &HU->okcular.sayi);
                }
                if (strstr(line, "suvariler") != NULL)
                {
                    sscanf(line, " \"suvariler\": %d,", &HU->suvariler.sayi);
                }
                if (strstr(line, "kusatma_makineleri") != NULL)
                {
                    sscanf(line, " \"kusatma_makineleri\": %d,", &HU->kusatma_makineleri.sayi);
                }
                if (strstr(line, "\"Alparslan\"") != NULL)
                {
                    HH->alparslan.sayi = 1;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
                {
                    HH->fsm.sayi = 1;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
                {
                    HH->yss.sayi = 1;
                }
                if (strstr(line, "\"Tugrul_Bey\"") != NULL)
                {
                    HH->tugrul_bey.sayi = 1;
                }
                if (strstr(line, "\"Ejderha\"") != NULL)
                {
                    HC->ejderha.sayi = 1;
                }
                if (strstr(line, "\"Agri_Dagi\"") != NULL)
                {
                    HC->agri_dagi.sayi = 1;
                }
                if (strstr(line, "\"Tepegoz\"") != NULL)
                {
                    HC->tepegoz.sayi = 1;
                }
                if (strstr(line, "\"Karakurt\"") != NULL)
                {
                    HC->karakurt.sayi = 1;
                }
                if (strstr(line, "\"Samur\"") != NULL) 
                {
                    HC->samur.sayi = 1;
                }
                if (strstr(line, "\"savunma_ustaligi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->savunma_ustaligi.seviye_1.sayi = 1;
                    }
                    else if (value == 2)
                    {
                        HR->savunma_ustaligi.seviye_2.sayi = 1;
                    }
                    else if (value == 3)
                    {
                        HR->savunma_ustaligi.seviye_3.sayi = 1;
                    }
                }
                if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
        
        if (strstr(line, "\"ork_legi\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "insan_imparatorlugu"))
            {
                if (strstr(line, "ork_dovusculeri") != NULL)
                {
                    sscanf(line, " \"ork_dovusculeri\": %d,", &OU->ork_dovusculeri.sayi);
                }
                if (strstr(line, "mizrakcilar") != NULL)
                {
                    sscanf(line, " \"mizrakcilar\": %d,", &OU->mizrakcilar.sayi);
                }
                if (strstr(line, "varg_binicileri") != NULL)
                {
                    sscanf(line, " \"varg_binicileri\": %d,", &OU->varg_binicileri.sayi);
                }
                if (strstr(line, "troller") != NULL)
                {
                    sscanf(line, " \"troller\": %d,", &OU->troller.sayi);
                }
                if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
                {
                    OH->goruk.sayi++;
                }
                if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
                {
                    OH->thruk.sayi++;
                }
                if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
                {
                    OH->vrog.sayi++;
                }
                if (strstr(line, "\"Ugar_Zalim\"") != NULL)
                {
                    OH->ugar.sayi++;
                }
                if (strstr(line, "\"Troll\"") != NULL)
                {
                    OC->troll.sayi++;
                }
                if (strstr(line, "\"Golge\"") != NULL)
                {
                    OC->golge.sayi++;
                }
                if (strstr(line, "\"Camur\"") != NULL)
                {
                    OC->camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\"") != NULL)
                {
                    OC->ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devi\"") != NULL)
                {
                    OC->buz_devi.sayi++;
                }
                if (strstr(line, "savunma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);               
                    if (value == 1)
                    {
                        OR->savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }

    }
    fclose(file);
}

void parse_unit_json(const char *filename, Human_Unit *HU, Ork_Unit *OU)
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
            sscanf(line, " \"saldiri\" : %d,", &HU->piyadeler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->piyadeler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->piyadeler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->piyadeler.kritik_sans);
        }
        if (strstr(line, "\"okcular\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\" : %d,", &HU->okcular.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->okcular.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->okcular.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->okcular.kritik_sans);
        }
        if (strstr(line, "\"suvariler\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\" : %d,", &HU->suvariler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->suvariler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->suvariler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->suvariler.kritik_sans);
        }
        if (strstr(line, "\"kusatma_makineleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU->kusatma_makineleri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU->kusatma_makineleri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU->kusatma_makineleri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU->kusatma_makineleri.kritik_sans);
        }
        if (strstr(line, "\"ork_dovusculeri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->ork_dovusculeri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->ork_dovusculeri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->ork_dovusculeri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->ork_dovusculeri.kritik_sans);
        }
        if (strstr(line, "\"mizrakcilar\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->mizrakcilar.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->mizrakcilar.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->mizrakcilar.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->mizrakcilar.kritik_sans);
        }
        if (strstr(line, "\"varg_binicileri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->varg_binicileri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->varg_binicileri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->varg_binicileri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->varg_binicileri.kritik_sans);
        }
        if (strstr(line, "\"troller\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->troller.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->troller.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->troller.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->troller.kritik_sans);
        }
    }

    fclose(file);
}

// Kritik vuruş kontrolü (Belirli adımlarda kritik vuruş yapar)
int kritik_vurus_kontrol(Unit *saldiran) {
    int vurus_periyodu = 100 / saldiran->kritik_sans;
    if (saldiran->vurus_sayisi % vurus_periyodu == 0 && saldiran->vurus_sayisi != 0) {
        return 1;  // Kritik vuruş
    }
    return 0;  // Normal vuruş
}

// Saldırı gücünü hesaplayan fonksiyon
double saldiri_gucu_hesapla(Unit *saldiran) {
    double toplam_saldiri_gucu = saldiran->saldiri * saldiran->sayi;
    if (kritik_vurus_kontrol(saldiran)) {
        printf("Kritik vurus! Saldiri gucu 1.5 katina cikti!\n");
        toplam_saldiri_gucu *= 1.5;  // Kritik vuruş varsa saldırı gücü 1.5 katına çıkar
    }
    saldiran->vurus_sayisi++;  // Vuruş sayısını artır
    return toplam_saldiri_gucu;
}

// Net hasarı hesaplayan fonksiyon (Toplam saldırı gücü ve toplam savunma gücü kullanarak)
double net_hasar_hesapla(double toplam_saldiri_gucu, double toplam_savunma_gucu) {
    if (toplam_savunma_gucu >= toplam_saldiri_gucu) {
        return 0;  // Savunma saldırıdan büyükse, net hasar 0 olur
    }
    return toplam_saldiri_gucu * (1 - (toplam_savunma_gucu / toplam_saldiri_gucu));
}

// Sağlık kaybını orantılı olarak hesapla
void saglik_kaybi_hesapla_orantili(Unit *unit, double toplam_savunma, double net_hasar) {

    if (unit->saglik > 0) { // Sağlık 0'dan büyükse hasar uygula
        double orantili_hasar = ((unit->savunma * unit->sayi / toplam_savunma)) * net_hasar;
        unit->saglik -= orantili_hasar;
        if (unit->saglik < 0) unit->saglik = 0; // Sağlık negatif olamaz
    }
}
// Kazananı belirleme fonksiyonu
void kazanani_belirle(Human_Unit *insan, Ork_Unit *ork) {
    // İnsanların sağlık durumu
    int insan_kazandi = 1; // Başlangıçta insan kazanacak varsayıyoruz
    int orc_kazandi = 1; // Başlangıçta orc kazanacak varsayıyoruz

    // İnsanların sağlığını kontrol et
    if (insan->piyadeler.saglik <= 0 && insan->suvariler.saglik <= 0 && 
        insan->okcular.saglik <= 0 && insan->kusatma_makineleri.saglik <= 0) {
        insan_kazandi = 0; // Eğer tüm insanlar yoksa, insan kazanamaz
    }

    // Orkların sağlığını kontrol et
    if (ork->ork_dovusculeri.saglik <= 0 && ork->mizrakcilar.saglik <= 0 && 
        ork->troller.saglik <= 0 && ork->varg_binicileri.saglik <= 0) {
        orc_kazandi = 0; // Eğer tüm orklar yoksa, orc kazanamaz
    }

    // Kazananı yazdır
    if (insan_kazandi && !orc_kazandi) {
        printf("Kazanan: İnsan Irkı!\n");
    } else if (orc_kazandi && !insan_kazandi) {
        printf("Kazanan: Orc Irkı!\n");
    } else if (!insan_kazandi && !orc_kazandi) {
        printf("Oyun berabere!\n");
    } else {
        printf("Savaş devam ediyor!\n");
    }
}
// Adım adım savaşı yürüten fonksiyon
void savas_adim_adim(Human_Unit *insan, Ork_Unit *ork, int adim) {
    printf("\nAdim %d:\n", adim);

    double toplam_human_saldiri = 0.0;
    double toplam_ork_saldiri = 0.0;

    // İnsanların toplam saldırı gücünü hesapla (Sadece sayısı 0'dan büyük olanlar)
    if (insan->piyadeler.sayi > 0) toplam_human_saldiri += saldiri_gucu_hesapla(&insan->piyadeler);
    if (insan->suvariler.sayi > 0) toplam_human_saldiri += saldiri_gucu_hesapla(&insan->suvariler);
    if (insan->okcular.sayi > 0) toplam_human_saldiri += saldiri_gucu_hesapla(&insan->okcular);
    if (insan->kusatma_makineleri.sayi > 0) toplam_human_saldiri += saldiri_gucu_hesapla(&insan->kusatma_makineleri);

    printf("Insan irki toplamda %.2f hasar verdi.\n", toplam_human_saldiri);

    // Orkların toplam savunma gücünü hesapla (Sadece sayısı 0'dan büyük olanlar)
    double toplam_ork_savunma = 0.0;
    if (ork->ork_dovusculeri.sayi > 0) toplam_ork_savunma += (ork->ork_dovusculeri.savunma * ork->ork_dovusculeri.sayi);
    if (ork->mizrakcilar.sayi > 0) toplam_ork_savunma += (ork->mizrakcilar.savunma * ork->mizrakcilar.sayi);
    if (ork->troller.sayi > 0) toplam_ork_savunma += (ork->troller.savunma * ork->troller.sayi);
    if (ork->varg_binicileri.sayi > 0) toplam_ork_savunma += (ork->varg_binicileri.savunma * ork->varg_binicileri.sayi);

    printf("Orklar toplam savunma gucu: %.2f\n", toplam_ork_savunma);

    // İnsanların net hasarını hesapla ve Orklara dağıt
    double net_human_hasar = net_hasar_hesapla(toplam_human_saldiri, toplam_ork_savunma);
    printf("Insan irki net %.2f hasar verdi.\n", net_human_hasar);
    
    // Ork birimlerinin sağlık kaybını uygula (sadece sağlığı 0'dan büyük olanlar)
    if (ork->ork_dovusculeri.sayi > 0) saglik_kaybi_hesapla_orantili(&ork->ork_dovusculeri, toplam_ork_savunma, net_human_hasar);
    if (ork->mizrakcilar.sayi > 0) saglik_kaybi_hesapla_orantili(&ork->mizrakcilar, toplam_ork_savunma, net_human_hasar);

    // Orkların toplam saldırı gücünü hesapla (Sadece sayısı 0'dan büyük olanlar)
    if (ork->ork_dovusculeri.sayi > 0) toplam_ork_saldiri += saldiri_gucu_hesapla(&ork->ork_dovusculeri);
    if (ork->mizrakcilar.sayi > 0) toplam_ork_saldiri += saldiri_gucu_hesapla(&ork->mizrakcilar);
    if (ork->troller.sayi > 0) toplam_ork_saldiri += saldiri_gucu_hesapla(&ork->troller);
    if (ork->varg_binicileri.sayi > 0) toplam_ork_saldiri += saldiri_gucu_hesapla(&ork->varg_binicileri);

    printf("Orklar toplamda %.2f hasar verdi.\n", toplam_ork_saldiri);

    // İnsanların toplam savunma gücünü hesapla (Sadece sayısı 0'dan büyük olanlar)
    double toplam_human_savunma = 0.0;
    if (insan->piyadeler.sayi > 0) toplam_human_savunma += (insan->piyadeler.savunma * insan->piyadeler.sayi);
    if (insan->suvariler.sayi > 0) toplam_human_savunma += (insan->suvariler.savunma * insan->suvariler.sayi);
    if (insan->okcular.sayi > 0) toplam_human_savunma += (insan->okcular.savunma * insan->okcular.sayi);
    if (insan->kusatma_makineleri.sayi > 0) toplam_human_savunma += (insan->kusatma_makineleri.savunma * insan->kusatma_makineleri.sayi);

    printf("Insan irki toplam savunma gucu: %.2f\n", toplam_human_savunma);

    // Orkların net hasarını hesapla ve İnsanlara dağıt
    double net_ork_hasar = net_hasar_hesapla(toplam_ork_saldiri, toplam_human_savunma);
    printf("Orklar net %.2f hasar verdi.\n", net_ork_hasar);
    
    // İnsan birimlerinin sağlık kaybını uygula (sadece sağlığı 0'dan büyük olanlar)
    if (insan->piyadeler.sayi > 0) saglik_kaybi_hesapla_orantili(&insan->piyadeler, toplam_human_savunma, net_ork_hasar);
    if (insan->suvariler.sayi > 0) saglik_kaybi_hesapla_orantili(&insan->suvariler, toplam_human_savunma, net_ork_hasar);
    if (insan->okcular.sayi > 0) saglik_kaybi_hesapla_orantili(&insan->okcular, toplam_human_savunma, net_ork_hasar);
    if (insan->kusatma_makineleri.sayi > 0) saglik_kaybi_hesapla_orantili(&insan->kusatma_makineleri, toplam_human_savunma, net_ork_hasar);

    // Adım sonrası birimlerin sağlık durumunu yazdır
    printf("Adim %d sonrasi birimlerin saglik durumu:\n", adim);
    printf("Piyadeler: %.2f, Suvariler: %.2f, Okcular: %.2f, Kusatma Makineleri: %.2f\n", 
           insan->piyadeler.saglik, insan->suvariler.saglik, insan->okcular.saglik, insan->kusatma_makineleri.saglik);
    printf("Ork Dovusculer: %.2f, Mizrakcilar: %.2f, Troller: %.2f, Varg Binicileri: %.2f\n", 
           ork->ork_dovusculeri.saglik, ork->mizrakcilar.saglik, ork->troller.saglik, ork->varg_binicileri.saglik);
}

int main()
{
    parse_unit_json("unit_types.json", &HU, &OU);
    parse_hero_json("heroes.json", &HH, &OH);
    parse_creature_json("creatures.json", &HC, &OC);
    parse_research_json("research.json", &HR, &OR);

    FILE *file = fopen("1.json", "r");
    parse_scenario_file(file, &HU, &OU, &HH, &OH, &HC, &OC, &HR, &OR);

    


int adim = 1;

    // Savaş adım adım simülasyonu
    while (1) { // Sonsuz döngü, kazanan belirlenene kadar devam edecek
        savas_adim_adim(&HU, &OU, adim);

        // Kazananı kontrol et
        kazanani_belirle(&HU, &OU);
        
        // Eğer bir taraf kazandıysa döngüyü kır
        if ((HU.piyadeler.saglik <= 0 && HU.suvariler.saglik <= 0 &&
             HU.okcular.saglik <= 0 && HU.kusatma_makineleri.saglik <= 0) || 
            (OU.ork_dovusculeri.saglik <= 0 && OU.mizrakcilar.saglik <= 0 &&
             OU.troller.saglik <= 0 && OU.varg_binicileri.saglik <= 0)) {
            break; // Döngüden çık
        }

        adim++; // Adım sayısını artır
    } 
     //yazdir_human_unit(&HU);       //her seyi okuyo
     //yazdir_ork_unit(&OU);         //her seyi okuyo
     //yazdir_human_hero(&HH);       //her seyi okuyo
     //yazdir_ork_hero(&OH);         //her seyi okuyo
     //yazdir_human_creature(&HC);   //her seyi okuyo
     //yazdir_ork_creature(&OC);     //her seyi okuyo
     //yazdir_human_research(&HR);   //her seyi okuyo
     //yazdir_ork_research(&OR);     //her seyi okuyo

     

    fclose(file);
    return 0;
}
