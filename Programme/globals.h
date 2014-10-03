#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED



#endif // GLOBALS_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include <string>
using namespace std;



extern SDL_Surface *ecran;
extern SDL_Surface *background;
extern SDL_Surface *sprite;
extern SDL_Event event;
extern void init();
extern void load();
extern void touches();
extern bool done;
extern void drawback();
extern void drawsprites(SDL_Surface *sprite, int destX, int destY, int srcX, int srcY);
extern SDL_Rect dstrect;

