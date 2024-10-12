void parse_research_json(const char *filename, Research *HR, Research *OR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    Research_Type *current_research_type = NULL;
    Seviye *current_level = NULL;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"savunma_ustaligi\""))
        {
            current_research_type = &HR->savunma_ustaligi;
        }
        else if (strstr(line, "\"saldiri_gelistirmesi\""))
        {
            current_research_type = &HR->saldiri_gelistirmesi;
        }
        else if (strstr(line, "\"elit_egitim\""))
        {
            current_research_type = &HR->elit_egitim;
        }
        else if (strstr(line, "\"kusatma_ustaligi\""))
        {
            current_research_type = &HR->kusatma_ustaligi;
        }
        else if (strstr(line, "\"deger\""))
        {
            if (current_level)
            {
                sscanf(line, " \"deger\": \"%d\"", &current_level->deger);
            }
        }
        else if (strstr(line, "\"aciklama\""))
        {
            if (current_level)
            {
                char *start = strchr(line, ':') + 3;
                strncpy(current_level->aciklama, start, strlen(start) - 2);
                current_level->aciklama[strlen(start) - 2] = '\0';
            }
        }
        else if (strstr(line, "\"seviye_1\""))
        {
            current_level = &current_research_type->seviye_1;
        }
        else if (strstr(line, "\"seviye_2\""))
        {
            current_level = &current_research_type->seviye_2;
        }
        else if (strstr(line, "\"seviye_3\""))
        {
            current_level = &current_research_type->seviye_3;
        }
    }

    fclose(file);

    // OR için verileri kopyalama
    memcpy(&OR->savunma_ustaligi, &HR->savunma_ustaligi, sizeof(Research_Type));
    memcpy(&OR->saldiri_gelistirmesi, &HR->saldiri_gelistirmesi, sizeof(Research_Type));
    memcpy(&OR->elit_egitim, &HR->elit_egitim, sizeof(Research_Type));
    memcpy(&OR->kusatma_ustaligi, &HR->kusatma_ustaligi, sizeof(Research_Type));
}