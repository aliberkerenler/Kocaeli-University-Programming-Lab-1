void parse_scenario_file(FILE *file, Human_Unit *HU, Ork_Unit *OU, Human_Hero *HH, Ork_Hero *OH, Human_Creature *HC, Ork_Creature *OC, Research_Side *RS)
{
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    char line[256];
    int value;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"insan_imparatorlugu\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
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
                    HH->alparslan.sayi++;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
                {
                    HH->fsm.sayi++;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
                {
                    HH->yss.sayi++;
                }
                if (strstr(line, "\"Tugrul_Bey\"") != NULL)
                {
                    HH->tugrul_bey.sayi++;
                }
                if (strstr(line, "\"Ejderha\"") != NULL)
                {
                    HC->ejderha.sayi++;
                }
                if (strstr(line, "\"Agri_Dagi\"") != NULL)
                {
                    HC->agri_dagi.sayi++;
                }
                if (strstr(line, "\"Tepegoz\"") != NULL)
                {
                    HC->tepegoz.sayi++;
                }
                if (strstr(line, "\"Karakurt\"") != NULL)
                {
                    HC->karakurt.sayi++;
                }
                if (strstr(line, "\"Samur\"") != NULL) 
                {
                    HC->samur.sayi++;
                }
                if (strstr(line, "savunma_ustaligi") != NULL)
                {
                    sscanf(line, " \"savunma_ustaligi\" : %d,", &value);
                
                    if (value == 1)
                    {
                        RS->Human_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Human_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Human_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi") != NULL)
                {
                    sscanf(line, " \"saldiri_gelistirmesi\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Human_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Human_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Human_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"elit_egitim\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Human_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Human_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Human_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"kusatma_ustaligi\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Human_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Human_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Human_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
        
        if (strstr(line, "\"ork_legi\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
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
                if (strstr(line, "\"Troll\"") != NULL)
                {
                    OC->troll.sayi++;
                }
                if (strstr(line, "\"Golge\"") != NULL)
                {
                    OC->golge.sayi++;
                }
                if (strstr(line, "\"Camur\"") != NULL)
                {
                    OC->camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\"") != NULL)
                {
                    OC->ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devi\"") != NULL)
                {
                    OC->buz_devi.sayi++;
                }
                if (strstr(line, "savunma_ustaligi") != NULL)
                {
                    sscanf(line, " \"savunma_ustaligi\" : %d,", &value);
                
                    if (value == 1)
                    {
                        RS->Ork_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Ork_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Ork_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi") != NULL)
                {
                    sscanf(line, " \"saldiri_gelistirmesi\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Ork_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Ork_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Ork_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"elit_egitim\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Ork_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Ork_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Ork_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"kusatma_ustaligi\" : %d,", &value);
                    if (value == 1)
                    {
                        RS->Ork_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        RS->Ork_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        RS->Ork_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }

    }
    fclose(file);
}