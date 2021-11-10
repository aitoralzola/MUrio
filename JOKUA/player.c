#include "funtzioak.h"
#include "kontrolak.h"
#include "irudiak.h"
#include "hitbox.h"
#include "SDLHasieratu.h"

SDL_Event event;
POSIZIOA saguPos;
PLAYER player;

SDL_Rect set_camera(SDL_Rect camera);
SDL_Rect camera = { 0, 0, 640, 420 };

int erantzunak[6];
int goraAnimaz = 0, ezkerreraAnimaz = 0, beheraAnimaz = 0, eskubiAnimaz = 0;

/*void messagePopUp(char* message)
{
    int messageID;

    messageID = irudiaSortu(MENSAJE);
    irudiaMugitu(messageID, 0, 363);
    irudiakMarraztu();
    textuaIdatzi(40, 410, message);
    SDL_RenderPresent(gRenderer);
    Sleep(2000);
    textuaDesgaitu();
    irudiaKendu(messageID);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
}*/

void denaKargatu(GYM* gimnasioak)
{
    int bossID;

    if (player.mapa == MAPA_MUNDUA1 || player.mapa == MAPA_MUNDUA2 || player.mapa == MAPA_MUNDUA3 || player.mapa == MAPA_MUNDUA4)
    {
        irudiaSortu(MUNDUA);
    }
    else if (player.mapa == MAPA_ETXEA)
    {
        irudiaSortu(LEHENENGO_PANTAILA_MARIO);
    }
    else if (player.mapa == MAPA_NIBEL1)
    {
        irudiaSortu(LEHENENGO_NIBELA);
    }
    else if (player.mapa == MAPA_NIBEL2)
    {
        irudiaSortu(BIGARREN_NIBELA);
    }
    else if (player.mapa == MAPA_NIBEL3)
    {
        irudiaSortu(HIRUGARREN_NIBELA);
    }
    else if (player.mapa == MAPA_FINALA)
    {
        irudiaSortu(MUNDU_FINALA);
    }
    if (player.pertsonaia == 1)
    {
        player.id = irudiaSortu(MARIO_GELDIRIK);
        irudiaMugitu(player.id, player.pos.x, player.pos.y);
    }
    else if (player.pertsonaia == 2)
    {
        player.id = irudiaSortu(LUIGI_GELDIRIK);
        irudiaMugitu(player.id, player.pos.x, player.pos.y);
    }
}

int kargatuPartida(GYM* gimnasioak)
{
    int kargatu = 0;
    FILE* save;

    save = fopen("MUrio_gorde.sav", "r");
    if (save == NULL)
    {
        printf("Errorea egon da fitxategia irekitzerakoan . . .\n");
    }
    else
    {
        fscanf(save, "Posizioak: %f %f Mapa: %d pertsonaia: %d\n", &player.pos.x, &player.pos.y, &player.mapa, &player.pertsonaia);
        gimnasioakHasieratu(gimnasioak);
        denaKargatu(gimnasioak);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
        kargatu = 1;
    }

    return kargatu;
}

void gordePartida()
{
    FILE* save;

    save = fopen("MUrio_gorde.sav", "w");
    if (save == NULL)
    {
        printf("Errorea egon da fitxategia sortzerakoan. . .");
    }
    else
    {
        fprintf(save, "Posizioak: %f %f Mapa: %d pertsonaia: %d\n", player.pos.x, player.pos.y, player.mapa, player.pertsonaia);
        fclose(save);
    }
}

int bukaeraMezua(GYM* gimnasioHitbox, int ebentoa)
{
    int bukatu = JOLASTEN, bukaeraID = 0;

    gimnasioakHasieratu(gimnasioHitbox);
    SDL_RenderPresent(gRenderer);
    Sleep(3000);
    textuaDesgaitu();
    textuaIdatzi(40, 415, "ESC sakatu ateratzeko");
    SDL_RenderPresent(gRenderer);
    bukatu = GAME_OVER;
    do
    {
        ebentoa = ebentuaJasoGertatuBada();
    } while (ebentoa != TECLA_ESCAPE);
    irudiaKendu(bukaeraID);

    return bukatu;
}


void gymRefresh(char* gymIMG)
{
    int imgID = -1;

    if (player.mapa == MAPA_NIBEL1)
    {
        player.mapa = MAPA_MUNDUA2;
        irudiaSortu(MUNDUA);
    }
    else if (player.mapa == MAPA_NIBEL2)
    {
        player.mapa = MAPA_MUNDUA3;
        irudiaSortu(MUNDUA);
    }
    else if (player.mapa == MAPA_NIBEL3)
    {
        player.mapa = MAPA_MUNDUA4;
        irudiaSortu(MUNDUA);
    }
}

void galderaPuntuazioaIgo(int nota)
{
    if (player.mapa == MAPA_NIBEL1)player.notak.gim1 = (float)((nota * 10) / 3);
    if (player.mapa == MAPA_NIBEL2)player.notak.gim2 = (float)((nota * 10) / 3);
    if (player.mapa == MAPA_NIBEL3)player.notak.gim3 = (float)((nota * 10) / 3);
}

void playerHasieratu()
{
    player.notak.gim1 = -1;
    player.notak.gim2 = -1;
    player.notak.gim3 = -1;
    player.mapa = MAPA_ETXEA;
}

void erantzunaHasieratu()
{
    erantzunak[0] = 1;
    erantzunak[1] = 2;
    erantzunak[2] = 3;
}

int galderakBaieztatu(int zureErantzuna, int galdera)
{
    int ondo = 0;

    if (zureErantzuna == erantzunak[galdera])
    {
        ondo = 1;
        printf("Ondo\n");
    }

    return ondo;
}

int galderaPantailaratu(char* imgGaldera)
{
    int galderaID, ebentoa;

    galderaID = irudiaSortu(imgGaldera);
    SDL_RenderPresent(gRenderer);
    do
    {
        ebentoa = ebentuaJasoGertatuBada();
    } while (ebentoa != SAGU_BOTOIA_EZKERRA);

    irudiaKendu(galderaID);
    galderaID = irudiaSortu(imgGaldera);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    return galderaID;
}

int galderaKargatu(int galdera)
{
    int galderaID = -1;

    if (player.mapa == MAPA_NIBEL1)
    {
        galderaPantailaratu(LEHENENGO_GALDERA);
        galderaID = 0;
    }
    else if (player.mapa == MAPA_NIBEL2)
    {
        galderaPantailaratu(BIGARREN_GALDERA);
        galderaID = 1;
    }
    else if (player.mapa == MAPA_NIBEL3)
    {
        galderaPantailaratu(HIRUGARREN_GALDERA);
        galderaID = 2;
    }

    return galderaID;
}


int battleStage()
{
    int erantzuna = 0, galdera = 0, galderaID, zuzen;
    int nota = 0;

    galderaID = galderaKargatu(galdera);
    erantzunaHasieratu();
    erantzuna = galderenHitboxa();
    if (erantzuna != 0)
    {
        irudiaKendu(galderaID);
        zuzen = galderakBaieztatu(erantzuna, galderaID);
        if (zuzen == 1)
        {
            nota++;
        }
    }
    galderaPuntuazioaIgo(nota);
    irudiaKendu(galderaID);
    endBattle();
    irudiaMugitu(player.id, player.pos.x, player.pos.y);
    SDL_RenderPresent(gRenderer);

    return erantzuna;
}

void endBattle()
{
    int egoera, berriz = 0;
    POSIZIOA saguPos;
    if (player.mapa == MAPA_NIBEL1 && player.notak.gim1 == 3)
    {
        irudiaKendu(LEHENENGO_GALDERA);
        irudiaSortu(GALDERA_ZUZENA);
        SDL_RenderPresent(gRenderer);
        SDL_Delay(1000);
        gymRefresh(MAPA_MUNDUA2);
    }
    else if (player.mapa == MAPA_NIBEL1 && player.notak.gim1 != 3)
    {
        irudiaKendu(LEHENENGO_GALDERA);
        irudiaSortu(GALDERA_OKERRA);
        SDL_RenderPresent(gRenderer);
        do {

            egoera = ebentuaJasoGertatuBada();
            saguPos = saguarenPosizioa();
            if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 183 && saguPos.x <= 373) && (saguPos.y >= 242 && saguPos.y <= 267))
            {
                berriz = 1;
            }
        } while (berriz != 1);
        if (berriz)
        {
            berrabiarazi();
        }
    }

    else if (player.mapa == MAPA_NIBEL2 && player.notak.gim2 == 3)
    {
        irudiaKendu(BIGARREN_GALDERA);
        irudiaSortu(GALDERA_ZUZENA);
        SDL_RenderPresent(gRenderer);
        SDL_Delay(1000);
        gymRefresh(MAPA_MUNDUA3);
    }

    else if (player.mapa == MAPA_NIBEL2 && player.notak.gim2 != 3)
    {
        irudiaKendu(BIGARREN_GALDERA);
        irudiaSortu(GALDERA_OKERRA);
        SDL_RenderPresent(gRenderer);
        do {

            egoera = ebentuaJasoGertatuBada();
            saguPos = saguarenPosizioa();
            if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 183 && saguPos.x <= 373) && (saguPos.y >= 242 && saguPos.y <= 267))
            {
                berriz = 1;
            }
        } while (berriz != 1);
        if (berriz)
        {
            berrabiarazi();
        }
    }

    else if (player.mapa == MAPA_NIBEL3 && player.notak.gim3 == 3)
    {
        irudiaKendu(HIRUGARREN_GALDERA);
        irudiaSortu(GALDERA_ZUZENA);
        SDL_RenderPresent(gRenderer);
        SDL_Delay(1000);
        gymRefresh(MAPA_MUNDUA4);
    }

    else if (player.mapa == MAPA_NIBEL3 && player.notak.gim3 != 3)
    {
        irudiaKendu(HIRUGARREN_GALDERA);
        irudiaSortu(GALDERA_OKERRA);
        SDL_RenderPresent(gRenderer);
        do {

            egoera = ebentuaJasoGertatuBada();
            saguPos = saguarenPosizioa();
            if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 183 && saguPos.x <= 373) && (saguPos.y >= 242 && saguPos.y <= 267))
            {
                berriz = 1;
            }
        } while (berriz != 1);
        if (berriz)
        {
            berrabiarazi();
        }
    }

    if (player.pertsonaia == 1)
    {
        player.id = irudiaSortu(MARIO_GELDIRIK);
        irudiaMugitu(player.id, player.pos.x, player.pos.y);
    }
    else if (player.pertsonaia == 2)
    {
        player.id = irudiaSortu(LUIGI_GELDIRIK);
        irudiaMugitu(player.id, player.pos.x, player.pos.y);
    }
    irudiakMarraztu();
}

int gimnasioakHasieratu(GYM* gimnasioHitbox)
{
    int i = 0;

    if (player.mapa == MAPA_MUNDUA1)
    {
        //LEHENENGO NIBELA
        gimnasioHitbox[i].egoera.sartu.x = 368;//lehenengo nibelera sartzeko
        gimnasioHitbox[i].egoera.sartu.y = 162;
        i++;
    }
    else if (player.mapa == MAPA_MUNDUA2)
    {
        //BIGARREN NIBELA
        gimnasioHitbox[i].egoera.sartu.x = 65;//bigarren nibelera sartzeko
        gimnasioHitbox[i].egoera.sartu.y = 280;
        i++;
    }
    else if (player.mapa == MAPA_MUNDUA3)
    {
        //HIRUGARREN NIBELA
        gimnasioHitbox[i].egoera.sartu.x = 501;
        gimnasioHitbox[i].egoera.sartu.y = 343;
        i++;
    }
    else if (player.mapa == MAPA_MUNDUA4)
    {
        //LAUGARREN NIBELA
        gimnasioHitbox[i].egoera.sartu.x = 369;
        gimnasioHitbox[i].egoera.sartu.y = 344;
        i++;
    }
    else if (player.mapa == MAPA_ETXEA)
    {
        //MUNDUA
        gimnasioHitbox[i].egoera.sartu.x = 595;//para entrar al mundo
        gimnasioHitbox[i].egoera.sartu.y = 378;
        gimnasioHitbox[i].egoera.irten.x = 51;//en que parte del mundo sale
        gimnasioHitbox[i].egoera.irten.y = 73;
        i++;
    }
    else if (player.mapa == MAPA_NIBEL1)
    {
        //PARA ENTRAR A LA PREGUNTA
        gimnasioHitbox[i].egoera.irten.x = 29;//en que parte del mapa sale
        gimnasioHitbox[i].egoera.irten.y = 399;
        gimnasioHitbox[i].atea.x = 9;//60 60para que aparezca la pregunta
        gimnasioHitbox[i].atea.y = 399;
        i++;
    }
    else if (player.mapa == MAPA_NIBEL2)
    {
        //PARA ENTRAR A LA PREGUNTA
        gimnasioHitbox[i].egoera.irten.x = 29;
        gimnasioHitbox[i].egoera.irten.y = 399;
        gimnasioHitbox[i].atea.x = 9; //60 60
        gimnasioHitbox[i].atea.y = 399;
        i++;
    }
    else if (player.mapa == MAPA_NIBEL3)
    {
        //PARA ENTRAR A LA PREGUNTA
        gimnasioHitbox[i].egoera.irten.x = 29;
        gimnasioHitbox[i].egoera.irten.y = 399;
        gimnasioHitbox[i].atea.x = 9;//60 60
        gimnasioHitbox[i].atea.y = 399;
        i++;
    }
    else if (player.mapa == MAPA_FINALA)
    {
        //PARA ENTRAR A LA PREGUNTA
        gimnasioHitbox[i].egoera.irten.x = 29;
        gimnasioHitbox[i].egoera.irten.y = 399;
        gimnasioHitbox[i].atea.x = 60; //60 60
        gimnasioHitbox[i].atea.y = 60;
        i++;
    }
        return i;
}

int edifizioaIreki(GYM gimnasioHitbox[], int* id, int max)
{
    int ret = 0, i;

    for (i = 0; i < max && ret == 0; i++)
    {
        if ((player.pos.x >= gimnasioHitbox[i].egoera.sartu.x && player.pos.x <= gimnasioHitbox[i].egoera.sartu.x + 51) && (player.pos.y >= gimnasioHitbox[i].egoera.sartu.y && player.pos.y <= gimnasioHitbox[i].egoera.sartu.y + 51))
        {
            ret = SARTU;
            printf("SARTUuuuuuuuuuuuuuu");
            *id = i;
        }
    }
    /* for (i = 0; i < max && ret == 0; i++)
    {

        if ((player.pos.x >= gimnasioHitbox[i].egoera.irten.x && player.pos.x <= gimnasioHitbox[i].egoera.irten.x + 21) && (player.pos.y >= gimnasioHitbox[i].egoera.irten.y && player.pos.y <= gimnasioHitbox[i].egoera.irten.y + 8))
        {
            ret = IRTEN;
            printf("IRTEN");
            *id = i;
        }
    }*/

    return ret;
}

int irudiaAurkitu(int id, int interakzioa)
{
    int imgID = -1;
    if (interakzioa == SARTU && player.mapa == MAPA_ETXEA)
    {
        imgID = irudiaSortu(MUNDUA);
        player.mapa = MAPA_MUNDUA1;
    }

    else if (interakzioa == SARTU && player.mapa == MAPA_MUNDUA1)
    {
        imgID = irudiaSortu(LEHENENGO_NIBELA);
        player.mapa = MAPA_NIBEL1;
    }

    else if (interakzioa == SARTU && player.mapa == MAPA_MUNDUA2)
    {
        imgID = irudiaSortu(BIGARREN_NIBELA);
        player.mapa = MAPA_NIBEL2;
    }

    else if (interakzioa == SARTU && player.mapa == MAPA_MUNDUA3)
    {
        imgID = irudiaSortu(HIRUGARREN_NIBELA);
        player.mapa = MAPA_NIBEL3;
    }
    else if (interakzioa == SARTU && player.mapa == MAPA_MUNDUA4)
    {
        imgID = irudiaSortu(MUNDU_FINALA);
        player.mapa = MAPA_FINALA;
    }

    return imgID;
}

void eraikinInterakzio(GYM* gimnasioHitbox)
{
    int interakzioa = 0, id = 0, gymID, max, bossID = 0, ezegin = 1;

    max = gimnasioakHasieratu(gimnasioHitbox);
    interakzioa = edifizioaIreki(gimnasioHitbox, &id, max);

    if (interakzioa == SARTU)
    {
        gymID = irudiaAurkitu(id, interakzioa);
        if (ezegin == 1)
        {
            irudiaKendu(player.id);
            gimnasioakHasieratu(gimnasioHitbox);
            player.pos.x = gimnasioHitbox[0].egoera.irten.x;
            player.pos.y = gimnasioHitbox[0].egoera.irten.y;
            if (player.pertsonaia == 1)
            {
                player.id = irudiaSortu(MARIO_GELDIRIK);
            }
            else
            {
                player.id = irudiaSortu(LUIGI_GELDIRIK);
            }
            irudiaMugitu(player.id, player.pos.x, player.pos.y);
            irudiaMugitu(bossID, gimnasioHitbox[0].atea.x, gimnasioHitbox[0].atea.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
        }
        else
        {
            //messagePopUp("Oraindik ez zara ikasgai guztietara joan");
        }

    }
}

int pausaMenua()
{
    int egoera, id, ret = 0, ikutu = 0, segi = 0, irten = 0;
    POSIZIOA saguPos;

    id = irudiaSortu(PAUSE);
    do
    {
        egoera = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
        if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 451 && saguPos.x <= 542) && (saguPos.y >= 206 && saguPos.y <= 271))
        {
            ikutu = 1;
        }

        if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 451 && saguPos.x <= 542) && (saguPos.y >= 59 && saguPos.y <= 121))
        {
            segi = 1;
        }

        if (egoera == SAGU_BOTOIA_EZKERRA && (saguPos.x >= 451 && saguPos.x <= 542) && (saguPos.y >= 360 && saguPos.y <= 423))
        {
            irten = 1;
        }

        SDL_RenderPresent(gRenderer);
    } while (ikutu != 1 && segi != 1 && irten != 1);
    saguPos = saguarenPosizioa();
    if (irten == 1)
    {
        ret = GAME_OVER;
    }
    else if (segi == 1)
    {
        ret = JOLASTEN;
    }
    else if (ikutu == 1)
    {
        gordePartida();
        ret = JOLASTEN;
    }

    pantailaGarbitu();
    irudiaKendu(id);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    return ret;
}

int ebentoaDetektatu(int ebentoa)
{
    int egoera = 1, baimena = 0;
    GYM* gimnasioHitbox;

    gimnasioHitbox = (GYM*)malloc(sizeof(GYM) * 10);
    if (kargatuta != 1)
    {
        kargatuta = kargatuPartida(gimnasioHitbox);
        if (kargatuta == 0)
        {
            egoera = GAME_OVER;
            //messagePopUp("Ez dago fitxategirik kargatzeko, jokua itxiko da. . .");
        }
    }
    if (player.mapa == MAPA_MUNDUA1 || player.mapa == MAPA_ETXEA || player.mapa == MAPA_MUNDUA2 || player.mapa == MAPA_MUNDUA3 || player.mapa==MAPA_MUNDUA4) {
        if (ebentoa == TECLA_w || ebentoa == TECLA_UP)
        {
            baimena = mapenHitboxak(ebentoa);
            pantailaGarbitu();
            if (baimena == 1)
            {
                player.pos.y -= (SALTO_MAPA / 60);
            }
            goraAnimaz = gorunztAnimazioa(goraAnimaz);
            irudiaMugitu(player.id, player.pos.x, player.pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            printf("x: %f, y: %f\n", player.pos.x, player.pos.y);
        }
        if (ebentoa == TECLA_a || ebentoa == TECLA_LEFT)
        {
            baimena = mapenHitboxak(ebentoa);
            pantailaGarbitu();
            ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
            if (baimena == 1) {
                player.pos.x -= SPEED / 60;
            }
            irudiaMugitu(player.id, player.pos.x, player.pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            printf("x: %f, y: %f\n", player.pos.x, player.pos.y);
        }
        if (ebentoa == TECLA_s || ebentoa == TECLA_DOWN)
        {
            baimena = mapenHitboxak(ebentoa);
            pantailaGarbitu();
            beheraAnimaz = beheruntzAnimazioa(beheraAnimaz);
            if (baimena == 1)
            {
                player.pos.y += SALTO_MAPA / 60;
            }
            irudiaMugitu(player.id, player.pos.x, player.pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            printf("x: %f, y: %f\n", player.pos.x, player.pos.y);
        }
        if (ebentoa == TECLA_d || ebentoa == TECLA_RIGHT)
        {
            baimena = mapenHitboxak(ebentoa);
            pantailaGarbitu();
            eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
            if (baimena == 1) {
                player.pos.x += SPEED / 60;
            }
            irudiaMugitu(player.id, player.pos.x, player.pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            printf("x: %f, y: %f\n", player.pos.x, player.pos.y);
        }
    }


    if (player.mapa == MAPA_NIBEL1)
    {
        {
            int hitground = 1, salto_altuera = 50, playerposy, saltospeed = 300;

            playerposy = player.pos.y;
            hitground = hitground_nibel1();

            if (ebentoa == TECLA_w || ebentoa == TECLA_UP)
            {
                while ((player.pos.y >= playerposy - salto_altuera) && (hitground == 0))
                {

                    pantailaGarbitu();
                    goraAnimaz = saltoAnimazioa(goraAnimaz);
                    player.pos.y -= 600 / 60;
                    irudiaMugitu(player.id, player.pos.x, player.pos.y);
                    irudiakMarraztu();
                    SDL_RenderPresent(gRenderer);
                }
            }
            if (ebentoa == TECLA_a || ebentoa == TECLA_LEFT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
                if (baimena == 1) {
                    player.pos.x -= 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
                printf("x=%i, y= %i\n", player.pos.x, player.pos.y);
            }
            if (ebentoa == TECLA_d || ebentoa == TECLA_RIGHT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
                if (baimena == 1) {
                    player.pos.x += 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            grabitateaAplikatu_nibel1();

        }
    }
    if (player.mapa == MAPA_NIBEL2)
    {
        {
            int hitground = 1, salto_altuera = 50, playerposy, saltospeed = 300;

            playerposy = player.pos.y;
            hitground = hitground_nibel2();

            if (ebentoa == TECLA_w || ebentoa == TECLA_UP)
            {
                while ((player.pos.y >= playerposy - salto_altuera) && (hitground == 0))
                {

                    pantailaGarbitu();
                    goraAnimaz = saltoAnimazioa(goraAnimaz);
                    player.pos.y -= 400 / 60;
                    irudiaMugitu(player.id, player.pos.x, player.pos.y);
                    irudiakMarraztu();
                    SDL_RenderPresent(gRenderer);
                }
            }
            if (ebentoa == TECLA_a || ebentoa == TECLA_LEFT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
                if (baimena == 1) {
                    player.pos.x -= 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            if (ebentoa == TECLA_d || ebentoa == TECLA_RIGHT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
                if (baimena == 1) {
                    player.pos.x += 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            grabitateaAplikatu_nibel2();

        }
    }
    if (player.mapa == MAPA_NIBEL3)
    {
        {
            int hitground = 1, salto_altuera = 50, playerposy, saltospeed = 300;

            playerposy = player.pos.y;
            hitground = hitground_nibel3();

            if (ebentoa == TECLA_w || ebentoa == TECLA_UP)
            {
                while ((player.pos.y >= playerposy - salto_altuera) && (hitground == 0))
                {

                    pantailaGarbitu();
                    goraAnimaz = saltoAnimazioa(goraAnimaz);
                    player.pos.y -= 400 / 60;
                    irudiaMugitu(player.id, player.pos.x, player.pos.y);
                    irudiakMarraztu();
                    SDL_RenderPresent(gRenderer);
                }
            }
            if (ebentoa == TECLA_a || ebentoa == TECLA_LEFT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
                if (baimena == 1) {
                    player.pos.x -= 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            if (ebentoa == TECLA_d || ebentoa == TECLA_RIGHT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
                if (baimena == 1) {
                    player.pos.x += 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            grabitateaAplikatu_nibel3();

        }
    }
    if (player.mapa == MAPA_FINALA)
    {
        {
            int hitground = 1, salto_altuera = 50, playerposy, saltospeed = 300;

            playerposy = player.pos.y;
            hitground = hitground_nibel2();

            if (ebentoa == TECLA_w || ebentoa == TECLA_UP)
            {
                while ((player.pos.y >= playerposy - salto_altuera) && (hitground == 0))
                {

                    pantailaGarbitu();
                    goraAnimaz = saltoAnimazioa(goraAnimaz);
                    player.pos.y -= 400 / 60;
                    irudiaMugitu(player.id, player.pos.x, player.pos.y);
                    irudiakMarraztu();
                    SDL_RenderPresent(gRenderer);
                }
            }
            if (ebentoa == TECLA_a || ebentoa == TECLA_LEFT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                ezkerreraAnimaz = ezkerreruntzAnimazioa(ezkerreraAnimaz);
                if (baimena == 1)
                {
                    player.pos.x -= 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            if (ebentoa == TECLA_d || ebentoa == TECLA_RIGHT)
            {
                baimena = mapenHitboxak(ebentoa);
                pantailaGarbitu();
                eskubiAnimaz = eskubiruntzAnimazioa(eskubiAnimaz);
                if (baimena == 1)
                {
                    player.pos.x += 9;
                }

                irudiaMugitu(player.id, player.pos.x, player.pos.y);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            grabitateaAplikatu_nibel2();

        }
    }
    if (ebentoa == TECLA_e)
    {
        eraikinInterakzio(gimnasioHitbox);
        if (player.mapa == MAPA_MUNDUA4 && player.pos.x >= 389 && player.pos.x <= 463 && player.pos.y >= 65 && player.pos.y <= 101)
        {
            irudiaKendu(MUNDU_FINALA);
            irudiaSortu(GALDERA_ZUZENA);
            SDL_RenderPresent(gRenderer);
            egoera = bukaeraMezua(gimnasioHitbox, ebentoa);
        }
        else
        {
            if (HITBOX_npcInRange(gimnasioHitbox) == 1/* && gymCompleted() == 1*/)
            {
                battleStage();
            }
        }
    }
    if (ebentoa == TECLA_ESCAPE)
    {
        egoera = pausaMenua();
    }
    free(gimnasioHitbox);

    return egoera;
}

int beheruntzAnimazioa(int boo)
{
    if (boo == 0)
    {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_ABAJOIZQ);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_ABAJOIZQ);
        boo = 1;
    }
    else
    {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_ABAJODER);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_ABAJODER);
        boo = 0;
    }

    return boo;
}

int ezkerreruntzAnimazioa(int boo) {
    if (boo == 0) {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_IZQDER);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_IZQDER);
        boo = 1;
    }
    else {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_IZQIZQ);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_IZQIZQ);
        boo = 0;
    }
    return boo;
}

int gorunztAnimazioa(int boo) {
    if (boo == 0) {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_ARRIBDER);
        else if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_ARRIBDER);
        boo = 1;
    }
    else {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_ARRIBIZQ);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_ARRIBIZQ);
        boo = 0;
    }
    return boo;
}

int eskubiruntzAnimazioa(int boo) {
    if (boo == 0) {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_DERDER);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_DERDER);
        boo = 1;
    }
    else {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(SPRITE_PLAYER_DERIZQ);
        if (player.pertsonaia == 2)player.id = irudiaSortu(PLAYER_DERIZQ);
        boo = 0;
    }
    return boo;
}

int saltoAnimazioa(int boo) {
    if (boo == 0) {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(MARIO_SALTO);
        if (player.pertsonaia == 2)player.id = irudiaSortu(LUIGI_SALTO);
        boo = 1;
    }
    else {
        irudiaKendu(player.id);
        if (player.pertsonaia == 1)player.id = irudiaSortu(MARIO_SALTO);
        if (player.pertsonaia == 2)player.id = irudiaSortu(LUIGI_SALTO);
        boo = 0;
    }
    return boo;
}

int ebentuaJasoGertatuBada()
{
    int ret = 0;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
                ret = TECLA_w;
                break;
            case SDL_SCANCODE_D:
                ret = TECLA_d;
                break;
            case SDL_SCANCODE_A:
                ret = TECLA_a;
                break;
            case SDL_SCANCODE_S:
                ret = TECLA_s;
                break;
            case SDL_SCANCODE_ESCAPE:
                ret = TECLA_ESCAPE;
                break;
            case SDL_SCANCODE_RETURN:
                ret = TECLA_ENTER;
                break;
            case SDL_SCANCODE_UP:
                ret = TECLA_UP;
                break;
            case SDL_SCANCODE_DOWN:
                ret = TECLA_DOWN;
                break;
            case SDL_SCANCODE_RIGHT:
                ret = TECLA_RIGHT;
                break;
            case SDL_SCANCODE_LEFT:
                ret = TECLA_LEFT;
                break;
            case SDL_SCANCODE_E:
                ret = TECLA_e;
                break;
            default:
                ret = event.key.keysym.scancode;
                break;
            }
            break;
        case SDL_QUIT:
            ret = GERTAERA_IRTEN;
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button) {
            case SDL_BUTTON_LEFT:
                ret = SAGU_BOTOIA_EZKERRA;
                break;
            case SDL_BUTTON_RIGHT:
                ret = SAGU_BOTOIA_ESKUMA;
                break;
            default:
                ret = event.button.button;
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            //ALDAGIA OROKOR BATEN EZARRIKO DUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
            saguPos.x = (float)event.motion.x;
            saguPos.y = (float)event.motion.y;
            ret = SAGU_MUGIMENDUA;
            break;

        }
    }
    return ret;
}

POSIZIOA saguarenPosizioa() { return saguPos; }