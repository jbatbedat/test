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
void courir();
void immobile();
int get_m_posX();

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

//attributs d'états du personnage
int m_sens;
bool m_courseOn;

};


#endif // PLAYER_H
