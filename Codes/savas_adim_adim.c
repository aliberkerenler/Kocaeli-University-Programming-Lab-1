void savas_adim_adim(const char *filename, Human_Unit *HU, Ork_Unit *OU, int adim)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }
    fprintf(file, "\nAdim %d:\n", adim);

    double toplam_insan_saldiri = 0;
    double toplam_ork_saldiri = 0;
    double toplam_insan_savunma = 0;
    double toplam_ork_savunma = 0;
    int tur = 0;

    // Saldiri ve savunma guclerini hesapla
    saldiri_gucu_hesapla(HU, OU, adim, &toplam_insan_saldiri, &toplam_ork_saldiri);
    savunma_gucu_hesapla(HU, OU, &toplam_insan_savunma, &toplam_ork_savunma);

    // Insanlarin orklara verdigi net hasari hesapla


    // Orklarin insanlara verdigi net hasari hesapla


    if(adim % 2 == 0)
    {
        double net_hasar_ork = ork_net_hasar_hesaplama(OU, &toplam_ork_saldiri, &toplam_ork_savunma, &toplam_insan_savunma);
        fprintf(file, "Ork irki insan birimlerine %.2f hasar verdi.\n", net_hasar_ork);
        insan_saglik_hesapla(HU, net_hasar_ork, &toplam_insan_savunma);
        fprintf(file, "Insan Piyadeleri: \n Sayi: %d\tSaglik: %d\n", HU->piyadeler.sayi, HU->piyadeler.saglik);
        fprintf(file, "Insan Okculari: \n Sayi: %d\tSaglik: %d\n", HU->okcular.sayi, HU->okcular.saglik);
        fprintf(file, "Insan Suvarileri: \n Sayi: %d\tSaglik: %d\n", HU->suvariler.sayi, HU->suvariler.saglik);
        fprintf(file, "Insan Kusatma Makineleri: \n Sayi: %d\tSaglik: %d\n", HU->kusatma_makineleri.sayi, HU->kusatma_makineleri.saglik);
        tur++;
    }

    if(adim % 2 == 1)
    {
        double net_hasar_insan = insan_net_hasar_hesaplama(HU, &toplam_insan_saldiri, &toplam_insan_savunma, &toplam_ork_savunma);
        fprintf(file, "Insan irki ork birimlerine %.2f hasar verdi.\n", net_hasar_insan);
        ork_saglik_hesapla(OU, net_hasar_insan, &toplam_ork_savunma);
        fprintf(file, "Ork Dovusculeri: \n Sayi: %d\tSaglik: %d\n", OU->ork_dovusculeri.sayi, OU->ork_dovusculeri.saglik);
        fprintf(file, "Ork Mizrakcilari: \n Sayi: %d\tSaglik: %d\n", OU->mizrakcilar.sayi, OU->mizrakcilar.saglik);
        fprintf(file, "Ork Varg Binicileri: \n Sayi: %d\tSaglik: %d\n", OU->varg_binicileri.sayi, OU->varg_binicileri.saglik);
        fprintf(file, "Ork Trolleri: \n Sayi: %d\tSaglik: %d\n\n", OU->troller.sayi, OU->troller.saglik);
    }

    if(tur % 5 == 0)
    {
        HU->piyadeler.saldiri *= 0.9;
        HU->piyadeler.savunma *= 0.9;
        HU->okcular.saldiri *= 0.9;
        HU->okcular.savunma *= 0.9;
        HU->suvariler.saldiri *= 0.9;
        HU->suvariler.savunma *= 0.9;
        HU->kusatma_makineleri.saldiri *= 0.9;
        HU->kusatma_makineleri.savunma *= 0.9;

        OU->ork_dovusculeri.saldiri *= 0.9;
        OU->ork_dovusculeri.savunma *= 0.9;
        OU->mizrakcilar.saldiri *= 0.9;
        OU->mizrakcilar.savunma *= 0.9;
        OU->varg_binicileri.saldiri *= 0.9;
        OU->varg_binicileri.savunma *= 0.9;
        OU->troller.saldiri *= 0.9;
        OU->troller.savunma *= 0.9;
    }

    // Eger insan birimlerinin sayilari 0'a ulastiysa savasi bitir
    if (HU->piyadeler.sayi <= 0 && HU->okcular.sayi <= 0 &&
            HU->suvariler.sayi <= 0 && HU->kusatma_makineleri.sayi <= 0)
    {
        fprintf(file, "Ork irki kazandi!\n");
        return;
    }

    // Eger ork birimlerinin sayilari 0'a ulastiysa savasi bitir
    if (OU->ork_dovusculeri.sayi <= 0 && OU->mizrakcilar.sayi <= 0 &&
            OU->varg_binicileri.sayi <= 0 && OU->troller.sayi <= 0)
    {
        fprintf(file, "Insan irki kazandi!\n\n");
        return;
    }

    fclose(file);
}
