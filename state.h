//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _STATE_H            // Prevent multiple definitions if this 
#define _STATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

class Entity;
class Enemy;

class State
{
private:

public:
	State();
	~State();

	virtual void ai(float frameTime, Enemy & ent, Entity & t);

	float getEntityDistXY(Enemy & ent, Entity & t);
	bool isEntityWithinRange(Enemy & ent, Entity & t, float dist);

};

#endif