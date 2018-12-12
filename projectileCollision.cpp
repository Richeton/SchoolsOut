#include "projectileCollision.h"



ProjectileCollision::ProjectileCollision()
{
}

ProjectileCollision::ProjectileCollision(EntityCollection* ec)
{
	entityCollection = ec;
}


ProjectileCollision::~ProjectileCollision()
{
}

// run: trigger(Projectile) and target(Target) collides
void ProjectileCollision::run(Entity & trigger, Entity & target, VECTOR2 collisionVector)
{
	// if entity is not the player
	if (target.getEntityType() != entityNS::ENTITY_TYPE::PLAYER && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
		entityCollection->remove(&target);
	}
}
		
