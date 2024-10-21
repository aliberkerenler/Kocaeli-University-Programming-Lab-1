void saldiri_gucu_hesapla(Human_Unit *HU, Ork_Unit *OU, int adim, double *toplam_insan_saldiri, double *toplam_ork_saldiri)
{
    *toplam_insan_saldiri = kritik_vurus_hesapla(&HU->piyadeler, adim) +
                            kritik_vurus_hesapla(&HU->okcular, adim) +
                            kritik_vurus_hesapla(&HU->suvariler, adim) +
                            kritik_vurus_hesapla(&HU->kusatma_makineleri, adim) ;


    *toplam_ork_saldiri =   kritik_vurus_hesapla(&OU->ork_dovusculeri, adim) +
                            kritik_vurus_hesapla(&OU->mizrakcilar, adim) +
                            kritik_vurus_hesapla(&OU->varg_binicileri, adim) +
                            kritik_vurus_hesapla(&OU->troller, adim);

}
