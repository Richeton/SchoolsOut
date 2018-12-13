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
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height

	const int EDGE_LEFT = -12;
	const int EDGE_RIGHT = 12;
	const int EDGE_TOP = -15;
	const int EDGE_BOTTOM = 15;

	const int TEXTURE_COLS = 2;           // texture has 8 columns

			
	
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
