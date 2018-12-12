//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _COMBATSTATE_H            // Prevent multiple definitions if this 
#define _COMBATSTATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "state.h"
#include "enemy.h"

class Entity;

class CombatState : public State
{
private:
	float attackDuration; // Attack duration
	float tempAttackDuration;
	float attackDist; // Attack Distance
	D3DXVECTOR2 direction;

public:
	CombatState();
	~CombatState();

	void ai(float frameTime, Enemy & ent, Entity & t);
};

#endif