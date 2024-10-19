void ork_saglik_hesapla(Ork_Unit *OU, int net_hasar_insan, double *toplam_ork_savunma) {
   // Oran Hesaplama
    

    double oran_ork_dovusculeri = (double)(OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) / *toplam_ork_savunma;
    double oran_mizrakcilar = (double)(OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) / *toplam_ork_savunma;
    double oran_varg_binicileri = (double)(OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) / *toplam_ork_savunma;
    double oran_troller = (double)(OU->troller.savunma * OU->troller.sayi) / *toplam_ork_savunma;

    // Hasar Dağılımı
    

    int hasar_ork_dovusculeri = net_hasar_insan * oran_ork_dovusculeri;
    int hasar_mizrakcilar = net_hasar_insan * oran_mizrakcilar;
    int hasar_varg_binicileri = net_hasar_insan * oran_varg_binicileri;
    int hasar_troller = net_hasar_insan * oran_troller;


    OU->ork_dovusculeri.sayi -= (hasar_ork_dovusculeri / OU->ork_dovusculeri.saglik);
    OU->mizrakcilar.sayi -= (hasar_mizrakcilar / OU->mizrakcilar.saglik);
    OU->varg_binicileri.sayi -= (hasar_varg_binicileri / OU->varg_binicileri.saglik);
    OU->troller.sayi -= (hasar_troller / OU->troller.saglik);

    // Sağlık 0'ın altına düşerse, 0'da sabitle.
    
    if (OU->ork_dovusculeri.sayi <= 0) OU->ork_dovusculeri.sayi = 0;
    if (OU->mizrakcilar.sayi <= 0) OU->mizrakcilar.sayi = 0;
    if (OU->varg_binicileri.sayi <= 0) OU->varg_binicileri.sayi = 0;
    if (OU->troller.sayi <= 0) OU->troller.sayi = 0;
}