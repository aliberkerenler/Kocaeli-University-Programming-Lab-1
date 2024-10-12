void yazdir_human_unit(Human_Unit *hu) {
    printf("Piyadeler - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            hu->piyadeler.saldiri, hu->piyadeler.savunma, hu->piyadeler.saglik, hu->piyadeler.kritik_sans, hu->piyadeler.sayi);
    printf("Okçular - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            hu->okcular.saldiri, hu->okcular.savunma, hu->okcular.saglik, hu->okcular.kritik_sans, hu->okcular.sayi);
    printf("Süvariler - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            hu->suvariler.saldiri, hu->suvariler.savunma, hu->suvariler.saglik, hu->suvariler.kritik_sans, hu->suvariler.sayi);
    printf("Kuşatma Makineleri - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            hu->kusatma_makineleri.saldiri, hu->kusatma_makineleri.savunma, hu->kusatma_makineleri.saglik, hu->kusatma_makineleri.kritik_sans, hu->kusatma_makineleri.sayi);
}

void yazdir_ork_unit(Ork_Unit *ou) {
    printf("Ork Dövüşçüleri - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            ou->ork_dovusculeri.saldiri, ou->ork_dovusculeri.savunma, ou->ork_dovusculeri.saglik, ou->ork_dovusculeri.kritik_sans, ou->ork_dovusculeri.sayi);
    printf("Mızrakçılar - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            ou->mizrakcilar.saldiri, ou->mizrakcilar.savunma, ou->mizrakcilar.saglik, ou->mizrakcilar.kritik_sans, ou->mizrakcilar.sayi);
    printf("Varg Binicileri - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            ou->varg_binicileri.saldiri, ou->varg_binicileri.savunma, ou->varg_binicileri.saglik, ou->varg_binicileri.kritik_sans, ou->varg_binicileri.sayi);
    printf("Troller - Saldırı: %d, Savunma: %d, Sağlık: %d, Kritik Şans: %d, Sayı: %d\n", 
            ou->troller.saldiri, ou->troller.savunma, ou->troller.saglik, ou->troller.kritik_sans, ou->troller.sayi);
}

void yazdir_hero(Hero *hero) {
    printf("Bonus Türü: %s, Aciklama: %s, Bonus Değeri: %d, Sayı: %d\n", 
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
    printf("Tuğrul Bey:\n");
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
    printf("Etki Değeri: %d, Etki Türü: %s, Aciklama: %s, Sayı: %d\n", 
            creature->etki_degeri, creature->etki_turu, creature->aciklama, creature->sayi);
}

void yazdir_human_creature(Human_Creature *hc) {
    printf("Ejderha:\n");
    yazdir_creature(&hc->ejderha);
    printf("Ağrı Dağı:\n");
    yazdir_creature(&hc->agri_dagi);
    printf("Tepegöz:\n");
    yazdir_creature(&hc->tepegoz);
    printf("Karakurt:\n");
    yazdir_creature(&hc->karakurt);
    printf("Samur:\n");
    yazdir_creature(&hc->samur);
}

void yazdir_ork_creature(Ork_Creature *oc) {
    printf("Troll:\n");
    yazdir_creature(&oc->troll);
    printf("Gölge:\n");
    yazdir_creature(&oc->golge);
    printf("Çamur:\n");
    yazdir_creature(&oc->camur);
    printf("Ateş İblisi:\n");
    yazdir_creature(&oc->ates_iblisi);
    printf("Makrog:\n");
    yazdir_creature(&oc->makrog);
    printf("Buz Devi:\n");
    yazdir_creature(&oc->buz_devi);
}

void yazdir_seviye(Seviye *seviye) {
    printf("Değer: %d, Açıklama: %s, Sayı: %d\n", seviye->deger, seviye->aciklama, seviye->sayi);
}

void yazdir_human_research(Research_Side *side) {
    printf("Insan Arastirma: \n");
    printf("Savunma Ustalığı Seviye 1:\n");
    yazdir_seviye(&side->Human_Research.savunma_ustaligi.seviye_1);
    printf("Savunma Ustalığı Seviye 2:\n");
    yazdir_seviye(&side->Human_Research.savunma_ustaligi.seviye_2);
    printf("Savunma Ustalığı Seviye 3:\n");
    yazdir_seviye(&side->Human_Research.savunma_ustaligi.seviye_3);
    
    printf("Saldırı Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&side->Human_Research.saldiri_gelistirmesi.seviye_1);
    printf("Saldırı Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&side->Human_Research.saldiri_gelistirmesi.seviye_2);
    printf("Saldırı Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&side->Human_Research.saldiri_gelistirmesi.seviye_3);

    printf("Elit Eğitim Seviye 1:\n");
    yazdir_seviye(&side->Human_Research.elit_egitim.seviye_1);
    printf("Elit Eğitim Seviye 2:\n");
    yazdir_seviye(&side->Human_Research.elit_egitim.seviye_2);
    printf("Elit Eğitim Seviye 3:\n");
    yazdir_seviye(&side->Human_Research.elit_egitim.seviye_3);

    printf("Kuşatma Ustalığı Seviye 1:\n");
    yazdir_seviye(&side->Human_Research.kusatma_ustaligi.seviye_1);
    printf("Kuşatma Ustalığı Seviye 2:\n");
    yazdir_seviye(&side->Human_Research.kusatma_ustaligi.seviye_2);
    printf("Kuşatma Ustalığı Seviye 3:\n");
    yazdir_seviye(&side->Human_Research.kusatma_ustaligi.seviye_3);
}

void yazdir_ork_research(Research_Side *side) {
    printf("Ork Arastirma: \n");
    printf("Savunma Ustalığı Seviye 1:\n");
    yazdir_seviye(&side->Ork_Research.savunma_ustaligi.seviye_1);
    printf("Savunma Ustalığı Seviye 2:\n");
    yazdir_seviye(&side->Ork_Research.savunma_ustaligi.seviye_2);
    printf("Savunma Ustalığı Seviye 3:\n");
    yazdir_seviye(&side->Ork_Research.savunma_ustaligi.seviye_3);
    
    printf("Saldırı Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&side->Ork_Research.saldiri_gelistirmesi.seviye_1);
    printf("Saldırı Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&side->Ork_Research.saldiri_gelistirmesi.seviye_2);
    printf("Saldırı Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&side->Ork_Research.saldiri_gelistirmesi.seviye_3);

    printf("Elit Eğitim Seviye 1:\n");
    yazdir_seviye(&side->Ork_Research.elit_egitim.seviye_1);
    printf("Elit Eğitim Seviye 2:\n");
    yazdir_seviye(&side->Ork_Research.elit_egitim.seviye_2);
    printf("Elit Eğitim Seviye 3:\n");
    yazdir_seviye(&side->Ork_Research.elit_egitim.seviye_3);

    printf("Kuşatma Ustalığı Seviye 1:\n");
    yazdir_seviye(&side->Ork_Research.kusatma_ustaligi.seviye_1);
    printf("Kuşatma Ustalığı Seviye 2:\n");
    yazdir_seviye(&side->Ork_Research.kusatma_ustaligi.seviye_2);
    printf("Kuşatma Ustalığı Seviye 3:\n");
    yazdir_seviye(&side->Ork_Research.kusatma_ustaligi.seviye_3);
}