void add_bonus_value(Human_Unit *HU, Ork_Unit *OU, Human_Hero *HH, Ork_Hero *OH, Human_Creature *HC, Ork_Creature *OC, Research *HR, Research *OR)
{
	if (HH->alparslan.sayi == 1)
    {
        HU->piyadeler.savunma *= 1.2; 
    }
    
    if (HH->fsm.sayi == 1)
    {
        HU->kusatma_makineleri.saldiri *= 1.25;
    }
    
    if (HH->metehan.sayi == 1)
    {
        HU->okcular.savunma *= 1.2;
    }
    
    if(HH->yss.sayi == 1)
    {
        HU->suvariler.kritik_sans = 15;
    }
    
    if(HH->tugrul_bey.sayi == 1)
    {
        HU->okcular.saldiri *= 1.2;
    }
    
    if(OH->goruk.sayi == 1)
    {
        OU->ork_dovusculeri.saldiri *= 1.2;
    }
    
    if(OH->thruk.sayi == 1)
    {
        OU->troller.savunma *= 1.25;
    }
    
    if(OH->vrog.sayi == 1)
    {
        OU->varg_binicileri.kritik_sans = 15;
    }

    if (OH->ugar.sayi == 1)
    {
        OU->mizrakcilar.savunma *= 1.1;
        OU->ork_dovusculeri.savunma *= 1.1;
        OU->troller.savunma *= 1.1;
        OU->varg_binicileri.savunma *= 1.1;
    }

    if(HC->ejderha.sayi == 1)
    {    
        HU->piyadeler.saldiri *= 1.15;
    }

    if(HC->agri_dagi.sayi == 1)
    {
        HU->suvariler.savunma *=1.2;
    }

    if(HC->tepegoz.sayi == 1)
    {    
        HU->okcular.saldiri *= 1.25;

    }

    if(HC->karakurt.sayi == 1)
    {
        HU->okcular.kritik_sans = 10;
    }

    if(HC->samur.sayi == 1)
    {
        HU->piyadeler.savunma *= 1.1;
    }
    
    if(OC->troll.sayi == 1)
    {
        OU->troller.saldiri *= 1.2;
    }
    
    if(OC->golge.sayi == 1)
    {    
        OU->varg_binicileri.savunma *= 1.15;
    }

    if(OC->camur.sayi == 1) 
    {
        OU->ork_dovusculeri.savunma *= 1.25;
    }
    
    if(OC->ates_iblisi.sayi == 1)
    {
        OU->varg_binicileri.saldiri *= 1.3;
    }
    
    if(OC->makrog.sayi == 1)
    {
        OU->troller.savunma *= 1.25;
    }   
    
    if(OC->buz_devi.sayi == 1)
    {
        OU->mizrakcilar.savunma *= 1.15;
    }

    if (HR->savunma_ustaligi.seviye_1.sayi == 1)
    {
        HU->piyadeler.savunma *= 1.1;
        HU->okcular.savunma *= 1.1;
        HU->suvariler.savunma *= 1.1;
        HU->kusatma_makineleri.savunma *= 1.1;
    }
    if (HR->savunma_ustaligi.seviye_2.sayi == 1)
    {
        HU->piyadeler.savunma *= 1.2;
        HU->okcular.savunma *= 1.2;
        HU->suvariler.savunma *= 1.2;
        HU->kusatma_makineleri.savunma *= 1.2;
    }
    if (HR->savunma_ustaligi.seviye_3.sayi == 1)
    {
        HU->piyadeler.savunma *= 1.3;
        HU->okcular.savunma *= 1.3;
        HU->suvariler.savunma *= 1.3;
        HU->kusatma_makineleri.savunma *= 1.3;
    }

    if(HR->saldiri_gelistirmesi.seviye_1.sayi == 1)
    {
        HU->piyadeler.saldiri *=1.1;
        HU->okcular.saldiri *=1.1;
        HU->suvariler.saldiri *=1.1;
        HU->kusatma_makineleri.saldiri *= 1.1;
    }
    
    if(HR->saldiri_gelistirmesi.seviye_2.sayi == 1)
    {
        HU->piyadeler.saldiri *=1.2;
        HU->okcular.saldiri *=1.2;
        HU->suvariler.saldiri *=1.2;
        HU->kusatma_makineleri.saldiri *= 1.1;
    }

    if(HR->saldiri_gelistirmesi.seviye_3.sayi == 1)
    {
        HU->piyadeler.saldiri *=1.3;
        HU->okcular.saldiri *=1.3;
        HU->suvariler.saldiri *=1.3;
        HU->kusatma_makineleri.saldiri *= 1.3;
    }

    if(HR->elit_egitim.seviye_1.sayi)
    {
        HU->piyadeler.kritik_sans = 5;
        HU->okcular.kritik_sans = 5;
        HU->suvariler.kritik_sans = 5;
        HU->kusatma_makineleri.kritik_sans = 5;
    }

    if(HR->kusatma_ustaligi.seviye_1.sayi == 1)
    {
       HU->kusatma_makineleri.saldiri *= 1.1;
    }

    if(HR->kusatma_ustaligi.seviye_2.sayi == 1)
    {
       HU->kusatma_makineleri.saldiri *= 1.2;
    }

    if(HR->kusatma_ustaligi.seviye_3.sayi == 1)
    {
       HU->kusatma_makineleri.saldiri *= 1.3;
    }
    
    if (OR->savunma_ustaligi.seviye_1.sayi == 1)
    {
        OU->ork_dovusculeri.savunma *= 1.1;
        OU->mizrakcilar.savunma *= 1.1;
        OU->varg_binicileri.savunma *= 1.1;
        OU->troller.savunma *= 1.1;
    }
    if (OR->savunma_ustaligi.seviye_2.sayi == 1)
    {
        OU->ork_dovusculeri.savunma *= 1.2;
        OU->mizrakcilar.savunma *= 1.2;
        OU->varg_binicileri.savunma *= 1.2;
        OU->troller.savunma *= 1.2;
    }
    if (OR->savunma_ustaligi.seviye_3.sayi == 1)
    {
        OU->ork_dovusculeri.savunma *= 1.3;
        OU->mizrakcilar.savunma *= 1.3;
        OU->varg_binicileri.savunma *= 1.3;
        OU->troller.savunma *= 1.3;
    }

    if(HR->saldiri_gelistirmesi.seviye_1.sayi == 1)
    {
        OU->ork_dovusculeri.saldiri *=1.1;
        OU->mizrakcilar.saldiri *=1.1;
        OU->varg_binicileri.saldiri *=1.1;
        OU->troller.saldiri *= 1.1;
    }
    
    if(HR->saldiri_gelistirmesi.seviye_2.sayi == 1)
    {
        OU->ork_dovusculeri.saldiri *=1.2;
        OU->mizrakcilar.saldiri *=1.2;
        OU->varg_binicileri.saldiri *=1.2;
        OU->troller.saldiri *= 1.1;
    }

    if(HR->saldiri_gelistirmesi.seviye_3.sayi == 1)
    {
        OU->ork_dovusculeri.saldiri *=1.3;
        OU->mizrakcilar.saldiri *=1.3;
        OU->varg_binicileri.saldiri *=1.3;
        OU->troller.saldiri *= 1.3;
    }

    if(OR->elit_egitim.seviye_1.sayi)
    {
        OU->ork_dovusculeri.kritik_sans = 5;
        OU->mizrakcilar.kritik_sans = 5;
        OU->varg_binicileri.kritik_sans = 5;
        OU->troller.kritik_sans = 5;
    }

    if(OR->elit_egitim.seviye_2.sayi == 1)
    {
        OU->ork_dovusculeri.kritik_sans = 10;
        OU->mizrakcilar.kritik_sans = 10;
        OU->varg_binicileri.kritik_sans = 10;
        OU->troller.kritik_sans = 10;
    }

    if(OR->elit_egitim.seviye_3.sayi == 1)
    {
        OU->ork_dovusculeri.kritik_sans = 15;
        OU->mizrakcilar.kritik_sans = 15;
        OU->varg_binicileri.kritik_sans = 15;
        OU->troller.kritik_sans = 15;
    }    
}