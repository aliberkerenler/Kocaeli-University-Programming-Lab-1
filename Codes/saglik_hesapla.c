void saglik_hesapla(Human_Unit *HU, Ork_Unit *OU, int net_hasar_insan, int net_hasar_ork, int *toplam_insan_savunma, int *toplam_ork_savunma) {
   // Oran Hesaplama
    double oran_piyadeler = (double)(HU->piyadeler.savunma * HU->piyadeler.sayi) / *toplam_insan_savunma;
    double oran_okcular = (double)(HU->okcular.savunma * HU->okcular.sayi) / *toplam_insan_savunma;
    double oran_suvariler = (double)(HU->suvariler.savunma * HU->suvariler.sayi) / *toplam_insan_savunma;
    double oran_kusatma = (double)(HU->kusatma_makineleri.savunma * HU->kusatma_makineleri.sayi) / *toplam_insan_savunma;

    double oran_ork_dovusculeri = (double)(OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) / *toplam_ork_savunma;
    double oran_mizrakcilar = (double)(OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) / *toplam_ork_savunma;
    double oran_varg_binicileri = (double)(OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) / *toplam_ork_savunma;
    double oran_troller = (double)(OU->troller.savunma * OU->troller.sayi) / *toplam_ork_savunma;

    // Hasar Dağılımı
    int hasar_piyadeler = net_hasar_ork * oran_piyadeler;
    int hasar_okcular = net_hasar_ork * oran_okcular;
    int hasar_suvariler = net_hasar_ork * oran_suvariler;
    int hasar_kusatma = net_hasar_ork * oran_kusatma;

    int hasar_ork_dovusculeri = net_hasar_insan * oran_ork_dovusculeri;
    int hasar_mizrakcilar = net_hasar_insan * oran_mizrakcilar;
    int hasar_varg_binicileri = net_hasar_insan * oran_varg_binicileri;
    int hasar_troller = net_hasar_insan * oran_troller;

    // Sağlık Güncelleme
    HU->piyadeler.saglik -= hasar_piyadeler;
    HU->okcular.saglik -= hasar_okcular;
    HU->suvariler.saglik -= hasar_suvariler;
    HU->kusatma_makineleri.saglik -= hasar_kusatma;

    OU->ork_dovusculeri.saglik -= hasar_ork_dovusculeri;
    OU->mizrakcilar.saglik -= hasar_mizrakcilar;
    OU->varg_binicileri.saglik -= hasar_varg_binicileri;
    OU->troller.saglik -= hasar_troller;

    // Sağlık 0'ın altına düşerse, 0'da sabitle.
    if (HU->piyadeler.saglik <= 0) HU->piyadeler.saglik = 0;
    if (HU->okcular.saglik <= 0) HU->okcular.saglik = 0;
    if (HU->suvariler.saglik <= 0) HU->suvariler.saglik = 0;
    if (HU->kusatma_makineleri.saglik <= 0) HU->kusatma_makineleri.saglik = 0;

    if (OU->ork_dovusculeri.saglik <= 0) OU->ork_dovusculeri.saglik = 0;
    if (OU->mizrakcilar.saglik <= 0) OU->mizrakcilar.saglik = 0;
    if (OU->varg_binicileri.saglik <= 0) OU->varg_binicileri.saglik = 0;
    if (OU->troller.saglik <= 0) OU->troller.saglik = 0;
}