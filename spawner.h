//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _SPAWNER_H
#define _SPAWNER_H
#define WIN32_LEAN_AND_MEAN

#include "entityCollection.h"
#include "player.h"
#include <vector>

namespace spawnerNS
{
	const float ENEMY_TIMER = 3;
	const float OBSTACLE_TIMER = 7;

	const UINT SPAWN_DISTANCE = 150;

	const int ENEMY_CAP = 10;				// only 3 enemies can spawn at any given time
	const int OBSTACLE_CAP = 10;				// only 3 obstacles can spawn at any given time
}

class Spawner
{
private:
	float enemyTimer = spawnerNS::ENEMY_TIMER;
	float obstacleTimer = spawnerNS::OBSTACLE_TIMER;

public:
	Spawner();
	~Spawner();
	bool enemySpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& enemyTexture, float frameTime);		
	bool obstacleSpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& obstacleTexture, float frameTime);
	
};

#endif