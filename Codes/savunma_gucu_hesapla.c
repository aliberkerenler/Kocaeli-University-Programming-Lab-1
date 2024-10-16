void savunma_gucu_hesapla(Human_Unit *HU , Ork_Unit *OU ,int *toplam_insan_savunma , int *toplam_ork_savunma) {

    *toplam_insan_savunma = (HU->piyadeler.savunma * HU->piyadeler.sayi) + 
                            (HU->okcular.savunma * HU->okcular.sayi) +     
                            (HU->suvariler.savunma * HU->suvariler.sayi) + 
                            (HU->kusatma_makineleri.savunma * HU->kusatma_makineleri.sayi); 

    *toplam_ork_savunma = (OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) + 
                          (OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) +    
                          (OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) + 
                          (OU->troller.savunma * OU->troller.sayi);             

}