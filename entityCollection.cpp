//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "entityCollection.h"
#include <algorithm>
#include "enemy.h"

// adds an entity into the entityCollection list
bool EntityCollection::add(Entity* entity)
{
	entityCollection.push_back(entity);
	return true;
}

bool EntityCollection::add(Enemy* enemy)
{
	add((Entity*)enemy);
	enemyCollection.push_back(enemy);
	return true;
}

bool EntityCollection::add(Obstacle * obstacle)
{
	add((Entity*)obstacle);
	obstacleCollection.push_back(obstacle);
	return true;
}

bool EntityCollection::add(Projectile* projectile)
{
	add((Entity*)projectile);
	projCollection.push_back(projectile);
	return true;
}

// deletes an entity from the entityCollection list by entity's name
bool EntityCollection::remove(Entity* en)
{
	// create iterator here
	int i = -1;
	for (const auto entity : entityCollection)
	{
		i++;
		// put iterator here
		if (en == entity)
		{
			entityCollection.erase(entityCollection.begin() + i);
			return true;
		}
	}

	return false; // entity not found
}

bool EntityCollection::remove(Enemy* enemy)
{
	// create iterator here
	int i = 0;
	for (const auto en : enemyCollection)
	{
		i++;
		// put iterator here
		if (&en == &enemy)
		{
			enemyCollection.erase(enemyCollection.begin() + i);
			return true;
		}
	}

	return false; // entity not found
}

bool EntityCollection::remove(Obstacle* obstacle)
{
	// create iterator here
	int i = 0;
	for (const auto obs : obstacleCollection)
	{
		i++;
		// put iterator here
		if (&obs == &obstacle)
		{
			projCollection.erase(projCollection.begin() + i);
			return true;
		}
	}

	return false; // entity not found
}

bool EntityCollection::remove(Projectile* proj)
{
	// create iterator here
	int i = 0;
	for (const auto projectile : projCollection)
	{
		i++;
		// put iterator here
		if (&projectile == &proj)
		{
			projCollection.erase(projCollection.begin() + i);
			return true;
		}
	}

	return false; // entity not found
}




// gets an entity from the entityCollection list using the entity's index
Entity* EntityCollection::get(int i)
{
	return entityCollection.at(i);
}

Enemy* EntityCollection::getEnemy(int i)
{
	return enemyCollection.at(i);
}

std::vector<Enemy*> EntityCollection::getEnemyCollection()
{
	return enemyCollection;
}

Obstacle * EntityCollection::getObstacle(int i)
{
	return obstacleCollection.at(i);
}

std::vector<Obstacle*> EntityCollection::getObstacleCollection()
{
	return std::vector<Obstacle*>();
}

Projectile * EntityCollection::getProjectile(int i)
{
	return projCollection.at(i);
}

// update for all entities
bool EntityCollection::update(float frameTime)
{
	for (const auto entity : entityCollection)
	{
		entity->update(frameTime);
	}
	//for (const auto projectile : projCollection)
	//{
	//	projectile->update(frameTime);
	//}
	return true;
}


// ai for all entities
bool EntityCollection::ai(float frameTime, Entity* en)
{
	for (const auto entity : entityCollection)
	{
		entity->ai(frameTime, *en);
	}	
	return true;
}

// collision for all entities
bool EntityCollection::collision()
{
	int iIndex = -1;
	std::vector<Entity*>::iterator eFront = entityCollection.begin(); // First entity iterates end
	while (eFront != entityCollection.end() - 1)
	{
		iIndex++;
		std::vector<Entity*>::iterator eBack = entityCollection.end(); // The last entity iterate to eFront
		D3DXVECTOR2 collVector;
		while (eBack != entityCollection.begin() + iIndex + 1)
		{
			eBack--;
			// For each Entity, it will collide with each Entity ONCE and ONLY ONCE
			if ((*eFront)->collidesWith((**eBack), collVector))
			{
				// Action after Collision
				(*eFront)->collidedWith(**eBack, collVector, *this);
			}
		}
		//// Bullet Collision
		//std::vector<Projectile*>::iterator pFront = projCollection.begin();
		//while (pFront != projCollection.end())
		//{
		//	if ((*eFront)->collidesWith((**pFront), collVector))
		//	{
		//		// Action after Projectile Collision (with other entity)
		//		(*eFront)->collidedWith(**pFront, collVector, *this);
		//	}
		//	pFront++;
		//}
		eFront++;
	}
	return true;
}

// render for all entities
bool EntityCollection::render()
{
	for (const auto entity : entityCollection)
	{
		entity->draw();
	}
	/*for (const auto projectile : projCollection)
	{
		projectile->draw();
	}*/
	return true;
}

//void EntityCollection::enemyPlayerCollision(Player* player, float frameTime)
//{
	/*
	D3DXVECTOR2 colVect;

	for (const auto enemy : entityCollection)
	{

		if (enemy->collidesWith(*player, colVect))
		{
			if (player->getTakenDamage() == false)
			{
				player->setHealth(player->getHealth() - 10);
				player->setTakenDamage(true);
				player->setInvulnerabilityFrame(3);
			}
			else
			{
				player->setInvulnerabilityFrame(player->getInvulnerabilityFrame() - frameTime);
				if (player->getInvulnerabilityFrame() <= 0)
				{
					player->setTakenDamage(false);
				}
			}

		}

	}	
	*/
//}