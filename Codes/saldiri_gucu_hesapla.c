void saldiri_gucu_hesapla(Human_Unit *HU, Ork_Unit *OU,  int *toplam_insan_saldiri, int *toplam_ork_saldiri) {
    
    *toplam_insan_saldiri = (HU->piyadeler.saldiri * HU->piyadeler.sayi) +
                            (HU->okcular.saldiri * HU->okcular.sayi) +     
                            (HU->suvariler.saldiri * HU->suvariler.sayi) +
                            (HU->kusatma_makineleri.saldiri * HU->kusatma_makineleri.sayi); 

    *toplam_ork_saldiri = (OU->ork_dovusculeri.saldiri * OU->ork_dovusculeri.sayi) + 
                          (OU->mizrakcilar.saldiri * OU->mizrakcilar.sayi) +     
                          (OU->varg_binicileri.saldiri * OU->varg_binicileri.sayi) + 
                          (OU->troller.saldiri * OU->troller.sayi);           
}