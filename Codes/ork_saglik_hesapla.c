void ork_saglik_hesapla(Ork_Unit *OU, double net_hasar_insan, double *toplam_ork_savunma)
{
   // Oran Hesaplama


    double oran_ork_dovusculeri = (double)(OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) / *toplam_ork_savunma;
    double oran_mizrakcilar = (double)(OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) / *toplam_ork_savunma;
    double oran_varg_binicileri = (double)(OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) / *toplam_ork_savunma;
    double oran_troller = (double)(OU->troller.savunma * OU->troller.sayi) / *toplam_ork_savunma;

    // Hasar Dağılımı


    double hasar_ork_dovusculeri = net_hasar_insan * oran_ork_dovusculeri;
    double hasar_mizrakcilar = net_hasar_insan * oran_mizrakcilar;
    double hasar_varg_binicileri = net_hasar_insan * oran_varg_binicileri;
    double hasar_troller = net_hasar_insan * oran_troller;

    OU->ork_dovusculeri.saglik -= (hasar_ork_dovusculeri / OU->ork_dovusculeri.sayi);
    OU->mizrakcilar.saglik -= (hasar_mizrakcilar / OU->mizrakcilar.sayi);
    OU->varg_binicileri.saglik -= (hasar_varg_binicileri / OU->varg_binicileri.sayi);
    OU->troller.saglik -= (hasar_troller / OU->troller.sayi);

    // Sağlık 0'ın altına düşerse, 0'da sabitle.

	if (OU->ork_dovusculeri.saglik <= 0) OU->ork_dovusculeri.saglik = 0;
    if (OU->mizrakcilar.saglik <= 0) OU->mizrakcilar.saglik = 0;
    if (OU->varg_binicileri.saglik <= 0) OU->varg_binicileri.saglik = 0;
    if (OU->troller.saglik <= 0) OU->troller.saglik = 0;

    if (OU->ork_dovusculeri.saglik <= 0) OU->ork_dovusculeri.sayi = 0;
    if (OU->mizrakcilar.saglik <= 0) OU->mizrakcilar.sayi = 0;
    if (OU->varg_binicileri.saglik <= 0) OU->varg_binicileri.sayi = 0;
    if (OU->troller.saglik <= 0) OU->troller.sayi = 0;
}

void insan_saglik_hesapla(Human_Unit *HU, double net_hasar_ork, double *toplam_insan_savunma)
{
    //Oran hesaplama(insan)
	double oran_piyadeler = (double)(HU->piyadeler.savunma * HU->piyadeler.sayi) / *toplam_insan_savunma;
    double oran_okcular = (double)(HU->okcular.savunma * HU->okcular.sayi) / *toplam_insan_savunma;
    double oran_suvariler = (double)(HU->suvariler.savunma * HU->suvariler.sayi) / *toplam_insan_savunma;
    double oran_kusatma = (double)(HU->kusatma_makineleri.savunma * HU->kusatma_makineleri.sayi) / *toplam_insan_savunma;

    //Hasar Dagilimi(insan)
	double hasar_piyadeler = net_hasar_ork * oran_piyadeler;
    double hasar_okcular = net_hasar_ork * oran_okcular;
    double hasar_suvariler = net_hasar_ork * oran_suvariler;
    double hasar_kusatma = net_hasar_ork * oran_kusatma;

	// Sayi Guncelleme(insan)
    HU->piyadeler.saglik -= hasar_piyadeler / HU->piyadeler.saglik;
    HU->okcular.saglik -= hasar_okcular / HU->okcular.saglik;
    HU->suvariler.saglik -= hasar_suvariler / HU->suvariler.saglik;
    HU->kusatma_makineleri.saglik -= hasar_kusatma / HU->kusatma_makineleri.saglik;

    // sayi 0'in altina duserse, 0'da sabitle.(insan)
	if (HU->piyadeler.saglik <= 0) HU->piyadeler.saglik = 0;
    if (HU->okcular.saglik <= 0) HU->okcular.saglik = 0;
    if (HU->suvariler.saglik<= 0) HU->suvariler.saglik = 0;
    if (HU->kusatma_makineleri.saglik <= 0) HU->kusatma_makineleri.saglik = 0;

    if (HU->piyadeler.saglik <= 0) HU->piyadeler.sayi = 0;
    if (HU->okcular.saglik <= 0) HU->okcular.sayi = 0;
    if (HU->suvariler.saglik<= 0) HU->suvariler.sayi = 0;
    if (HU->kusatma_makineleri.saglik <= 0) HU->kusatma_makineleri.sayi = 0;

}
