//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "projectile.h"

Projectile::Projectile()
{
	collisionType = entityNS::COLLISION_TYPE::BOX;
	entityType = entityNS::ENTITY_TYPE::PROJECTILE;
}

Projectile::~Projectile()
{
}

void Projectile::update(float frameTime)
{
	Entity::update(frameTime);

	// Updates the x & y of the spriteData with relation
	// ... to the velocity * frameTime
	spriteData.x += this->velocity.x * frameTime;
	spriteData.y += this->velocity.y * frameTime;
}