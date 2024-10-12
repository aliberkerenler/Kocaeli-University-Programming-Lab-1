void parse_research_json(const char *filename, Research *R)
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
            sscanf(line, " \"deger\" : \"%d\",", &R->savunma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->savunma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->savunma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->savunma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->savunma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->savunma_ustaligi.seviye_3.aciklama);
        }
        if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->saldiri_gelistirmesi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->saldiri_gelistirmesi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->saldiri_gelistirmesi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->saldiri_gelistirmesi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->saldiri_gelistirmesi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->saldiri_gelistirmesi.seviye_3.aciklama);
        }
        if (strstr(line, "\"elit_egitim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->elit_egitim.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->elit_egitim.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\": \"%d\",", &R->elit_egitim.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->elit_egitim.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->elit_egitim.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->elit_egitim.seviye_3.aciklama);
        }
        if (strstr(line, "\"kusatma_ustaligi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->kusatma_ustaligi.seviye_1.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->kusatma_ustaligi.seviye_1.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->kusatma_ustaligi.seviye_2.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->kusatma_ustaligi.seviye_2.aciklama);

            fgets(line, sizeof(line), file);
            sscanf(line, " \"deger\" : \"%d\",", &R->kusatma_ustaligi.seviye_3.deger);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\"", &R->kusatma_ustaligi.seviye_3.aciklama);
        }
    }
    fclose(file);
}