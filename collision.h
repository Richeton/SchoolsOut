//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _COLLISION_H
#define _COLLISION_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "entityCollection.h"

class Collision
{
private:
	int timer = 3;

protected: 
	EntityCollection* entityCollection;
public:
	Collision();
	Collision(EntityCollection* ec);
	~Collision();

	// Default Collision (trigger entity affects target entity)
	void run(Entity & trigger, Entity & target, VECTOR2 collisionVector);		
};

#endif // !_COLLISION_H
