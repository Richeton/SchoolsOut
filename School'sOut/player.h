//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _PLAYER_H               // Prevent multiple definitions if this 
#define _PLAYER_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h";
#include "input.h";
#include <list>;
#include "projectile.h"

namespace playerNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 100;                // 100 pixels per second
	const int   TEXTURE_COLS = 8;           // texture has 8 columns			
}

class Player : public Entity
{
private:

public:

	Player();				//Default Constructor
	Player(Input &input);
	~Player();				//Destructor

	void update(float frameTime);
	void collisions();

};

#endif