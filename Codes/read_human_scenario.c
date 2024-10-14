void read_human_scenario(const char *filename, Human_Unit *HU, Human_Hero *HH, Human_Creature *HC, Research *HR)
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
        if (strstr(line, "\"insan_imparatorlugu\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "ork_legi"))
            {
                if (strstr(line, "\"piyadeler\"") != NULL)
                {
                    sscanf(line, " \"piyadeler\": %d,", &HU->piyadeler.sayi);
                }
                if (strstr(line, "okcular") != NULL)
                {
                    sscanf(line, " \"okcular\": %d,", &HU->okcular.sayi);
                }
                if (strstr(line, "suvariler") != NULL)
                {
                    sscanf(line, " \"suvariler\": %d,", &HU->suvariler.sayi);
                }
                if (strstr(line, "kusatma_makineleri") != NULL)
                {
                    sscanf(line, " \"kusatma_makineleri\": %d,", &HU->kusatma_makineleri.sayi);
                }
                if (strstr(line, "\"Alparslan\"") != NULL)
                {
                    HH->alparslan.sayi = 1;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
                {
                    HH->fsm.sayi = 1;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
                {
                    HH->yss.sayi = 1;
                }
                if (strstr(line, "\"Tugrul_Bey\"") != NULL)
                {
                    HH->tugrul_bey.sayi = 1;
                }
                if (strstr(line, "\"Ejderha\"") != NULL)
                {
                    HC->ejderha.sayi = 1;
                }
                if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
                {
                    HC->agri_dagi.sayi = 1;
                }
                if (strstr(line, "\"Tepegoz\"") != NULL)
                {
                    HC->tepegoz.sayi = 1;
                }
                if (strstr(line, "\"Karakurt\"") != NULL)
                {
                    HC->karakurt.sayi = 1;
                }
                if (strstr(line, "\"Samur\"") != NULL) 
                {
                    HC->samur.sayi = 1;
                }
                if (strstr(line, "\"savunma_ustaligi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->savunma_ustaligi.seviye_1.sayi = 1;
                    }
                    else if (value == 2)
                    {
                        HR->savunma_ustaligi.seviye_2.sayi = 1;
                    }
                    else if (value == 3)
                    {
                        HR->savunma_ustaligi.seviye_3.sayi = 1;
                    }
                }
                if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
    }
    fclose(file);
}