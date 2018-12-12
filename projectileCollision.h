#pragma once
#include "collision.h"
#include "entityCollection.h"

class ProjectileCollision : public Collision
{
public:
	ProjectileCollision();
	ProjectileCollision(EntityCollection* ec);
	~ProjectileCollision();
	void run(Entity & ent, Entity & t, VECTOR2 collisionVector);
};

