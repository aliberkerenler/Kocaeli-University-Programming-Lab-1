#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global değişkenler
Human_Unit Human_Unit;
Ork_Unit Ork_Unit;
Human_Hero Human_Hero;
Ork_Hero Ork_Hero;
Human_Creature Human_Creature;
Ork_Creature Ork_Creature;
Research_Side Research_Side;

// Fonksiyon prototipleri
void parse_unit_json(const char *filename);
void parse_hero_json(const char *filename);
void parse_creature_json(const char *filename);
void parse_research_json(const char *filename);
void parse_scenario_file(FILE *file);

int main() {
    // JSON dosyalarını analiz etme
    parse_unit_json("unit_types.json");
    parse_hero_json("heroes.json");
    parse_creature_json("creatures.json");
    parse_research_json("research.json");

    // Senaryo dosyasını açma ve analiz etme
    FILE *file = fopen("scenario.json", "r");
    parse_scenario_file(file);

    // Burada, doldurulan verileri kullanarak işlemler yapabilirsin.
    // Örneğin, İnsan birimlerinin sayılarını yazdırma
    printf("İnsan Birimleri:\n");
    printf("Piyadeler: %d\n", Human_Unit.piyadeler.sayi);
    printf("Okçular: %d\n", Human_Unit.okcular.sayi);
    printf("Süvariler: %d\n", Human_Unit.suvariler.sayi);
    printf("Kuşatma Makineleri: %d\n", Human_Unit.kusatma_makineleri.sayi);

    // Ork birimlerinin sayılarını yazdırma
    printf("\nOrk Birimleri:\n");
    printf("Ork Dövüşçüleri: %d\n", Ork_Unit.ork_dovusculeri.sayi);
    printf("Mızrakçılar: %d\n", Ork_Unit.mizrakcilar.sayi);
    printf("Varg Binicileri: %d\n", Ork_Unit.varg_binicileri.sayi);
    printf("Troller: %d\n", Ork_Unit.troller.sayi);

    // Belleği temizle ve çık
    fclose(file);
    return 0;
}