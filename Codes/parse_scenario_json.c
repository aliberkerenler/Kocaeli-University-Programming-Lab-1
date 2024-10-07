void parse_scenario_file(FILE *file)
{
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "piyadeler"))
        {
            sscanf(line, " \"piyadeler\": %d,", &Human_Unit.piyadeler.sayi);
        }
        if (strstr(line, "okcular"))
        {
            sscanf(line, " \"okcular\": %d,", &Human_Unit.okcular.sayi);
        }
        if (strstr(line, "suvariler"))
        {
            sscanf(line, " \"suvariler\": %d,", &Human_Unit.suvariler.sayi);
        }
        if (strstr(line, "kusatma_makineleri"))
        {
            sscanf(line, " \"kusatma_makineleri\": %d,", &Human_Unit.kusatma_makineleri.sayi);
        }
        if (strstr(line, "ork_dovusculeri"))
        {
            sscanf(line, " \"ork_dovusculeri\": %d,", &Ork_Unit.ork_dovusculeri.sayi);
        }
        if (strstr(line, "mizrakcilar"))
        {
            sscanf(line, " \"mizrakcilar\": %d,", &Ork_Unit.mizrakcilar.sayi);
        }
        if (strstr(line, "varg_binicileri"))
        {
            sscanf(line, " \"varg_binicileri\": %d,", &Ork_Unit.varg_binicileri.sayi);
        }
        if (strstr(line, "troller"))
        {
            sscanf(line, " \"troller\": %d,", &Ork_Unit.troller.sayi);
        }

        if (strstr(line, "\"insan_imparatorlugu\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Alparslan\""))
                {
                    Human_Hero.alparslan.sayi++;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\""))
                {
                    Human_Hero.fsm.sayi++;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\""))
                {
                    Human_Hero.yss.sayi++;
                }
                if (strstr(line, "\"Tugrul_Bey\""))
                {
                    Human_Hero.tugrul_bey.sayi++;
                }
            }
        }

        if (strstr(line, "\"ork_legi\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Goruk_Vahsi\""))
                {
                    Ork_Hero.goruk.sayi++;
                }
                if (strstr(line, "\"Thruk_Kemikkiran\""))
                {
                    Ork_Hero.thruk.sayi++;
                }
                if (strstr(line, "\"Vrog_Kafakiran\""))
                {
                    Ork_Hero.vrog.sayi++;
                }
                if (strstr(line, "\"Ugar_Zalim\""))
                {
                    Ork_Hero.ugar.sayi++;
                }
            }
        }
            if (strstr(line, "\"canavarlar\": [")) {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Ejderha\""))
                {
                    Human_Creature.ejderha.sayi++;
                }
                if (strstr(line, "\"Agri_Dagi\""))
                {
                    Human_Creature.agri_dagi.sayi++;
                }
                if (strstr(line, "\"Tepegoz\""))
                {
                    Human_Creature.tepegoz.sayi++;
                }
                if (strstr(line, "\"Karakurt\""))
                {
                    Human_Creature.karakurt.sayi++;
                }
                if (strstr(line, "\"Samur\"")) 
                {
                    Human_Creature.samur.sayi++;
                }
            }
        }

        if (strstr(line, "\"ork_legi\": {"))
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "],"))
            {
                if (strstr(line, "\"Troll\""))
                {
                    Ork_Creature.troll.sayi++;
                }
                if (strstr(line, "\"Golge\""))
                {
                    Ork_Creature.golge.sayi++;
                }
                if (strstr(line, "\"Camur\""))
                {
                    Ork_Creature.camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\""))
                {
                    Ork_Creature.ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devi\""))
                {
                    Ork_Creature.buz_devi.sayi++;
                }
            }
        }

        int value;
        if (strstr(line, "\"insan_imparatorlugu\": {") )
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
            {
                if (strstr(line, "savunma_ustaligi"))
                {
                    sscanf(line, " \"savunma_ustaligi\": %d,", &value);
                
                    if (value == 1)
                    {
                        Research_Side.Human_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Human_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Human_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi"))
                {
                    sscanf(line, " \"saldiri_gelistirmesi\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Human_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Human_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Human_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim"))
                {
                    sscanf(line, " \"elit_egitim\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Human_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Human_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Human_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi"))
                {
                    sscanf(line, " \"kusatma_ustaligi\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Human_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Human_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Human_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
        
        if (strstr(line, "\"ork_legi\": {") )
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "},"))
            {
                if (strstr(line, "savunma_ustaligi"))
                {
                    sscanf(line, " \"savunma_ustaligi\": %d,", &value);
                
                    if (value == 1)
                    {
                        Research_Side.Ork_Research.savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Ork_Research.savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Ork_Research.savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi"))
                {
                    sscanf(line, " \"saldiri_gelistirmesi\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Ork_Research.saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Ork_Research.saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Ork_Research.saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim"))
                {
                    sscanf(line, " \"elit_egitim\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Ork_Research.elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Ork_Research.elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Ork_Research.elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi"))
                {
                    sscanf(line, " \"kusatma_ustaligi\": %d,", &value);
                    if (value == 1)
                    {
                        Research_Side.Ork_Research.kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        Research_Side.Ork_Research.kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        Research_Side.Ork_Research.kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }

    }
    fclose(file);
}