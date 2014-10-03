#include "draw.h"

void drawback()
{

        // clear screen
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        // draw background
        SDL_BlitSurface(background, 0, ecran, &dstrect);


}


