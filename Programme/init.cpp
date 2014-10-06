#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "init.h"


void init(void)
{

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        exit(1);
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    ecran = SDL_SetVideoMode(640, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !ecran )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        exit(1);
    }
}


void load()
{
        // load an image
    background = IMG_Load("images/background.png");
    if (!background)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        exit(1);
    }
}
