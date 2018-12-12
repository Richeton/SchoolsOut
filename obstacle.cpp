//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "obstacle.h"


Obstacle::Obstacle()
{
	setCurrentFrame(17);
	setScale(0.5);
	collisionType = entityNS::COLLISION_TYPE::BOX;
	entityType = entityNS::ENTITY_TYPE::TABLE;
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(float frameTime)
{
	Entity::update(frameTime);
	VECTOR2 friction = velocity.operator/=(10);
	spriteData.x += this->velocity.x * frameTime * friction.x;
	spriteData.y += this->velocity.y * frameTime * friction.y;
}

void Obstacle::collisions()
{
	
}

