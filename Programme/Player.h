#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <SDL.h>
#include <SDL_image.h>



class Player
{
public:

Player();
Player(int posX, int posY);

void load();
void draw();
void freeSurface();

private:

int m_vie;
int m_posX;
int m_posY;
int m_tileX;
int m_tileY;
int m_hauteurTile;
int m_largeurTile;
std::string m_adresseSprite;
SDL_Surface *m_sprite;

};


#endif // PLAYER_H
