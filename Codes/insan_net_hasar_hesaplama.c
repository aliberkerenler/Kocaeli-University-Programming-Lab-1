int insan_net_hasar_hesaplama(Human_Unit *HU, int *toplam_insan_saldiri, int *toplam_insan_savunma, int *toplam_ork_savunma)
{
    int insan_net_hasar = *toplam_insan_saldiri * (1 - (*toplam_ork_savunma / *toplam_insan_saldiri));
    if (insan_net_hasar < 0)
        insan_net_hasar = 0;
    return (insan_net_hasar);
}