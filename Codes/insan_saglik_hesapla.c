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
