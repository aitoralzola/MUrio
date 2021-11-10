#ifndef SDLHASIERATU_H
#define SDLHASIERATU_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <SDL.h>
#include <time.h>
#include <SDL_ttf.h>
#include "SDL_image.h"
#include <SDL_mixer.h>
#define GAME_OVER -1
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define LEVEL_WIDTH = 800
#define LEVEL_HEIGHT = 1600
#define JOLASTEN 1
#define SARTU 2
#define IRTEN 3
#define SPEED 300
#define SALTO_MAPA 300
#define SALTO_NIBEL 1000
#define MAX_SOUNDS 10

int SDLHasi();
void bukatu();
int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest);
void textuaGaitu(void);
void textuaIdatzi(int x, int y, char* str);
void textuaDesgaitu(void);
void jokuaHasi(int pertsonaia);
void berrabiarazi();

SDL_Rect set_camera(SDL_Rect camera);
SDL_Renderer* gRenderer;

#endif
