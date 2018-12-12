//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _OBSTACLE_H            // Prevent multiple definitions if this 
#define _OBSTACLE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace obstacleNS
{
	const int WIDTH = 64;                   // image width
	const int HEIGHT = 64;                  // image height

	const int EDGE_LEFT = -25;
	const int EDGE_RIGHT = 25;
	const int EDGE_TOP = -30;
	const int EDGE_BOTTOM = 30;

	const int TEXTURE_COLS = 8;           // texture has 8 columns

	const int OBSTACLE_DEFAULT_FRAME = 17;
			
	
}

class Obstacle : public Entity
{
private:
	
public:
	Obstacle();	//Constructor
	~Obstacle();	//Destructor

	void update(float frameTime);
	void collisions();
};

#endif
