#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H
#include "sdlHasieratu.h"

#define MAPA_MUNDUA1 0
#define MAPA_MUNDUA2 1
#define MAPA_MUNDUA3 2
#define MAPA_NIBEL1 3
#define MAPA_NIBEL2 4
#define MAPA_NIBEL3 5
#define MAPA_FINALA 8
#define MAPA_ETXEA 6
#define MAPA_MUNDUA4 7

typedef struct
{
    float x;
    float y;

}POSIZIOA;

typedef struct
{
    float gim1;
    float gim2;
    float gim3;
    float gim4;
    float gim5;
    float bataz;
}NOTA;

typedef struct
{
    int id;
    POSIZIOA pos;
    NOTA notak;
    int mapa;
    int pertsonaia;
}PLAYER;

typedef struct
{
    POSIZIOA sartu;
    POSIZIOA irten;
}EGOERA;

typedef struct
{
    int id;
    POSIZIOA atea;
    int nota;
    EGOERA egoera;
}GYM;

PLAYER player;
int kargatuta;

void denaKargatu(GYM* gimnasioak);
int kargatuPartida(GYM* gimnasioak);
void gordePartida();
void playerHasieratu();
void galderaPuntuazioaIgo(int nota);
void gymRefresh(char* gymIMG);
void endBattle();
int ezPasa();
void erantzunaHasieratu();
int galderakBaieztatu(int zureErantzuna, int galdera);
//int startBattle(int* fighterID, int* bossID);
int galderaKargatu(int galdera);
int galderaPantailaratu(char* imgGaldera);
int battleStage();
int irudiaAurkitu(int id, int interakzioa);
void eraikinInterakzio(GYM* gimnasioHitbox);
int gimnasioakHasieratu(GYM* gimnasioHitbox);
int edifizioaIreki(GYM gimnasioHitbox[], int* id, int max);
POSIZIOA saguarenPosizioa();
int ebentoaDetektatu(int ebentoa);
int ebentuaJasoGertatuBada();
int pausaMenua();
int mapenHitboxak(int tecla);
int beheruntzAnimazioa(int boo);
int ezkerreruntzAnimazioa(int boo);
int gorunztAnimazioa(int boo);
int eskubiruntzAnimazioa(int boo);
int saltoAnimazioa(int boo);

SDL_Rect set_camera(SDL_Rect camera);
extern SDL_Rect camera;

#endif
