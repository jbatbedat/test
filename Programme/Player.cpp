#ifndef PLAYER_CPP_INCLUDED
#define PLAYER_CPP_INCLUDED



#endif // PLAYER_CPP_INCLUDED

#include "Player.h"

extern SDL_Surface *ecran;

Player::Player():  m_vie(100), m_posX(0), m_posY(500), m_tileX(1),
m_tileY(1), m_hauteurTile(200), m_largeurTile(100), m_adresseSprite("images/sprite.png"),
m_sprite(0)
{
}

Player::Player(int posX, int posY):  m_vie(100), m_posX(posX), m_posY(posY), m_tileX(1),
m_tileY(1), m_hauteurTile(200), m_largeurTile(100), m_adresseSprite("images/sprite.png"),
m_sprite(0)
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
        SDL_BlitSurface(m_sprite, &src, ecran, &dest);

}
