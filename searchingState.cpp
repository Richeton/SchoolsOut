//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "searchingState.h"
#include "combatState.h"

SearchingState::SearchingState()
{

}

SearchingState::~SearchingState()
{
}

void SearchingState::ai(float frameTime, Enemy & ent, Entity & t)
{
	if (isEntityWithinRange(ent, t, 100))
	{
		// Combat AI
		ent.setAI(new CombatState());
	}
	else
	{
		D3DXVECTOR2 vel = D3DXVECTOR2(0, 0);
		vel = ent.getVelocity();
		if (vel.x < 0)
			vel.x += rand() % 2;
		else
			vel.x -= rand() % 2;
		if (vel.y < 0)
			vel.y += rand() % 2;
		else
			vel.y -= rand() % 2;
		if (abs(vel.x) < 10)
			vel.x = (rand() % 3 - 1) * 75;
		if (abs(vel.y) < 10)
			vel.y = (rand() % 3 - 1) * 75;
		ent.setVelocity(vel);
	}
}
