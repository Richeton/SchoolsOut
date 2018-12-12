#ifndef _ENEMYSPAWN_H
#define _ENEMYSPAWN_H
#define WIN32_LEAN_AND_MEAN

#include "enemy.h"
#include "game.h"
#include "player.h"
#include <vector>


namespace enemySpawnNS
{
	const int ENEMY_CAP = 30;                   // image width
}

// Providing an algorithm for the Entity To Spawn
class EnemySpawn 
{
private:
	std::vector<Enemy*> enemySpawner;
	float enemyTimer = 2.0f; // default timer: every 8 seconds, an enemy spawns
	float invulnerabilityFrame = 3.0f;
public:
	// Adds an enemy pointer into the enemySpawner vector
	bool addEnemy(Enemy* en);

	// Deletes an enemy pointer from the enemySpawner vector
	bool deleteEnemy(Enemy* en);

	// Deletes an enemy pointer from the enemySpawner vector (based on index)
	bool deleteEnemy(int i);

	// Gets the enemy (based on index)
	Enemy* getEnemy(int i);

	// Updates all the enemies (per frame)
	bool enemyUpdate(float frameTime);

	// AIs for all the enemies
	bool enemyAI(float frameTime, Player* player);

	// Collision for all the enemies
	bool enemyCollision(Player* player, float frameTime);

	// Rendering for all the enemies
	bool enemyRender();

	// Setting the spawn mechanics for the enemy
	bool spawnEnemy(Game &gamePtr, TextureManager &gameTexture, Player player, float frameTime);
};

#endif