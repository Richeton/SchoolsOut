//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "combatState.h"

CombatState::CombatState() : State()
{
}

CombatState::~CombatState()
{
}

void CombatState::ai(float frameTime, Enemy & ent, Entity & t)
{
	D3DXVECTOR2 toVector = D3DXVECTOR2(t.getCenterX() - ent.getCenterX(), t.getCenterY() - ent.getCenterY()); // Direction from AI Enemy to Player
	D3DXVECTOR2 vel = D3DXVECTOR2(0, 0);
	
	if (attackDuration <= 0)
		if (isEntityWithinRange(ent, t, enemyNS::ALERT_DIST))
		// Character moves up and down till it reaches the player Y axis
			if (toVector.y > (t.getHeight()/2))
			{
				vel.y = enemyNS::BASE_SPEED;
			}
			else if (toVector.y < (-t.getHeight()/2))
			{
				vel.y = -enemyNS::BASE_SPEED;
			}
			else
			{
				// If the Character is on the player Y axis, Attack(Rush) for set seconds
				attackDuration = 1;
				if (toVector.x > 0)
					direction.x = 1;
				else
					direction.x = -1;
			}
		else
		{
			// Move towards the player
			if (toVector.y > t.getHeight())
			{
				vel.y = enemyNS::BASE_SPEED;
			}
			else if (toVector.y < -t.getHeight())
			{
				vel.y = -enemyNS::BASE_SPEED;
			}
			if (toVector.x > t.getWidth())
			{
				vel.x = enemyNS::BASE_SPEED;
			}
			else if (toVector.x < -t.getHeight())
			{
				vel.x = -enemyNS::BASE_SPEED;
			}
		}
	// If the enemy is close enough, he will rush towards the target
	if (attackDuration > 0)
	{
		attackDuration -= frameTime;
		vel.x = enemyNS::BASE_SPEED * direction.x * 4;
	}
	ent.setVelocity(vel);
}
