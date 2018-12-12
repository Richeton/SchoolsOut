#include <algorithm>
#include <random>
#include "enemySpawn.h"


// adds an entity into the entityCollection list
bool EnemySpawn::addEnemy(Enemy* en)
{
	enemySpawner.push_back(en);
	return true;
}


// deletes an entity from the entityCollection list by entity's name
bool EnemySpawn::deleteEnemy(Enemy* en)
{
	// create iterator here
	int i = 0;
	for (const auto enemy : enemySpawner)
	{
		i++;
		// put iterator here
		if (&en == &enemy)
		{			
			enemySpawner.erase(enemySpawner.begin() + i);
			
			return true;
		}
	}

	return false; // entity not found
}


// deletes an entity from the entityCollection list by entity's index
bool EnemySpawn::deleteEnemy(int i)
{
	return true;
}



// gets an entity from the entityCollection list using the entity's index
Enemy* EnemySpawn::getEnemy(int i)
{	
	return enemySpawner[i];
	
}

// update for all entities
bool EnemySpawn::enemyUpdate(float frameTime)
{
	for (const auto enemy : enemySpawner)
	{
		enemy->update(frameTime);
	}
	return true;
}


// ai for all entities
bool EnemySpawn::enemyAI(float frameTime, Player* player)
{
	for (const auto enemy : enemySpawner)
	{
		enemy->ai(frameTime, *player);
	}
	return true;
}

// collision for all entities
bool EnemySpawn::enemyCollision(Player* player,float frameTime)
{
	D3DXVECTOR2 colVect;
	for (const auto enemy : enemySpawner)
	{
	
		if (enemy->collidesWith(*player, colVect))
		{
			if (player->getTakenDamage() == false) 
			{
				player->setHealth(player->getHealth() - 10);
				player->setTakenDamage(true);
				invulnerabilityFrame = 5.0f;
			}
			else
			{
				invulnerabilityFrame -= frameTime;
				if (invulnerabilityFrame <= 0)
				{
					player->setTakenDamage(false);
				}
			}	
			enemy->setVelocity(enemy->getVelocity()*-1);						
		}
	}
	return true;
}

//// render for all entities
//bool EnemySpawn::enemyRender()
//{
//	for (const auto enemy : enemySpawner)
//	{		
//		enemy->draw();		
//	}
//	return true;
//}


bool EnemySpawn::spawnEnemy(Game& gamePtr, TextureManager &gameTexture, Player player,float frameTime)
{	
	if (enemySpawner.size() < 2 )// enemySpawnNS::ENEMY_CAP)
	{
		enemyTimer -= frameTime;
		if (enemyTimer <= 0)
		{	
			enemyTimer = 2;
			float randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - enemyNS::WIDTH) + GAME_BOUNDARY_XSTART;
			float randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - enemyNS::HEIGHT) + GAME_BOUNDARY_YSTART;

			float edgeLeft = player.getX() - 100;
			float edgeRight = player.getX() + 100;
			float edgeUp = player.getY() - 100;
			float edgeDown = player.getY() + 100;
			
			while (true)
			{
				if (!(edgeLeft > randPosX || edgeRight < randPosX || edgeUp > randPosY || edgeDown < randPosY))
				{
					randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - enemyNS::WIDTH) + GAME_BOUNDARY_XSTART;
					randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - enemyNS::HEIGHT) + GAME_BOUNDARY_YSTART;
					continue;
				}
				break;
			}
			


			Enemy* newEnemy = new Enemy();
			if (!newEnemy->initialize(&gamePtr, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &gameTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing enemy"));
			newEnemy->setEdge(-8,8,-15,15);
			newEnemy->setX(randPosX);
			newEnemy->setY(randPosY);
			this->addEnemy(newEnemy);			

			return true;
		}
	}
	
	return true;
	
	
}