//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "enemy.h"
#include "searchingState.h"

Enemy::Enemy()
{
	setCurrentFrame(enemyNS::ENEMY_DEFAULT_FRAME);
	collisionType = entityNS::COLLISION_TYPE::BOX;
	entityType = entityNS::ENTITY_TYPE::RUGBYPLAYERS;
}

Enemy::~Enemy() {}

void Enemy::update(float frameTime)
{
	spriteData.x += this->velocity.x * frameTime;
	spriteData.y += this->velocity.y * frameTime;
	if (getY() <= (GAME_BOUNDARY_YSTART))
		setY((float)GAME_BOUNDARY_YSTART);
	else if (getY() >= (GAME_BOUNDARY_YEND))
		setY((float)GAME_BOUNDARY_YEND - getHeight());
	if (getX() <= (GAME_BOUNDARY_XSTART))
		setX((float)GAME_BOUNDARY_XSTART);
	else if (getX() >= (GAME_BOUNDARY_XEND - getWidth()))
		setX((float)GAME_BOUNDARY_XEND - getWidth());
}

void Enemy::ai(float frameTime, Entity &ent)
{
	Entity::ai(frameTime, ent);
	if (aiState)
	{
		aiState->ai(frameTime,*this, ent);
	}
	else
		setAI(new SearchingState());
}




