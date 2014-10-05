#include "boucle.h"

//Met le jeu en pause tant que 16ms (1 frame) ne se sont pas écoulées. Réinitialise le timer au début de chaque boucle
void pause(void)
{
    while(SDL_GetTicks()-timer<16)
    {

    }
    timer=SDL_GetTicks();
}
