void parse_hero_json(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char etki_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Ejderha\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Human_Creature.ejderha.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Human_Creature.ejderha.etki_turu);
            
        }
        else if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Human_Creature.agri_dagi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Human_Creature.agri_dagi.etki_turu);
            
        }
        else if (strstr(line, "\"Tepegoz\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Human_Creature.tepegoz.etki_degeri = atoi(etki_str)
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Human_Creature.tepegoz.etki_turu);
            ;
        }
        else if (strstr(line, "\"Karakurt\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Human_Creature.karakurt.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Human_Creature.karakurt.etki_turu);
            
        }
        else if (strstr(line, "\"Samur\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Human_Creature.samur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Human_Creature.samur.etki_turu);
            
        }
        else if (strstr(line, "\"Kara_Troll\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Ork_Creature.troll.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Ork_Creature.troll.etki_turu);
            
        }
        else if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Ork_Creature.golge.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Ork_Creature.golge.etki_turu);
            
        }
        else if (strstr(line, "\"Camur_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Ork_Creature.camur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Ork_Creature.camur.etki_turu);
            
        }
        else if (strstr(line, "\"Ates_Iblisi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Ork_Creature.ates_iblisi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Ork_Creature.ates_iblisi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Ork_Hero.ugar.etkiledigi_birim);
            
        }
        else if (strstr(line, "\"Buz_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\": \"%[^\"]\",", etki_str);
            Ork_Creature.buz_devi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\": \"%[^\"]\",", &Ork_Creature.buz_devi.etki_turu);
            
        }
    }    
    fclose(file);
}