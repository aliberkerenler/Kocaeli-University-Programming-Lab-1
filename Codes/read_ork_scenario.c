void read_ork_scenario(const char *filename, Ork_Unit *OU, Ork_Hero *OH, Ork_Creature *OC, Research *OR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    char line[256];
    int value = 0;
    while (fgets(line, sizeof(line), file))
    {   
        if (strstr(line, "\"ork_legi\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "insan_imparatorlugu"))
            {
                if (strstr(line, "ork_dovusculeri") != NULL)
                {
                    sscanf(line, " \"ork_dovusculeri\": %d,", &OU->ork_dovusculeri.sayi);
                }
                if (strstr(line, "mizrakcilar") != NULL)
                {
                    sscanf(line, " \"mizrakcilar\": %d,", &OU->mizrakcilar.sayi);
                }
                if (strstr(line, "varg_binicileri") != NULL)
                {
                    sscanf(line, " \"varg_binicileri\": %d,", &OU->varg_binicileri.sayi);
                }
                if (strstr(line, "troller") != NULL)
                {
                    sscanf(line, " \"troller\": %d,", &OU->troller.sayi);
                }
                if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
                {
                    OH->goruk.sayi++;
                }
                if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
                {
                    OH->thruk.sayi++;
                }
                if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
                {
                    OH->vrog.sayi++;
                }
                if (strstr(line, "\"Ugar_Zalim\"") != NULL)
                {
                    OH->ugar.sayi++;
                }
                if (strstr(line, "\"Kara_Troll\"") != NULL)
                {
                    OC->troll.sayi++;
                }
                if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
                {
                    OC->golge.sayi++;
                }
                if (strstr(line, "\"Camur_Devleri\"") != NULL)
                {
                    OC->camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\"") != NULL)
                {
                    OC->ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devleri\"") != NULL)
                {
                    OC->buz_devi.sayi++;
                }
                if (strstr(line, "savunma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);               
                    if (value == 1)
                    {
                        OR->savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
    }
    fclose(file);
}