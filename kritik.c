// Kritik vuruş hesabı yapan fonksiyon
int kritik_vurus_hesapla(Unit *unit, int adim)
{
    // Birimin kritik vuruş zamanını hesapla
    if (adim % (100 / unit->kritik_sans) == 0) { 
        return unit->saldiri * unit->sayi * 1.5; // Kritik vuruş varsa hasarı artır
    }

    return unit->saldiri * unit->sayi; // Kritik vuruş yoksa normal hasar
}

// İnsanların toplam saldırı gücünü hesaplayan fonksiyon
void saldiri_gucu_hesapla(Human_Unit *HU, Ork_Unit *OU , int adim , double *toplam_insan_saldiri , double *toplam_ork_saldiri)
{
    *toplam_insan_saldiri = kritik_vurus_hesapla(&HU->piyadeler , adim) + 
                            kritik_vurus_hesapla(&HU->okcular , adim) + 
                            kritik_vurus_hesapla(&HU->suvariler , adim) + 
                            kritik_vurus_hesapla(&HU->kusatma_makineleri , adim) ;

    
    *toplam_ork_saldiri =   kritik_vurus_hesapla(&OU->ork_dovusculeri , adim) +
                            kritik_vurus_hesapla(&OU->mizrakcilar , adim) +
                            kritik_vurus_hesapla(&OU->varg_binicileri , adim) +
                            kritik_vurus_hesapla(&OU->troller , adim);
   
}
