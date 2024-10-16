int ork_net_hasar_hesaplama(Ork_Unit *OU, int *toplam_ork_saldiri, int *toplam_ork_savunma, int *toplam_insan_savunma)
{
    int ork_net_hasar = *toplam_ork_saldiri * (1 - (*toplam_insan_savunma / *toplam_ork_saldiri));
    if (ork_net_hasar < 0)
        ork_net_hasar = 0;
    return (ork_net_hasar);
}