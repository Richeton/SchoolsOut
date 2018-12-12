//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _ENTITYCOLLECTION_H
#define _ENTITYCOLLECTION_H
#define WIN32_LEAN_AND_MEAN

#include <vector>
#include "entity.h"
#include "player.h"
#include "obstacle.h"
#include "enemy.h"
#include "projectile.h"

// Store and Execute Functions on Entities
class EntityCollection
{
private:
	Player* playerPtr;
	std::vector<Entity*> entityCollection;
	std::vector<Enemy*> enemyCollection;
	std::vector<Obstacle*> obstacleCollection;
	std::vector<Projectile*> projCollection;
	int index; // Used to loop through.

public:
	bool deleted;
	bool add(Entity* entity);
	bool add(Enemy* enemy);
	bool add(Obstacle* projectile);
	bool add(Projectile* projectile);
	

	bool remove(Entity* entity);
	bool remove(Enemy* enemy);
	bool remove(Obstacle* obstacle);
	bool remove(Projectile* projectile);

	Entity* get(int i);
	Enemy* getEnemy(int i);
	
	std::vector<Enemy*> getEnemyCollection();

	Obstacle* getObstacle(int i);
	std::vector<Obstacle*> getObstacleCollection();

	Projectile* getProjectile(int i);

	bool update(float frameTime);
	bool ai(float frameTime, Entity * en);
	bool collision();
	bool render();

	int getIndex() { return index; }
	void setIndex(int i) { index = i; }

};


#endif // _entityCollection_H
