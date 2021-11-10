#include"SDLHasieratu.h"
#include "irudiak.h"
#include "funtzioak.h"
#include "kontrolak.h"
#include "menua.h"

PLAYER player;
int pausa = 0;

int hasierakomenu(PLAYER menu)
{
    Mix_Music* gMusic = NULL;
    //PLAYER menu;
    POSIZIOA saguPos;
    saguPos = saguarenPosizioa();
    int ebentu = 0, pertsonaia = 0, egoera = 0, kargatu = 0;

    pantailaGarbitu();
    ebentu = ebentuaJasoGertatuBada();
    saguPos = saguarenPosizioa();
    if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 257) && (saguPos.x < 413) && (saguPos.y > 159) && (saguPos.y < 213))
    {
        irudiaKendu(menu.id);
        pantailaGarbitu();
        menu.id = irudiaSortu(KARGATU);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
        kargatu = kargatzekoMenua();
        if (kargatu == 1)//PARTIDA BERRIA
        {
            kargatuta = 1;
            player.pertsonaia = pertsonaiaAukeratu();
            playerHasieratu();
            jokuaHasi(pertsonaia);
            SDL_RenderPresent(gRenderer);
            do {
                ebentu = ebentuaJasoGertatuBada();
                egoera = ebentoaDetektatu(ebentu);
            } while (egoera != GAME_OVER);
        }
        else if (kargatu == 2)//KARGATU
        {
            do {
                ebentu = ebentuaJasoGertatuBada();
                egoera = ebentoaDetektatu(ebentu);
            } while (egoera != GAME_OVER);
        }
    }
    pantailaGarbitu();
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 175) && (saguPos.x < 485) && (saguPos.y > 230) && (saguPos.y < 260))
    {
        do
        {
            irudiaKendu(menu.id);
            pantailaGarbitu();
            menu.id = irudiaSortu(KONTROLAK);
            pantailaGarbitu();
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            ebentu = ebentuaJasoGertatuBada();
        } while (ebentu != SAGU_BOTOIA_EZKERRA);
        irudiaKendu(menu.id);
        menu.id = irudiaSortu(MENU);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
    }
    else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 180) && (saguPos.x < 470) && (saguPos.y > 270) && (saguPos.y < 305))
    {
        do
        {
            irudiaKendu(menu.id);
            pantailaGarbitu();
            menu.id = irudiaSortu(KREDITOAK);
            pantailaGarbitu();
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
            ebentu = ebentuaJasoGertatuBada();
        } while (ebentu != SAGU_BOTOIA_EZKERRA);
        irudiaKendu(menu.id);
        menu.id = irudiaSortu(MENU);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
    }
    else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 575) && (saguPos.x < 630) && (saguPos.y > 10) && (saguPos.y < 50))
    {
        //If the music is paused
        if ((Mix_PausedMusic() == 1) && (ebentu == SAGU_BOTOIA_EZKERRA))
        {
            //Resume the music
            Mix_ResumeMusic();
            pausa = 0;
            irudiaKendu(menu.id);
            menu.id = irudiaSortu(MENU);
            pantailaGarbitu();
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
        }
        //If the music is playing
        else
        {
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                //Pause the music
                Mix_PauseMusic();
                irudiaKendu(menu.id);
                menu.id = irudiaSortu(MENUMUTE);
                pantailaGarbitu();
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
        }
    }
    else if ((ebentu == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 380) && (saguPos.y > 320) && (saguPos.y < 340))
    {
        egoera = GAME_OVER;
    }


    return egoera;
}

int kargatzekoMenua()
{
    POSIZIOA saguPos;
    int ebentoa, kargatu = 0;

    do
    {
        ebentoa = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
        if (ebentoa == SAGU_BOTOIA_EZKERRA)
        {
            if ((saguPos.x >= 110 && saguPos.x <= 205) && (saguPos.y >= 215 && saguPos.y <= 280))
            {
                kargatu = 1; //PARTIDA BERRIA
            }
            else if ((saguPos.x >= 410 && saguPos.x <= 500) && (saguPos.y >= 215 && saguPos.y <= 280))
            {
                kargatu = 2; //KARGATU
            }
        }
    } while (kargatu == 0);

    return kargatu;
}

int pertsonaiaAukeratu()
{
    POSIZIOA saguPos;
    PLAYER menu;
    int pertsonaia = 0;

    menu.id = irudiaSortu(PERTSONAIA_MENUA);
    saguPos = saguarenPosizioa();
    do
    {
        ANIMAZIOAK_menuPertsonaiak();
        pertsonaia = HITBOX_menuPertsonaiak();
    } while (pertsonaia == 0);

    return pertsonaia;
}

int HITBOX_menuPertsonaiak()
{
    int ebentua, pertsonaia = 0;
    POSIZIOA saguPos;

    saguPos = saguarenPosizioa();
    ebentua = ebentuaJasoGertatuBada();
    if (ebentua == SAGU_BOTOIA_EZKERRA)
    {
        if ((saguPos.x >= 55 && saguPos.x <= 160) && (saguPos.y >= 215 && saguPos.y <= 295))
        {
            pertsonaia = 1; //MARIO
        }
        else if ((saguPos.x >= 195 && saguPos.x <= 280) && (saguPos.y >= 215 && saguPos.y <= 295))
        {
            pertsonaia = 2; //LUIGI
        }
    }

    return pertsonaia;
}

void ANIMAZIOAK_menuPertsonaiak()
{
    POSIZIOA saguPos;
    PLAYER menu;
    int ebentua, ID_pertsonaiaAukeratu = 0, ikutu = 0, aux = 0;

    ebentua = ebentuaJasoGertatuBada();
    saguPos = saguarenPosizioa();
    if ((saguPos.x >= 55 && saguPos.x <= 160) && (saguPos.y >= 215 && saguPos.y <= 295))
    {
        menu.id = irudiaSortu(PERTSONAIA_MENUA);
        ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU_MARIO);
        irudiakMarraztu();
        //aux aldagaia erabiliko dugu behin xagua hitboxatik kenduta pertsonaia inguratzen duen zati gorriak kentzeko
        aux = 1;
        irudiaKendu(menu.id);
        SDL_RenderPresent(gRenderer);
    }
    else if (aux == 1)
    {
        irudiaKendu(ID_pertsonaiaAukeratu);
        SDL_RenderPresent(gRenderer);
        aux = 0;
    }
    else if ((saguPos.x >= 195 && saguPos.x <= 280) && (saguPos.y >= 215 && saguPos.y <= 295))
    {
        menu.id = irudiaSortu(PERTSONAIA_MENUA);
        ID_pertsonaiaAukeratu = irudiaSortu(PERTSONAIA_AUKERATU_LUIGI);
        irudiakMarraztu();
        irudiaKendu(ID_pertsonaiaAukeratu);
        aux = 2;
        irudiaKendu(menu.id);
    }
    else if (aux == 2)
    {
        irudiaKendu(ID_pertsonaiaAukeratu);
        aux = 0;
    }
    SDL_RenderPresent(gRenderer);
}
