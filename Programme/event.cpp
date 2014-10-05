#include "event.h"

void touches()
{

        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // On fait correspondre les actions disponibles aux inputs. On switch en On les input correspondants aux touches enfoncées
                    if (event.key.keysym.sym == SDLK_x)
                        {
                        Input1.m_quit=1;}
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                        Input1.m_space=1;}
                    if (event.key.keysym.sym == SDLK_UP)
                        {
                        Input1.m_up=1;}
                    if (event.key.keysym.sym == SDLK_DOWN)
                        {
                        Input1.m_down=1;}
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        {
                        Input1.m_right=1;}
                    if (event.key.keysym.sym == SDLK_LEFT)
                        {
                        Input1.m_left=1;}
                    break;

            //On switch les input en off si les touches correspondantes ne sont pas enfoncées
            case SDL_KEYUP:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        Input1.m_space=0;
                    if (event.key.keysym.sym == SDLK_UP)
                        Input1.m_up=0;
                    if (event.key.keysym.sym == SDLK_DOWN)
                        Input1.m_down=0;
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        Input1.m_right=0;
                    if (event.key.keysym.sym == SDLK_LEFT)
                        Input1.m_left=0;
                    break;
                }
            }
        }
    }
}

