#include "funtzioak.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 500

//----------------------------------------------------------------
#define SPRITE_PLAYER_ARRIBIZQ ".\\IMG\\personajes\\mario\\mario_bizkarrez3.bmp"
#define SPRITE_PLAYER_ABAJOIZQ ".\\IMG\\personajes\\mario\\mario3.bmp"
#define SPRITE_PLAYER_IZQIZQ ".\\IMG\\personajes\\mario\\mario_left_0.bmp"
#define SPRITE_PLAYER_DERIZQ ".\\IMG\\personajes\\mario\\mario_right_1.bmp"
#define SPRITE_PLAYER_ARRIBDER ".\\IMG\\personajes\\mario\\mario_bizkarrez2.bmp"
#define SPRITE_PLAYER_ABAJODER ".\\IMG\\personajes\\mario\\mario2.bmp"
#define SPRITE_PLAYER_IZQDER ".\\IMG\\personajes\\mario\\mario_left_1.bmp"
#define SPRITE_PLAYER_DERDER ".\\IMG\\personajes\\mario\\mario_right_0.bmp"
#define PLAYER_ARRIBIZQ ".\\IMG\\personajes\\luigi\\luigi_bizkarrez3.bmp"
#define PLAYER_ABAJOIZQ ".\\IMG\\personajes\\luigi\\luigi3.bmp"
#define PLAYER_IZQIZQ ".\\IMG\\personajes\\luigi\\luigi_left_0.bmp"
#define PLAYER_DERIZQ ".\\IMG\\personajes\\luigi\\luigi_right_1.bmp"
#define PLAYER_ARRIBDER ".\\IMG\\personajes\\luigi\\luigi_bizkarrez2.bmp"
#define PLAYER_ABAJODER ".\\IMG\\personajes\\luigi\\luigi2.bmp"
#define PLAYER_IZQDER ".\\IMG\\personajes\\luigi\\luigi_left_1.bmp"
#define PLAYER_DERDER ".\\IMG\\personajes\\luigi\\luigi_right_0.bmp"
#define MARIO_GELDIRIK ".\\IMG\\personajes\\mario\\mario22.bmp"
#define MARIO_GELDIRIK2 ".\\IMG\\personajes\\mario\\mario.bmp"
#define LUIGI_GELDIRIK ".\\IMG\\personajes\\luigi\\luigi22.bmp"
#define LUIGI_GELDIRIK2 ".\\IMG\\personajes\\luigi\\luigi.bmp"
#define MARIO_SALTO ".\\IMG\\personajes\\mario\\mario_salto.bmp"
#define LUIGI_SALTO ".\\IMG\\personajes\\luigi\\luigi_salto.bmp"

//------------------------------------------------------------------

#define PERTSONAIA_MENUA ".\\IMG\\menus\\aukeratu_personajea.bmp"
#define PERTSONAIA_AUKERATU_MARIO ".\\IMG\\menus\\aukeratu_personajea_mario.bmp"
#define PERTSONAIA_AUKERATU_LUIGI ".\\IMG\\menus\\aukeratu_personajea_luigi.bmp"
#define LEHENENGO_PANTAILA_MARIO ".\\IMG\\galderak\\lehenengoa_mario.bmp"
#define LEHENENGO_PANTAILA_LUIGI ".\\IMG\\galderak\\lehenengoa_luigi.bmp"
#define LEHENENGO_PANTAILA2 ".\\IMG\\galderak\\bigarrena.bmp"
#define LEHENENGO_NIBELA ".\\IMG\\nibelak\\nibel1.bmp"
#define BIGARREN_NIBELA ".\\IMG\\nibelak\\nibel2.bmp"
#define HIRUGARREN_NIBELA ".\\IMG\\nibelak\\nibel3.bmp"
#define PAUSE ".\\IMG\\menus\\pause.bmp"
#define MENU ".\\IMG\\menus\\hasiera0.bmp"
#define MENUMUTE ".\\IMG\\menus\\hasieraisilik0.bmp"
#define MUNDUA ".\\IMG\\menus\\mundo.bmp"
#define KREDITOAK ".\\IMG\\menus\\kredituak0.bmp"
#define KONTROLAK ".\\IMG\\menus\\kontrolak0.bmp"
#define KARGATU ".\\IMG\\menus\\kargatuPartida.bmp"
#define MUNDU_FINALA ".\\IMG\\menus\\azken_pantaila.bmp"//azken_pantaila

//------------------------------------------------------------------

#define LEHENENGO_GALDERA ".\\IMG\\galderak\\galdera1.bmp"
#define BIGARREN_GALDERA ".\\IMG\\galderak\\galdera2.bmp"
#define HIRUGARREN_GALDERA ".\\IMG\\galderak\\galdera3.bmp"
#define GALDERA_ZUZENA ".\\IMG\\galderak\\erantzun_zuzena.bmp"
#define GALDERA_OKERRA ".\\IMG\\galderak\\erantzun_okerra.bmp"


typedef struct
{
    int id;
    SDL_Surface* imagen;
    SDL_Texture* texture;
    SDL_Rect dest;
}IMG;

int irudiaSortu(char* imgName);
int irudiaKargatu(char* fileName);
void irudiaKendu(int id);
int irudiarenPosizioaAurkitu(int id);
void pantailaGarbitu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu();
#endif