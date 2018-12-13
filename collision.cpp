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
	// Player-Enemy
	if (target.getEntityType() == entityNS::ENTITY_TYPE::PLAYER && trigger.getEntityType() == entityNS::ENTITY_TYPE::RUGBYPLAYERS)
	{
		if (target.getX() < trigger.getX()) {
			target.setX(target.getX() - 1); trigger.setX(trigger.getX() + 1);
		}
		else {
			target.setX(target.getX() + 1); trigger.setX(trigger.getX() - 1);
		}

		if (target.getY() < trigger.getY()) {
			target.setY(target.getY() - 1); trigger.setY(trigger.getY() + 1);
		}
		else {
			target.setY(target.getY() + 1); trigger.setY(trigger.getY() - 1);
		}

		if (target.getVulnerable())
		{
			target.setHealth(target.getHealth() - 1);
			target.resetVulnerable();
		}
	}

	// Player-Projectile
	if (target.getEntityType() == entityNS::ENTITY_TYPE::PLAYER && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
	}

	// Enemy-Projectile
	if (target.getEntityType() == entityNS::ENTITY_TYPE::RUGBYPLAYERS && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
		//if (entityCollection->remove(&target))
		//{
		//	entityCollection->setIndex(entityCollection->getIndex() - 1);
		//	entityCollection->deleted = true;
		//}
		target.setVisible(false);
		target.setActive(false);

		trigger.setVisible(false);
		trigger.setActive(false);
	}

	// Table-Projectile
	if (target.getEntityType() == entityNS::ENTITY_TYPE::TABLE && trigger.getEntityType() == entityNS::ENTITY_TYPE::PROJECTILE)
	{
		//if (entityCollection->remove(&target))
		//{
		//	entityCollection->setIndex(entityCollection->getIndex() - 1);
		//	entityCollection->deleted = true;
		//}
		target.setVisible(false);
		target.setActive(false);

		trigger.setVisible(false);
		trigger.setActive(false);

	}

	// Enemy-Table
	if (target.getEntityType() == entityNS::ENTITY_TYPE::RUGBYPLAYERS && trigger.getEntityType() == entityNS::ENTITY_TYPE::TABLE)
	{
		target.setVisible(false);
		target.setActive(false);

		trigger.setVisible(false);
		trigger.setActive(false);
	}

	// Table-Table
	if (target.getEntityType() == entityNS::ENTITY_TYPE::TABLE && trigger.getEntityType() == entityNS::ENTITY_TYPE::TABLE)
	{
		if (target.getX() < trigger.getX()) {
			target.setX(target.getX() - 1); trigger.setX(trigger.getX() + 1);
		}
		else {
			target.setX(target.getX() + 1); trigger.setX(trigger.getX() - 1);
		}

		if (target.getY() < trigger.getY()) {
			target.setY(target.getY() - 1); trigger.setY(trigger.getY() + 1);
		}
		else {
			target.setY(target.getY() + 1); trigger.setY(trigger.getY() - 1);
		}
	}

	// Player-Table
	if (target.getEntityType() == entityNS::ENTITY_TYPE::PLAYER && trigger.getEntityType() == entityNS::ENTITY_TYPE::TABLE)
	{
		if (target.getX() < trigger.getX()) {
			target.setX(target.getX() - 1); trigger.setX(trigger.getX() + 1);
		}
		else {
			target.setX(target.getX() + 1); trigger.setX(trigger.getX() - 1);
		}

		if (target.getY() < trigger.getY()) {
			target.setY(target.getY() - 1); trigger.setY(trigger.getY() + 1);
		}
		else {
			target.setY(target.getY() + 1); trigger.setY(trigger.getY() - 1);
		}

	}

}