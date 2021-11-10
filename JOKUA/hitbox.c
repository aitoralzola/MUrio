#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"
#include "hitbox.h"

int galderenHitboxa()
{
    POSIZIOA saguPos;
    int ebentua = 0, erantzuna = 0;

    saguPos = saguarenPosizioa();

    //ArrIzq
    if ((saguPos.x >= 67 && saguPos.x <= 269) && (saguPos.y >= 205 && saguPos.y <= 227))
    {
        erantzuna = ERANTZUN1;
        printf("ikutu du 1\n");
    }
    //ArrDer
    if ((saguPos.x >= 291 && saguPos.x <= 493) && (saguPos.y >= 205 && saguPos.y <= 227))
    {
        erantzuna = ERANTZUN2;
        printf("ikutu du 2\n");
    }
    //AbaIzq
    if ((saguPos.x >= 67 && saguPos.x <= 269) && (saguPos.y >= 242 && saguPos.y <= 264))
    {
        erantzuna = ERANTZUN3;
        printf("ikutu du 3\n");
    }
    //AbaDer
    if ((saguPos.x >= 291 && saguPos.x <= 493) && (saguPos.y >= 242 && saguPos.y <= 264))
    {
        erantzuna = ERANTZUN4;
        printf("ikutu du 4\n");
    }

    return erantzuna;
}

int mapenHitboxak(int tecla)
{
    int baimena = 1;

    if (player.mapa == MAPA_MUNDUA1)
    {
        baimena = HITBOX_mundua(tecla);
    }
    else if (player.mapa == MAPA_MUNDUA2)
    {
        baimena = HITBOX_mundua2(tecla);
    }
    else if (player.mapa == MAPA_MUNDUA3)
    {
        baimena = HITBOX_mundua3(tecla);
    }
    else if (player.mapa == MAPA_MUNDUA4)
    {
        baimena = HITBOX_mundua4(tecla);
    }
    else if (player.mapa == MAPA_ETXEA)
    {
        baimena = HITBOX_hasieraEtxea(tecla);
    }
    else if (player.mapa == MAPA_NIBEL1)
    {
        baimena = HITBOX_nibel1(tecla);
    }
    else if (player.mapa == MAPA_NIBEL2)
    {
        baimena = HITBOX_nibel2(tecla);
    }
    else if (player.mapa == MAPA_NIBEL3)
    {
        baimena = HITBOX_nibel3(tecla);
    }
    else if (player.mapa == MAPA_FINALA)
    {
        baimena = HITBOX_finala(tecla);
    }
    return baimena;
}

int HITBOX_mundua(int tecla)
{
    int baimena = 1;

    if ((player.pos.x >= 300 && player.pos.x <= 335) && (player.pos.y >= 310) && tecla == TECLA_d)baimena = 0;
    if ((player.pos.x >= 300 && player.pos.x <= 335) && (player.pos.y >= 310) && tecla == TECLA_RIGHT)baimena = 0;

    //goiko partea
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_UP) baimena = 0;
    //hasiera behean
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 80 && player.pos.y <= 125) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 80 && player.pos.y <= 125) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 80 && player.pos.y <= 155) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 80 && player.pos.y <= 155) && tecla == TECLA_LEFT) baimena = 0;
    //ate azpikoa
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_RIGHT) baimena = 0;
    //beheko bidean parez ezkerra
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_LEFT) baimena = 0;
    //beheko bidean behean
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_DOWN) baimena = 0;
    //lehenengo bertikala
    if ((player.pos.x >= 290 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 290 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 290 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 290 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_UP) baimena = 0;
    //txanpi ondoan
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;
    //gaztelua
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_RIGHT) baimena = 0;
    //ate ondokoa
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 0 && player.pos.x <= 640 && player.pos.y >= 250) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 0 && player.pos.x <= 640 && player.pos.y >= 250) && tecla == TECLA_DOWN) baimena = 0;

    return baimena;
}

int HITBOX_mundua2(int tecla)
{
    int baimena = 1;

    if ((player.pos.x >= 300 && player.pos.x <= 335) && (player.pos.y >= 310) && tecla == TECLA_d)baimena = 0;
    if ((player.pos.x >= 300 && player.pos.x <= 335) && (player.pos.y >= 310) && tecla == TECLA_RIGHT)baimena = 0;

    //goiko partea
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_UP) baimena = 0;
    //hasiera behean
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 125) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 125) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 155) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 155) && tecla == TECLA_LEFT) baimena = 0;
    //ate azpikoa
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_RIGHT) baimena = 0;
    //beheko bidean parez ezkerra
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_LEFT) baimena = 0;
    //beheko bidean behean
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_DOWN) baimena = 0;
    //lehenengo bertikala
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_UP) baimena = 0;
    //txanpi ondoan
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;
    //gaztelua
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_RIGHT) baimena = 0;
    //ate ondokoa
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 320 && player.pos.y >= 310 && player.pos.y <= 480) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 320 && player.pos.y >= 310 && player.pos.y <= 480) && tecla == TECLA_RIGHT) baimena = 0;

    return baimena;
}

int HITBOX_mundua3(int tecla)
{
    int baimena = 1;

    //goiko partea
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 82) && tecla == TECLA_UP) baimena = 0;
    //hasiera behean
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 154 && player.pos.y <= 175) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 125) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 125) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 155) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= 235 && player.pos.x <= 275) && (player.pos.y >= 85 && player.pos.y <= 155) && tecla == TECLA_LEFT) baimena = 0;
    //ate azpikoa
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 295 && player.pos.x <= 640) && (player.pos.y >= 179 && player.pos.y <= 276) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 290 && player.pos.x <= 360) && (player.pos.y >= 173 && player.pos.y <= 276) && tecla == TECLA_RIGHT) baimena = 0;
    //beheko bidean parez ezkerra
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 135 && player.pos.y <= 274) && tecla == TECLA_LEFT) baimena = 0;
    //beheko bidean behean
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= 131 && player.pos.x <= 640) && (player.pos.y >= 206 && player.pos.y <= 264) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 170) && (player.pos.y >= 207 && player.pos.y <= 329) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 130 && player.pos.x <= 640) && (player.pos.y >= 265 && player.pos.y <= 329) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 640) && (player.pos.y >= 343 && player.pos.y <= 480) && tecla == TECLA_DOWN) baimena = 0;
    //lehenengo bertikala
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 164) && tecla == TECLA_RIGHT) baimena = 0;

    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= 285 && player.pos.x <= 640) && (player.pos.y >= 124 && player.pos.y <= 164) && tecla == TECLA_UP) baimena = 0;
    //txanpi ondoan
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 234 && player.pos.y <= 274) && tecla == TECLA_UP) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 50) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 108) && (player.pos.y >= 298 && player.pos.y <= 338) && tecla == TECLA_DOWN) baimena = 0;

    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x >= -35 && player.pos.x <= 111) && (player.pos.y >= 299 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;
    //gaztelua
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 507 && player.pos.x <= 602) && (player.pos.y >= 270 && player.pos.y <= 480) && tecla == TECLA_RIGHT) baimena = 0;
    //ate ondokoa
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 390 && player.pos.x <= 640) && (player.pos.y >= 0 && player.pos.y <= 260) && tecla == TECLA_RIGHT) baimena = 0;

    return baimena;
}

int HITBOX_mundua4(int tecla)
{
    int baimena = 1;

    return baimena;
}

int HITBOX_hasieraEtxea(int tecla)
{
    int baimena = 1;

    //lurra
    if ((player.pos.y >= 378 && player.pos.y <= 480) && tecla == TECLA_s) baimena = 0;
    if ((player.pos.y >= 378 && player.pos.y <= 480) && tecla == TECLA_DOWN) baimena = 0;
    if ((player.pos.y <= 378) && tecla == TECLA_w) baimena = 0;
    if ((player.pos.y <= 378) && tecla == TECLA_UP) baimena = 0;
    //hormak
    if ((player.pos.x <= 0) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 0) && tecla == TECLA_LEFT) baimena = 0;

    if ((player.pos.x >= 600) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 600) && tecla == TECLA_RIGHT) baimena = 0;

    return baimena;
}

int HITBOX_nibel1(int tecla)
{
    int baimena = 1;

    if ((player.pos.x <= 0) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 0) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x >= 605) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 605) && (player.pos.y >= 0 && player.pos.y <= 480) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x >= 59 && player.pos.x <= 274) && (player.pos.y >= 360 && player.pos.y <= 410) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 59 && player.pos.x <= 274) && (player.pos.y >= 360 && player.pos.y <= 410) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x >= 263 && player.pos.x <= 274) && (player.pos.y >= 345 && player.pos.y <= 360) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 263 && player.pos.x <= 274) && (player.pos.y >= 345 && player.pos.y <= 360) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x >= 299 && player.pos.x <= 309) && (player.pos.y >= 315 && player.pos.y <= 340) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 299 && player.pos.x <= 309) && (player.pos.y >= 315 && player.pos.y <= 340) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x >= 335 && player.pos.x <= 345) && (player.pos.y >= 302 && player.pos.y <= 310) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 335 && player.pos.x <= 345) && (player.pos.y >= 302 && player.pos.y <= 310) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x >= 362 && player.pos.x <= 372) && (player.pos.y >= 272 && player.pos.y <= 280) && tecla == TECLA_d) baimena = 0;
    if ((player.pos.x >= 362 && player.pos.x <= 372) && (player.pos.y >= 272 && player.pos.y <= 280) && tecla == TECLA_RIGHT) baimena = 0;
    if ((player.pos.x <= 389 && player.pos.x >= 379) && (player.pos.y >= 190 && player.pos.y <= 240) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 389 && player.pos.x >= 379) && (player.pos.y >= 190 && player.pos.y <= 240) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x <= 272 && player.pos.x >= 262) && (player.pos.y >= 400 && player.pos.y <= 410) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 272 && player.pos.x >= 262) && (player.pos.y >= 400 && player.pos.y <= 410) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x <= 353 && player.pos.x >= 343) && (player.pos.y >= 175 && player.pos.y <= 185) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 353 && player.pos.x >= 343) && (player.pos.y >= 175 && player.pos.y <= 185) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x <= 314 && player.pos.x >= 304) && (player.pos.y >= 150 && player.pos.y <= 160) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 314 && player.pos.x >= 304) && (player.pos.y >= 150 && player.pos.y <= 160) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x <= 272 && player.pos.x >= 260) && (player.pos.y >= 120 && player.pos.y <= 130) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 272 && player.pos.x >= 260) && (player.pos.y >= 120 && player.pos.y <= 130) && tecla == TECLA_LEFT) baimena = 0;
    if ((player.pos.x <= 234 && player.pos.x >= 224) && (player.pos.y >= 84 && player.pos.y <= 94) && tecla == TECLA_a) baimena = 0;
    if ((player.pos.x <= 234 && player.pos.x >= 224) && (player.pos.y >= 84 && player.pos.y <= 94) && tecla == TECLA_LEFT) baimena = 0;

    return baimena;
}

int HITBOX_nibel2(int tecla)
{
    int baimena = 1;

    if (player.pos.x <= 0 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 0 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 605 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 605 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 56 && player.pos.x <= 66 && player.pos.y >= 376 && player.pos.y <= 405 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 56 && player.pos.x <= 66 && player.pos.y >= 376 && player.pos.y <= 405 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 110 && player.pos.x >= 100 && player.pos.y >= 376 && player.pos.y <= 405 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 110 && player.pos.x >= 100 && player.pos.y >= 376 && player.pos.y <= 405 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 101 && player.pos.x <= 111 && player.pos.y >= 345 && player.pos.y <= 375 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 101 && player.pos.x <= 111 && player.pos.y >= 345 && player.pos.y <= 375 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 150 && player.pos.x <= 160 && player.pos.y >= 320 && player.pos.y <= 340 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 150 && player.pos.x <= 160 && player.pos.y >= 320 && player.pos.y <= 340 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 191 && player.pos.x <= 201 && player.pos.y >= 276 && player.pos.y <= 306 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 191 && player.pos.x <= 201 && player.pos.y >= 276 && player.pos.y <= 306 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 200 && player.pos.x >= 190 && player.pos.y >= 240 && player.pos.y <= 272 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 200 && player.pos.x >= 190 && player.pos.y >= 240 && player.pos.y <= 272 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x <= 155 && player.pos.x >= 145 && player.pos.y >= 196 && player.pos.y <= 228 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 155 && player.pos.x >= 145 && player.pos.y >= 196 && player.pos.y <= 228 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 155 && player.pos.x <= 165 && player.pos.y >= 165 && player.pos.y <= 195 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 155 && player.pos.x <= 165 && player.pos.y >= 165 && player.pos.y <= 195 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 200 && player.pos.x <= 210 && player.pos.y >= 137 && player.pos.y <= 169 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 200 && player.pos.x <= 210 && player.pos.y >= 137 && player.pos.y <= 169 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 308 && player.pos.x <= 318 && player.pos.y >= 100 && player.pos.y <= 132 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 308 && player.pos.x <= 318 && player.pos.y >= 100 && player.pos.y <= 132 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 309 && player.pos.x >= 299 && player.pos.y >= 73 && player.pos.y <= 105 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 309 && player.pos.x >= 299 && player.pos.y >= 73 && player.pos.y <= 105 && tecla == TECLA_LEFT) baimena = 0;

    return baimena;
}

void grabitatea()
{
    player.pos.y += 1.5;
    irudiaMugitu(player.id, player.pos.x, player.pos.y);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
}

void grabitateaAplikatu_nibel1()
{
    if (player.pos.x >= 0 && player.pos.x <= 59 && player.pos.y <= 399 && player.pos.y >= 125) grabitatea(); //lurra
    else if (player.pos.x >= 0 && player.pos.x <= 274 && player.pos.y >= 125 && player.pos.y <= 354) grabitatea();//lehenengo plataforma
    else if (player.pos.x >= 274 && player.pos.x <= 276 && player.pos.y >= 125 && player.pos.y <= 399) grabitatea();//lehenengo airea
    else if (player.pos.x >= 276 && player.pos.x <= 300 && player.pos.y >= 125 && player.pos.y <= 329) grabitatea();//bigarren plataforma
    else if (player.pos.x >= 300 && player.pos.x <= 330 && player.pos.y >= 173 && player.pos.y <= 303) grabitatea();//hirugarren plataforma
    else if (player.pos.x >= 330 && player.pos.x <= 360 && player.pos.y >= 200 && player.pos.y <= 275) grabitatea(); //laugarren plataforma
    else if (player.pos.x >= 360 && player.pos.x <= 400 && player.pos.y >= 200 && player.pos.y <= 250) grabitatea(); //bosgarren plataforma
    else if (player.pos.x >= 400 && player.pos.x <= 410 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();//bigarren airea
    else if (player.pos.x >= 410 && player.pos.x <= 595 && player.pos.y >= 0 && player.pos.y <= 215) grabitatea(); //seigarren plataforma
    else if (player.pos.x >= 379 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 178) grabitatea(); //zazpigarren plataforma
    else if (player.pos.x >= 303 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 151) grabitatea(); //zortzigarren plataforma
    else if (player.pos.x >= 263 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 120) grabitatea(); //bederatzigarren plataforma
    else if (player.pos.x >= 221 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 85) grabitatea(); //hamargarren plataforma
    else if (player.pos.x >= 0 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 62) grabitatea(); //azken plataforma
    else if (player.pos.x >= 415 && player.pos.x <= 640 && player.pos.y >= 277 && player.pos.y <= 399) grabitatea(); //eskuineko hutsune handia
    else if (player.pos.x >= 318 && player.pos.x <= 640 && player.pos.y >= 344 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 350 && player.pos.x <= 640 && player.pos.y >= 337 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 383 && player.pos.x <= 640 && player.pos.y >= 312 && player.pos.y <= 399) grabitatea();
}

void grabitateaAplikatu_nibel2()
{
    if (player.pos.x >= 0 && player.pos.x <= 56 && player.pos.y >= 111 && player.pos.y <= 399) grabitatea();//1
    else if (player.pos.x >= 57 && player.pos.x <= 105 && player.pos.y >= 111 && player.pos.y <= 363) grabitatea();//2
    else if (player.pos.x >= 106 && player.pos.x <= 110 && player.pos.y >= 111 && player.pos.y <= 399) grabitatea();//3
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 227 && player.pos.y <= 327) grabitatea();//4
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 376 && player.pos.y <= 399) grabitatea();//5
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 111 && player.pos.y <= 189) grabitatea();//6
    else if (player.pos.x >= 147 && player.pos.x <= 155 && player.pos.y >= 111 && player.pos.y <= 399) grabitatea();//7
    else if (player.pos.x >= 156 && player.pos.x <= 640 && player.pos.y >= 346 && player.pos.y <= 399) grabitatea();//8
    else if (player.pos.x >= 156 && player.pos.x <= 192 && player.pos.y >= 250 && player.pos.y <= 302) grabitatea();//9
    else if (player.pos.x >= 156 && player.pos.x <= 192 && player.pos.y >= 179 && player.pos.y <= 228) grabitatea();//10
    else if (player.pos.x >= 164 && player.pos.x <= 198 && player.pos.y >= 105 && player.pos.y <= 156) grabitatea();//11
    else if (player.pos.x >= 200 && player.pos.x <= 227 && player.pos.y >= 177 && player.pos.y <= 267) grabitatea();//12
    else if (player.pos.x >= 228 && player.pos.x <= 640 && player.pos.y >= 177 && player.pos.y <= 399) grabitatea();//13
    else if (player.pos.x >= 193 && player.pos.x <= 199 && player.pos.y >= 200 && player.pos.y <= 399) grabitatea();//14
    else if (player.pos.x >= 199 && player.pos.x <= 209 && player.pos.y >= 105 && player.pos.y <= 267) grabitatea();//15
    else if (player.pos.x >= 210 && player.pos.x <= 291 && player.pos.y >= 81 && player.pos.y <= 131) grabitatea();//16
    else if (player.pos.x >= 292 && player.pos.x <= 308 && player.pos.y >= 0 && player.pos.y <= 131) grabitatea();//17
    else if (player.pos.x >= 353 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();//18
    else if (player.pos.x >= 310 && player.pos.x <= 352 && player.pos.y >= 0 && player.pos.y <= 97) grabitatea();//19
    else if (player.pos.x >= 309 && player.pos.x <= 352 && player.pos.y >= 136 && player.pos.y <= 399) grabitatea();//20
    else if (player.pos.x >= 0 && player.pos.x <= 291 && player.pos.y >= 0 && player.pos.y <= 65) grabitatea();//21
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 346 && player.pos.y <= 399) grabitatea();
}

void grabitateaAplikatu_nibel3()
{
    if (player.pos.x >= 0 && player.pos.x <= 77 && player.pos.y >= 74 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 77 && player.pos.x <= 513 && player.pos.y >= 298 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 571 && player.pos.x <= 581 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 582 && player.pos.x <= 605 && player.pos.y >= 0 && player.pos.y <= 351) grabitatea();
    else if (player.pos.x >= 513 && player.pos.x <= 571 && player.pos.y >= 0 && player.pos.y <= 322) grabitatea();
    else if (player.pos.x >= 513 && player.pos.x <= 571 && player.pos.y >= 330 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 504 && player.pos.x <= 513 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 455 && player.pos.x <= 503 && player.pos.y >= 0 && player.pos.y <= 283) grabitatea();
    else if (player.pos.x >= 400 && player.pos.x <= 455 && player.pos.y >= 272 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 292 && player.pos.x <= 400 && player.pos.y >= 222 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 401 && player.pos.x <= 454 && player.pos.y >= 0 && player.pos.y <= 242) grabitatea();
    else if (player.pos.x >= 396 && player.pos.x <= 400 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 351 && player.pos.x <= 395 && player.pos.y >= 0 && player.pos.y <= 212) grabitatea();
    else if (player.pos.x >= 297 && player.pos.x <= 350 && player.pos.y >= 0 && player.pos.y <= 399) grabitatea();
    else if (player.pos.x >= 78 && player.pos.x <= 292 && player.pos.y >= 243 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 78 && player.pos.x <= 127 && player.pos.y >= 74 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 128 && player.pos.x <= 170 && player.pos.y >= 74 && player.pos.y <= 231) grabitatea();
    else if (player.pos.x >= 171 && player.pos.x <= 176 && player.pos.y >= 87 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 177 && player.pos.x <= 219 && player.pos.y >= 96 && player.pos.y <= 205) grabitatea();
    else if (player.pos.x >= 225 && player.pos.x <= 250 && player.pos.y >= 185 && player.pos.y <= 174) grabitatea();
    else if (player.pos.x >= 250 && player.pos.x <= 260 && player.pos.y >= 0 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 261 && player.pos.x <= 312 && player.pos.y >= 0 && player.pos.y <= 147) grabitatea();
    else if (player.pos.x >= 158 && player.pos.x <= 292 && player.pos.y >= 242 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 166 && player.pos.x <= 292 && player.pos.y >= 215 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 228 && player.pos.x <= 292 && player.pos.y >= 186 && player.pos.y <= 288) grabitatea();
    else if (player.pos.x >= 0 && player.pos.x <= 182 && player.pos.y >= 0 && player.pos.y <= 63) grabitatea();
    else if (player.pos.x >= 210 && player.pos.x <= 257 && player.pos.y >= 0 && player.pos.y <= 110) grabitatea();
    else if (player.pos.x >= 182 && player.pos.x <= 217 && player.pos.y >= 0 && player.pos.y <= 74) grabitatea();
}

int HITBOX_nibel3(int tecla)
{
    int baimena = 1;

    if (player.pos.x <= 0 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 0 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 605 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 605 && player.pos.y >= 0 && player.pos.y <= 480 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 569 && player.pos.x <= 579 && player.pos.y >= 365 && player.pos.y <= 405 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 569 && player.pos.x <= 579 && player.pos.y >= 365 && player.pos.y <= 405 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 569 && player.pos.x >= 559 && player.pos.y >= 334 && player.pos.y <= 375 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 569 && player.pos.x >= 559 && player.pos.y >= 334 && player.pos.y <= 375 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 515 && player.pos.x <= 525 && player.pos.y >= 334 && player.pos.y <= 375 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 515 && player.pos.x <= 525 && player.pos.y >= 334 && player.pos.y <= 375 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 500 && player.pos.x >= 490 && player.pos.y >= 293 && player.pos.y <= 333 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 500 && player.pos.x >= 490 && player.pos.y >= 293 && player.pos.y <= 333 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 452 && player.pos.x <= 462 && player.pos.y >= 293 && player.pos.y <= 333 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 452 && player.pos.x <= 462 && player.pos.y >= 293 && player.pos.y <= 333 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 452 && player.pos.x >= 442 && player.pos.y >= 252 && player.pos.y <= 292 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 452 && player.pos.x >= 442 && player.pos.y >= 252 && player.pos.y <= 292 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 407 && player.pos.x <= 417 && player.pos.y >= 252 && player.pos.y <= 292 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 407 && player.pos.x <= 417 && player.pos.y >= 252 && player.pos.y <= 292 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 390 && player.pos.x >= 380 && player.pos.y >= 221 && player.pos.y <= 241 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 390 && player.pos.x >= 380 && player.pos.y >= 221 && player.pos.y <= 261 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 344 && player.pos.x <= 354 && player.pos.y >= 221 && player.pos.y <= 262 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 344 && player.pos.x <= 354 && player.pos.y >= 221 && player.pos.y <= 242 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 290 && player.pos.x >= 280 && player.pos.y >= 297 && player.pos.y <= 337 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 290 && player.pos.x >= 280 && player.pos.y >= 297 && player.pos.y <= 337 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 83 && player.pos.x <= 93 && player.pos.y >= 297 && player.pos.y <= 337 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 83 && player.pos.x <= 93 && player.pos.y >= 297 && player.pos.y <= 337 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 133 && player.pos.x <= 143 && player.pos.y >= 240 && player.pos.y <= 280 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 133 && player.pos.x <= 143 && player.pos.y >= 240 && player.pos.y <= 280 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 182 && player.pos.x >= 172 && player.pos.y >= 240 && player.pos.y <= 280 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 182 && player.pos.x >= 172 && player.pos.y >= 240 && player.pos.y <= 280 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 175 && player.pos.x <= 185 && player.pos.y >= 219 && player.pos.y <= 259 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 175 && player.pos.x <= 185 && player.pos.y >= 219 && player.pos.y <= 259 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 224 && player.pos.x >= 214 && player.pos.y >= 219 && player.pos.y <= 259 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 224 && player.pos.x >= 214 && player.pos.y >= 219 && player.pos.y <= 259 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 210 && player.pos.x <= 220 && player.pos.y >= 183 && player.pos.y <= 223 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 210 && player.pos.x <= 220 && player.pos.y >= 183 && player.pos.y <= 223 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x >= 255 && player.pos.x <= 265 && player.pos.y >= 157 && player.pos.y <= 197 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 255 && player.pos.x <= 265 && player.pos.y >= 157 && player.pos.y <= 197 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 299 && player.pos.x >= 289 && player.pos.y >= 157 && player.pos.y <= 197 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 299 && player.pos.x >= 289 && player.pos.y >= 157 && player.pos.y <= 197 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x <= 252 && player.pos.x >= 242 && player.pos.y >= 121 && player.pos.y <= 161 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 252 && player.pos.x >= 242 && player.pos.y >= 121 && player.pos.y <= 161 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x >= 200 && player.pos.x <= 210 && player.pos.y >= 121 && player.pos.y <= 161 && tecla == TECLA_d) baimena = 0;
    if (player.pos.x >= 200 && player.pos.x <= 210 && player.pos.y >= 121 && player.pos.y <= 161 && tecla == TECLA_RIGHT) baimena = 0;
    if (player.pos.x <= 216 && player.pos.x >= 206 && player.pos.y >= 80 && player.pos.y <= 120 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 216 && player.pos.x >= 206 && player.pos.y >= 80 && player.pos.y <= 120 && tecla == TECLA_LEFT) baimena = 0;
    if (player.pos.x <= 173 && player.pos.x >= 163 && player.pos.y >= 73 && player.pos.y <= 113 && tecla == TECLA_a) baimena = 0;
    if (player.pos.x <= 173 && player.pos.x >= 163 && player.pos.y >= 73 && player.pos.y <= 113 && tecla == TECLA_LEFT) baimena = 0;

    return baimena;
}

int HITBOX_finala(int tecla)
{
    int baimena = 1;
    return baimena;
}

int HITBOX_npcInRange(GYM* boss)
{
    int baimena = 0;

    if ((player.pos.x >= boss->atea.x - 7 && player.pos.x <= boss->atea.x + 32) && (player.pos.y >= boss->atea.y && player.pos.y <= boss->atea.y + 45))
    {
        baimena = 1;
    }

    return baimena;
}

int hitground_nibel1()
{
    int egoera = 0;

    if (player.pos.x >= 0 && player.pos.x <= 59 && player.pos.y <= 399 && player.pos.y >= 125) egoera = 1; //lurra
    else if (player.pos.x >= 0 && player.pos.x <= 274 && player.pos.y >= 125 && player.pos.y <= 354) egoera = 1;//lehenengo plataforma
    else if (player.pos.x >= 274 && player.pos.x <= 276 && player.pos.y >= 125 && player.pos.y <= 399) egoera = 1;//lehenengo airea
    else if (player.pos.x >= 276 && player.pos.x <= 300 && player.pos.y >= 125 && player.pos.y <= 329) egoera = 1;//bigarren plataforma
    else if (player.pos.x >= 300 && player.pos.x <= 330 && player.pos.y >= 173 && player.pos.y <= 303) egoera = 1;//hirugarren plataforma
    else if (player.pos.x >= 330 && player.pos.x <= 360 && player.pos.y >= 200 && player.pos.y <= 275) egoera = 1; //laugarren plataforma
    else if (player.pos.x >= 360 && player.pos.x <= 400 && player.pos.y >= 200 && player.pos.y <= 250) egoera = 1; //bosgarren plataforma
    else if (player.pos.x >= 400 && player.pos.x <= 410 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;//bigarren airea
    else if (player.pos.x >= 410 && player.pos.x <= 595 && player.pos.y >= 0 && player.pos.y <= 215) egoera = 1; //seigarren plataforma
    else if (player.pos.x >= 347 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 178) egoera = 1; //zazpigarren plataforma
    else if (player.pos.x >= 303 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 151) egoera = 1; //zortzigarren plataforma
    else if (player.pos.x >= 263 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 120) egoera = 1; //bederatzigarren plataforma
    else if (player.pos.x >= 221 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 85) egoera = 1; //hamargarren plataforma
    else if (player.pos.x >= 0 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 62) egoera = 1; //azken plataforma
    else if (player.pos.x >= 415 && player.pos.x <= 640 && player.pos.y >= 277 && player.pos.y <= 399) egoera = 1; //eskuineko hutsune handia
    //beheko blokeen hutsuneak
    else if (player.pos.x >= 318 && player.pos.x <= 640 && player.pos.y >= 365 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 350 && player.pos.x <= 640 && player.pos.y >= 337 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 383 && player.pos.x <= 640 && player.pos.y >= 312 && player.pos.y <= 399) egoera = 1;

    return egoera;
}
int hitground_nibel2()
{
    int egoera = 0;

    if (player.pos.x >= 0 && player.pos.x <= 56 && player.pos.y >= 111 && player.pos.y <= 399) egoera = 1;//1
    else if (player.pos.x >= 57 && player.pos.x <= 105 && player.pos.y >= 111 && player.pos.y <= 363) egoera = 1;//2
    else if (player.pos.x >= 106 && player.pos.x <= 110 && player.pos.y >= 111 && player.pos.y <= 399) egoera = 1;//3
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 227 && player.pos.y <= 327) egoera = 1;//4
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 376 && player.pos.y <= 399) egoera = 1;//5
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 111 && player.pos.y <= 189) egoera = 1;//6
    else if (player.pos.x >= 147 && player.pos.x <= 155 && player.pos.y >= 111 && player.pos.y <= 399) egoera = 1;//7
    else if (player.pos.x >= 156 && player.pos.x <= 640 && player.pos.y >= 346 && player.pos.y <= 399) egoera = 1;//8
    else if (player.pos.x >= 156 && player.pos.x <= 192 && player.pos.y >= 250 && player.pos.y <= 302) egoera = 1;//9
    else if (player.pos.x >= 156 && player.pos.x <= 192 && player.pos.y >= 179 && player.pos.y <= 228) egoera = 1;//10
    else if (player.pos.x >= 164 && player.pos.x <= 198 && player.pos.y >= 105 && player.pos.y <= 156) egoera = 1;//11
    else if (player.pos.x >= 200 && player.pos.x <= 227 && player.pos.y >= 177 && player.pos.y <= 267) egoera = 1;//12
    else if (player.pos.x >= 228 && player.pos.x <= 640 && player.pos.y >= 177 && player.pos.y <= 399) egoera = 1;//13
    else if (player.pos.x >= 193 && player.pos.x <= 199 && player.pos.y >= 200 && player.pos.y <= 399) egoera = 1;//14
    else if (player.pos.x >= 199 && player.pos.x <= 209 && player.pos.y >= 105 && player.pos.y <= 267) egoera = 1;//15
    else if (player.pos.x >= 210 && player.pos.x <= 291 && player.pos.y >= 81 && player.pos.y <= 131) egoera = 1;//16
    else if (player.pos.x >= 292 && player.pos.x <= 308 && player.pos.y >= 0 && player.pos.y <= 131) egoera = 1;//17
    else if (player.pos.x >= 353 && player.pos.x <= 640 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;//18
    else if (player.pos.x >= 310 && player.pos.x <= 352 && player.pos.y >= 0 && player.pos.y <= 97) egoera = 1;//19
    else if (player.pos.x >= 309 && player.pos.x <= 352 && player.pos.y >= 136 && player.pos.y <= 399) egoera = 1;//20
    else if (player.pos.x >= 0 && player.pos.x <= 291 && player.pos.y >= 0 && player.pos.y <= 65) egoera = 1;//21
    else if (player.pos.x >= 111 && player.pos.x <= 146 && player.pos.y >= 346 && player.pos.y <= 399) egoera = 1;

    return egoera;
}
int hitground_nibel3()
{
    int egoera = 0;

    if (player.pos.x >= 0 && player.pos.x <= 77 && player.pos.y >= 74 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 77 && player.pos.x <= 513 && player.pos.y >= 298 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 571 && player.pos.x <= 581 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 582 && player.pos.x <= 605 && player.pos.y >= 0 && player.pos.y <= 351) egoera = 1;
    else if (player.pos.x >= 513 && player.pos.x <= 571 && player.pos.y >= 0 && player.pos.y <= 322) egoera = 1;
    else if (player.pos.x >= 513 && player.pos.x <= 571 && player.pos.y >= 330 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 504 && player.pos.x <= 513 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 455 && player.pos.x <= 503 && player.pos.y >= 0 && player.pos.y <= 283) egoera = 1;
    else if (player.pos.x >= 400 && player.pos.x <= 455 && player.pos.y >= 272 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 292 && player.pos.x <= 400 && player.pos.y >= 222 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 401 && player.pos.x <= 454 && player.pos.y >= 0 && player.pos.y <= 242) egoera = 1;
    else if (player.pos.x >= 396 && player.pos.x <= 400 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 351 && player.pos.x <= 395 && player.pos.y >= 0 && player.pos.y <= 212) egoera = 1;
    else if (player.pos.x >= 297 && player.pos.x <= 350 && player.pos.y >= 0 && player.pos.y <= 399) egoera = 1;
    else if (player.pos.x >= 78 && player.pos.x <= 292 && player.pos.y >= 243 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 78 && player.pos.x <= 127 && player.pos.y >= 74 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 128 && player.pos.x <= 170 && player.pos.y >= 74 && player.pos.y <= 231) egoera = 1;
    else if (player.pos.x >= 171 && player.pos.x <= 176 && player.pos.y >= 87 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 177 && player.pos.x <= 219 && player.pos.y >= 96 && player.pos.y <= 205) egoera = 1;
    else if (player.pos.x >= 225 && player.pos.x <= 250 && player.pos.y >= 185 && player.pos.y <= 174) egoera = 1;
    else if (player.pos.x >= 250 && player.pos.x <= 260 && player.pos.y >= 0 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 261 && player.pos.x <= 312 && player.pos.y >= 0 && player.pos.y <= 147) egoera = 1;
    else if (player.pos.x >= 158 && player.pos.x <= 292 && player.pos.y >= 242 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 166 && player.pos.x <= 292 && player.pos.y >= 215 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 228 && player.pos.x <= 292 && player.pos.y >= 186 && player.pos.y <= 288) egoera = 1;
    else if (player.pos.x >= 0 && player.pos.x <= 182 && player.pos.y >= 0 && player.pos.y <= 63) egoera = 1;
    else if (player.pos.x >= 210 && player.pos.x <= 257 && player.pos.y >= 0 && player.pos.y <= 110) egoera = 1;
    else if (player.pos.x >= 182 && player.pos.x <= 217 && player.pos.y >= 0 && player.pos.y <= 74) egoera = 1;

    return egoera;
}