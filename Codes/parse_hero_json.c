void parse_hero_json(const char* filename)
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
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Human_Hero.alparslan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Human_Hero.alparslan.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Human_Hero.alparslan.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Human_Hero.fsm.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Human_Hero.fsm.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Human_Hero.fsm.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Human_Hero.yss.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Human_Hero.yss.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Human_Hero.yss.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Tugrul_Bey\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Human_Hero.tugrul_bey.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Human_Hero.tugrul_bey.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Human_Hero.tugrul_bey.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Ork_Hero.goruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Ork_Hero.goruk.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Ork_Hero.goruk.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Ork_Hero.thruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Ork_Hero.thruk.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Ork_Hero.thruk.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Ork_Hero.vrog.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Ork_Hero.vrog.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Ork_Hero.vrog.bonus_degeri = atoi(bonus_str);
        }
        else if (strstr(line, "\"Ugar_Zalim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\": \"%[^\"]\",", &Ork_Hero.ugar.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etkiledigi_birim\": \"%[^\"]\",", &Ork_Hero.ugar.etkiledigi_birim);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\": \"%[^\"]\",", bonus_str);
            Ork_Hero.ugar.bonus_degeri = atoi(bonus_str);
        }
    }    
    fclose(file);
}