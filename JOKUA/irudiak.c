#include "irudiak.h"
#include "funtzioak.h"

IMG irudiak[MAX_IMG];
int irudiKop = 0;
int id = 0;

int Surface_kop = -2;

int irudiaKargatu(char* fileName)
{
    int colorkey;
    SDL_Surface* surface;

    if (irudiKop < MAX_IMG)
    {
        surface = SDL_LoadBMP(fileName);
        if (surface == NULL)
        {
            fprintf(stderr, "Couldn't load %s: %s\n", fileName, SDL_GetError());
            return -1;
        }
        else
        {
            colorkey = SDL_MapRGB(surface->format, 255, 0, 255);//kolore rosa kentzeko
            SDL_SetColorKey(surface, SDL_TRUE, colorkey);
            irudiak[irudiKop].texture = SDL_CreateTextureFromSurface(gRenderer, surface);
            irudiak[irudiKop].dest.x = irudiak[irudiKop].dest.y = 0;
            irudiak[irudiKop].dest.w = surface->w;
            irudiak[irudiKop].dest.h = surface->h;
            SDL_FreeSurface(surface);
            irudiak[irudiKop].id = id;
            irudiKop++;
            id++;
        }
    }
    else
    {
        printf("Has superado el maixmo de Imagens por aplicación.Para aumentar imagen.h\n");
        return -1;
    }

    return id - 1;
}


void irudiakMarraztu(void)
{
    int i = 0;

    for (i = 0; i < irudiKop; i++)
    {
        if (i == Surface_kop - 1)
        {
            camera = set_camera(camera);
            kamararekinMarraztu(camera, irudiak[i].texture, &irudiak[i].dest);
        }
        else
        {
            irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
        }
    }
}

int kamararekinMarraztu(SDL_Rect camera, SDL_Texture* texture, SDL_Rect* pDest)
{
    SDL_Rect clip = { 0, 0, 640, 480 };

   
    SDL_RenderCopy(gRenderer, texture, &camera, &clip);

    return 0;
}

int irudiarenPosizioaAurkitu(int id)
{
    int i = 0;

    for (i = 0; i < irudiKop; i++)
    {
        if (id == irudiak[i].id) return i;
    }
    return -1;
}

void  irudiaMugitu(int numImg, int x, int y)
{

    int id = 0;

    id = irudiarenPosizioaAurkitu(numImg);

    irudiak[id].dest.x = x;
    irudiak[id].dest.y = y;
}

void irudiaKendu(int id)
{
    int i = 0, pos = 0;

    pos = irudiarenPosizioaAurkitu(id);
    SDL_DestroyTexture(irudiak[pos].texture);
    SDL_DestroyTexture(irudiak[pos].texture);
    for (i = pos; i < irudiKop; i++)
    {

        irudiak[i] = irudiak[i + 1];
    }
    irudiKop--;
}

void pantailaGarbitu()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
}

int irudiaSortu(char* imgName)
{
    int img = -1;

    if (imgName == MUNDU_FINALA)
    {
        Surface_kop = irudiKop;
   }
    img = irudiaKargatu(imgName);
    irudiaMugitu(img, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();

    return img;
}