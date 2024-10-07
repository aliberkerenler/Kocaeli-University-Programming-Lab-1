void parse_skill_json(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"savunma_ustaligi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &savunma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", savunma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &savunma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", savunma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &savunma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", savunma_ustaligi.seviye_3.aciklama);
        }
        else if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &saldiri_gelistirmesi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", saldiri_gelistirmesi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &saldiri_gelistirmesi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", saldiri_gelistirmesi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &saldiri_gelistirmesi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", saldiri_gelistirmesi.seviye_3.aciklama);
        }
        else if (strstr(line, "\"elit_egitim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &elit_egitim.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", elit_egitim.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &elit_egitim.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", elit_egitim.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &elit_egitim.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", elit_egitim.seviye_3.aciklama);
        }
        else if (strstr(line, "\"kusatma_ustaligi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &kusatma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", kusatma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &kusatma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", kusatma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &kusatma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\": \"%[^\"]\"", kusatma_ustaligi.seviye_3.aciklama);
        }
    }

    fclose(file);
}