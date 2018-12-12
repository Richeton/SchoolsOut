//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "state.h"
#include "enemy.h"

State::State()
{
}

State::~State()
{
}

void State::ai(float frameTime, Enemy & ent, Entity & t)
{

}

float State::getEntityDistXY(Enemy & ent, Entity & t)
{
	return abs(t.getX() - ent.getX()) + abs(t.getY() - ent.getY());
}

bool State::isEntityWithinRange(Enemy & ent, Entity & t, float dist)
{
	if (getEntityDistXY(ent, t) < dist)
		return true;
	return false;
}