void parse_hero_json(const char *filename, Human_Hero *HH, Ork_Hero *OH)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char bonus_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Alparslan\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->alparslan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->alparslan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->alparslan.aciklama);
            
        }
        if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->fsm.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->fsm.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->fsm.aciklama);
            
        }
        if (strstr(line, "\"Mete_Han\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->metehan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->metehan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->metehan.aciklama);
            
        }
        if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->yss.bonus_turu);            
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->yss.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->yss.aciklama);
        }
        if (strstr(line, "\"Tugrul_Bey\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->tugrul_bey.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->tugrul_bey.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->tugrul_bey.aciklama);
            
        }
        if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->goruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->goruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->goruk.aciklama);
            
        }
        if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->thruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->thruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->thruk.aciklama);
            
        }
        if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->vrog.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->vrog.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->vrog.aciklama);
            
        }
        if (strstr(line, "\"Ugar_Zalim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->ugar.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->ugar.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->ugar.aciklama);
            
        }
    }    
    fclose(file);
}