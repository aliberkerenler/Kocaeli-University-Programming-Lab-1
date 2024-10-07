#include <curl/curl.h>

const char* url_list[] =
{
    "https://yapbenzet.org.tr/1.json",
    "https://yapbenzet.org.tr/2.json",
    "https://yapbenzet.org.tr/3.json",
    "https://yapbenzet.org.tr/4.json",
    "https://yapbenzet.org.tr/5.json",
    "https://bilgisayar.kocaeli.edu.tr/1.json",
    "https://bilgisayar.kocaeli.edu.tr/2.json",
    "https://bilgisayar.kocaeli.edu.tr/3.json",
    "https://bilgisayar.kocaeli.edu.tr/4.json",
    "https://bilgisayar.kocaeli.edu.tr/5.json"
};

size_t ft_write(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

void dosya_indir(int num)
{
    CURL *curl;
    FILE *file;
    CURLcode res;

    if (num < 1 || num > 10)
	{
        printf("Gecersiz Numara! 1-10 Arasinda Bir Numara Giriniz.\n");
        return;
    }
    const char *url = url_list[num - 1];
    printf("Secilen Senaryoya Ait URL: %s\n", url);

    curl = curl_easy_init();
    if (curl)
	{
        file = fopen("senaryo.json", "wb");
        if (!file)
		{
            perror("Dosya Acilamadi!");
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ft_write);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, dosya);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
		{
            fprintf(stderr, "Dosya Indirilemedi: %s\n", curl_easy_strerror(res));
        }

        fclose(file);
        curl_easy_cleanup(curl);

        file = fopen("senaryo.json", "r"); // Dosyayı okuma modunda aç
        if (file)
        {
            parse_scenario_file(file); // Dosyayı parse et
            fclose(file); // Dosyayı kapat
        }
        else
        {
            perror("Dosya Acilamadi!");
        }
    }
}
