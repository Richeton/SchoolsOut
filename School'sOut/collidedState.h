//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef  _COLLIDEDSTATE_H
#define _COLLIDEDSTATE_H
#define WIN32_LEAN_AND_MEAN

#include "state.h"
#include "enemy.h"

class CollidedState : public State
{
private:
	float collidedTime; // Stop time after colliding
	VECTOR2* collVector;

public:
	CollidedState();
	~CollidedState();

	void ai(float frameTime, Enemy & ent, Entity & t);
};

#endif // ! _COLLIDEDSTATE_H
