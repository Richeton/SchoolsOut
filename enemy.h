//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _ENEMY_H            // Prevent multiple definitions if this 
#define _ENEMY_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "state.h"

namespace enemyNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height

	const int   TEXTURE_COLS = 8;           // texture has 8 columns


	const int EDGE_LEFT = -8;
	const int EDGE_RIGHT = 8;
	const int EDGE_TOP = -15;
	const int EDGE_BOTTOM = 15;

	const UINT ENEMY_DEFAULT_FRAME = 17;


	const int ALERT_DIST = 300;
	const int BASE_SPEED = 75;
	
}


class Enemy : public Entity
{
private:

public:
	Enemy();	//Constructor
	~Enemy();	//Destructor

	void update(float frameTime);

	void ai(float frameTime, Entity &ent);	// Execute the AI


};

#endif
