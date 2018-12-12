//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include <random>
#include "spawner.h"

Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

bool Spawner::enemySpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime)
{
	if (entityCollection->getEnemyCollection().size() <  spawnerNS::ENEMY_CAP)
	{
		// Internal timer for enemy to spawn
		enemyTimer -= frameTime;

		if (enemyTimer <= 0)
		{
			float randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - enemyNS::WIDTH) + GAME_BOUNDARY_XSTART;
			float randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - enemyNS::HEIGHT) + GAME_BOUNDARY_YSTART;

			float edgeLeft = player->getX() - spawnerNS::SPAWN_DISTANCE;
			float edgeRight = player->getX() + spawnerNS::SPAWN_DISTANCE;
			float edgeUp = player->getY() - spawnerNS::SPAWN_DISTANCE;
			float edgeDown = player->getY() + spawnerNS::SPAWN_DISTANCE;

			// Keep generating X and Y values until true
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

			// Create a new obstacle and initialize, then add into entityCollection
			Enemy* newEnemy = new Enemy();
			if (!newEnemy->initialize(&gamePtr, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &gameTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing enemy"));
			newEnemy->setEdge(enemyNS::EDGE_LEFT,enemyNS::EDGE_RIGHT, enemyNS::EDGE_TOP, enemyNS::EDGE_BOTTOM);
			newEnemy->setX(randPosX);
			newEnemy->setY(randPosY);
			entityCollection->add(newEnemy);

			// Reset timer
			enemyTimer = spawnerNS::ENEMY_TIMER;

			return true;
		}
	}
	return true;
}


bool Spawner::obstacleSpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime)
{	
	if (entityCollection->getObstacleCollection().size() < spawnerNS::OBSTACLE_CAP)
	{
		// Internal timer for obstacle to spawn
		obstacleTimer -= frameTime;
		if (obstacleTimer <= 0)
		{
			// Once timer reached

			// Define a random X and Y
			float randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - obstacleNS::WIDTH) + GAME_BOUNDARY_XSTART;
			float randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - obstacleNS::HEIGHT) + GAME_BOUNDARY_YSTART;

			// Define spawning boundary for player
			float edgeLeft = player->getX() - spawnerNS::SPAWN_DISTANCE;
			float edgeRight = player->getX() + spawnerNS::SPAWN_DISTANCE;
			float edgeUp = player->getY() - spawnerNS::SPAWN_DISTANCE;
			float edgeDown = player->getY() + spawnerNS::SPAWN_DISTANCE;

			// Keep generating X and Y values until true
			while (true)
			{
				if (!(edgeLeft > randPosX || edgeRight < randPosX || edgeUp > randPosY || edgeDown < randPosY))
				{
					randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - obstacleNS::WIDTH) + GAME_BOUNDARY_XSTART;
					randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - obstacleNS::HEIGHT) + GAME_BOUNDARY_YSTART;
					continue;
				}
				break;
			}

			// Create a new obstacle and initialize, then add into entityCollection
			Obstacle* newObstacle = new Obstacle();
			if (!newObstacle->initialize(&gamePtr, obstacleNS::WIDTH, obstacleNS::HEIGHT, obstacleNS::TEXTURE_COLS, &gameTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing obstacle"));
			newObstacle->setEdge(obstacleNS::EDGE_LEFT, obstacleNS::EDGE_RIGHT, obstacleNS::EDGE_TOP, obstacleNS::EDGE_BOTTOM);
			newObstacle->setX(randPosX);
			newObstacle->setY(randPosY);
			entityCollection->add(newObstacle);

			// Reset timer
			obstacleTimer = spawnerNS::OBSTACLE_TIMER;
			return true;
		}
	}
	return true;
}