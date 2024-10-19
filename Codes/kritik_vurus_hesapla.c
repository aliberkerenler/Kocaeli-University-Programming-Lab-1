int kritik_vurus_hesapla(Unit *unit, int adim)
{
    // Birimin kritik vuruş zamanını hesapla
    if (adim % (100 / unit->kritik_sans) == 0)
    { 
        return unit->saldiri * unit->sayi * 1.5; // Kritik vuruş varsa hasarı artır
    }

    return unit->saldiri * unit->sayi; // Kritik vuruş yoksa normal hasar
}