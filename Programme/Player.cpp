#ifndef PLAYER_CPP_INCLUDED
#define PLAYER_CPP_INCLUDED



#endif // PLAYER_CPP_INCLUDED

#include "Player.h"
#include "Input.h"
#include "timers.h"
extern Input Input1;
extern SDL_Surface *background;
extern SDL_Surface *ecran;

Player::Player():  m_vie(100), m_posX(0), m_posY(500), m_tileX(1),
m_tileY(1), m_hauteurTile(75), m_largeurTile(38), m_adresseSprite("images/sprite.png"),
m_sprite(0), m_sens(1), m_courseOn(0)
{
}

Player::Player(int posX, int posY):  m_vie(100), m_posX(posX), m_posY(posY), m_tileX(1),
m_tileY(1), m_hauteurTile(75), m_largeurTile(38), m_adresseSprite("images/sprite.png"),
m_sprite(0), m_sens(1), m_courseOn(0)
{
}

void Player::freeSurface()
{
    SDL_FreeSurface(m_sprite);
}

void Player::load()
{
    m_sprite = IMG_Load("images/sprite.png");

    if (!m_sprite)
    {
        printf("Unable to load sprite: %s\n", SDL_GetError());
        exit(1);
    }

}

int Player::get_m_posX()
{
    return m_posX;
}

void Player::draw()
{
    SDL_Rect dest;
    dest.x=m_posX;
    dest.y=m_posY;

    SDL_Rect src;
    src.x=(m_tileX-1)*m_largeurTile;
    src.y=(m_tileY-1)*m_hauteurTile;
    src.w=m_largeurTile;
    src.h=m_hauteurTile;
    // draw sprite
    SDL_BlitSurface(m_sprite, &src, background, &dest);

}


//Vérifie qu'aucune action n'est en cours et affiche la tile correspondante à l'inaction
void Player::immobile()
{
    if(m_courseOn==0 && m_sens==1)
    {
        m_tileY=1;
        m_tileX=1;
    }

    if(m_courseOn==0 && m_sens==2)
    {
        m_tileY=2;
        m_tileX=1;
    }
}

//Peut courir vers la droite ou la gauche
void Player::courir()
{
    //Réinitialise le status de course en Off si aucune touche directionnelle n'est enfoncée alors que le status est encore en On
    if(m_courseOn && !Input1.m_right && !Input1.m_left)
    {
        m_courseOn=0;

    }

    if(Input1.m_right)
       {
           //On vérifie qu'on commence à courir et on initialise les status et timers
           if(!m_courseOn)
           {
               m_tileY=3;
               m_sens=1;
               m_courseOn=1;
               rtCourse=SDL_GetTicks();
               rtInterval=SDL_GetTicks();
           }

           //On affiche la tile suivante à chaque boucle
           if(m_tileX<4)
           m_tileX++;
           //Si on est à la dernière tile on revient à la première
           else
            m_tileX=1;
            //Première étape d'accélèration
           if(SDL_GetTicks()-rtCourse<tCourse1)
           m_posX=m_posX+3;
           //Seconde étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse1 && SDL_GetTicks()-rtCourse<tCourse2)
           m_posX=m_posX+5;
           //Troisième étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse2 && SDL_GetTicks()-rtCourse<tCourse3)
           m_posX=m_posX+9;
           //4ème étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse3 && SDL_GetTicks()-rtCourse<tCourse4)
           m_posX=m_posX+13;
           //5ème étape d'accélération
           if(SDL_GetTicks()-rtCourse>=tCourse4 && SDL_GetTicks()-rtCourse<tCourse5)
           m_posX=m_posX+19;
           //Vitesse max
           if(SDL_GetTicks()-rtCourse>=tCourse5)
            m_posX=m_posX+23;


       }

    if(Input1.m_left)
       {
           if(!m_courseOn)
           {
               m_tileY=4;
               m_sens=2;
               m_courseOn=1;
               rtCourse=SDL_GetTicks();
               rtInterval=SDL_GetTicks();
           }
           if(m_tileX<4)
           m_tileX++;
           else
            m_tileX=1;
           if(SDL_GetTicks()-rtCourse<tCourse1)
           m_posX=m_posX-3;
           if(SDL_GetTicks()-rtCourse>=tCourse1 && SDL_GetTicks()-rtCourse<tCourse2)
           m_posX=m_posX-5;
           if(SDL_GetTicks()-rtCourse>=tCourse2 && SDL_GetTicks()-rtCourse<tCourse3)
           m_posX=m_posX-9;
           if(SDL_GetTicks()-rtCourse>=tCourse3 && SDL_GetTicks()-rtCourse<tCourse4)
           m_posX=m_posX-13;
           if(SDL_GetTicks()-rtCourse>=tCourse4 && SDL_GetTicks()-rtCourse<tCourse5)
           m_posX=m_posX-19;
           if(SDL_GetTicks()-rtCourse>=tCourse5)
            m_posX=m_posX-23;


       }
}


