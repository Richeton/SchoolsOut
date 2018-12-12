//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "collision.h"
#include "collidedState.h"

Collision::Collision()
{
}

Collision::Collision(EntityCollection* ec)
{
	entityCollection = ec;
}

Collision::~Collision()
{
}

void Collision::run(Entity & trigger, Entity & target, VECTOR2 collisionVector)
{ 
	Entity* t = &target;

	
	if (target.getEntityType() == entityNS::ENTITY_TYPE::RUGBYPLAYERS && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
		if (entityCollection->remove(&target))
		{
			entityCollection->setIndex(entityCollection->getIndex() - 1);
			entityCollection->deleted = true;
		}
	}
	else if (target.getEntityType() != entityNS::ENTITY_TYPE::PLAYER)// && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
		collisionVector.x = target.getVelocity().x - trigger.getVelocity().x;
		collisionVector.y = target.getVelocity().y - trigger.getVelocity().y;
		trigger.setVelocity((collisionVector));
		target.setVelocity(-(collisionVector));
	}

	if (target.getEntityType() == entityNS::ENTITY_TYPE::PLAYER && trigger.getEntityType() == entityNS::ENTITY_TYPE::RUGBYPLAYERS)
	{
		if (target.getHealth() > 0)
		{
			target.setHealth(target.getHealth() - 1);
		}
		else
		{
			PostQuitMessage(0);
		}
		t->setAI(new CollidedState());
	}
}