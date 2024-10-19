void savas_adim_adim(Human_Unit *HU, Ork_Unit *OU, int adim) {
    printf("\nAdim %d:\n", adim);

    double toplam_insan_saldiri = 0;
    double toplam_ork_saldiri = 0;
    double toplam_insan_savunma = 0;
    double toplam_ork_savunma = 0;

    // Saldiri ve savunma guclerini hesapla
    saldiri_gucu_hesapla(HU, OU, adim, &toplam_insan_saldiri, &toplam_ork_saldiri);
    savunma_gucu_hesapla(HU, OU, &toplam_insan_savunma, &toplam_ork_savunma);

    // Insanlarin orklara verdigi net hasari hesapla
    

    // Orklarin insanlara verdigi net hasari hesapla
    

    if(adim % 2 == 0)
    {
        double net_hasar_ork = ork_net_hasar_hesaplama(OU, &toplam_ork_saldiri, &toplam_ork_savunma, &toplam_insan_savunma);
        printf("Ork irki insan birimlerine %.2f hasar verdi.\n", net_hasar_ork);
        insan_saglik_hesapla(HU, net_hasar_ork, &toplam_insan_savunma);
        printf("Insan Piyadelerinin yeni sayisi: %d\n", HU->piyadeler.sayi);
        printf("Insan Okcularinin yeni sayisi: %d\n", HU->okcular.sayi);
        printf("Insan Suvarilerinin yeni sayisi: %d\n", HU->suvariler.sayi);
        printf("Insan Kusatma Makinelerinin yeni sayisi: %d\n", HU->kusatma_makineleri.sayi);

    }

    if(adim % 2 == 1)
    {
        double net_hasar_insan = insan_net_hasar_hesaplama(HU, &toplam_insan_saldiri, &toplam_insan_savunma, &toplam_ork_savunma);
        printf("Insan irki ork birimlerine %.2f hasar verdi.\n", net_hasar_insan);
        ork_saglik_hesapla(OU, net_hasar_insan, &toplam_ork_savunma);
        printf("Ork Dovusculerinin yeni sayisi: %d\n", OU->ork_dovusculeri.sayi);
        printf("Ork Mizrakcilarinin yeni sayisi: %d\n", OU->mizrakcilar.sayi);
        printf("Ork Varg Binicilerinin yeni sayisi: %d\n", OU->varg_binicileri.sayi);
        printf("Ork Trollerinin yeni sayisi: %d\n\n", OU->troller.sayi);
    }
    
    // Guncellenen sayi durumlarini yazdir


    // Eger insan birimlerinin sayilari 0'a ulastiysa savasi bitir
    if (HU->piyadeler.sayi <= 0 && HU->okcular.sayi <= 0 &&
        HU->suvariler.sayi <= 0 && HU->kusatma_makineleri.sayi <= 0) {
        printf("Ork irki kazandi!\n");
        return;
    }

    // Eger ork birimlerinin sayilari 0'a ulastiysa savasi bitir
    if (OU->ork_dovusculeri.sayi <= 0 && OU->mizrakcilar.sayi <= 0 &&
        OU->varg_binicileri.sayi <= 0 && OU->troller.sayi <= 0) {
        printf("Insan irki kazandi!\n\n");
        return;
    }
}
