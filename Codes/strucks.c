typedef struct {
    int saldiri;
    int savunma;
    int saglik;
    int kritik_sans;
    int sayi;
} Unit;

typedef struct {
    Unit piyadeler;
    Unit okcular;
    Unit suvariler;
    Unit kusatma_makineleri;
} Human_Unit;

typedef struct {
    Unit ork_dovusculeri;
    Unit mizrakcilar;
    Unit varg_binicileri;
    Unit troller;
} Ork_Unit;

typedef struct {
    char bonus_turu[50];
    char aciklama[256];
    int bonus_degeri;
    int sayi;
} Hero;

typedef struct {
    Hero alparslan;
    Hero fsm;
    Hero metehan;
    Hero yss;
    Hero tugrul_bey;
} Human_Hero;

typedef struct {
    Hero goruk;
    Hero thruk;
    Hero vrog;
    Hero ugar;
} Ork_Hero;

typedef struct {
    int etki_degeri;
    char etki_turu[50];
    char aciklama[256];
    int sayi;
} Creature;

typedef struct {
    Creature ejderha;
    Creature agri_dagi;
    Creature tepegoz;
    Creature karakurt;
    Creature samur;
} Human_Creature;

typedef struct {
    Creature troll;
    Creature golge;
    Creature camur;
    Creature ates_iblisi;
    Creature makrog;
    Creature buz_devi;
} Ork_Creature;

typedef struct {
    int deger;
    char aciklama[100];
    int sayi;
} Seviye;

typedef struct {
    Seviye seviye_1;
    Seviye seviye_2;
    Seviye seviye_3;
} Research_Type;

typedef struct {
    Research_Type savunma_ustaligi;
    Research_Type saldiri_gelistirmesi;
    Research_Type elit_egitim;
    Research_Type kusatma_ustaligi;
} Research;
