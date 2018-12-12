//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "collidedState.h"
#include "searchingState.h"

CollidedState::CollidedState()
{
	collidedTime = 0.5;
	collVector = NULL;

}

CollidedState::~CollidedState()
{
}

void CollidedState::ai(float frameTime, Enemy & ent, Entity & t)
{
	collidedTime -= frameTime;

	if (collidedTime <= 0)
	{
		SAFE_DELETE(collVector);
		ent.setAI(new SearchingState());
	}
	


}
