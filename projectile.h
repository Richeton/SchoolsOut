//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _PROJECTILE_H               // Prevent multiple definitions if this 
#define _PROJECTILE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h";

namespace projectileNS
{
	const int	WIDTH = 32;							// image width
	const int	HEIGHT = 32;						// image height
	const float SPEED = 100;						// 100 pixels per second
	const int   TEXTURE_COLS = 1;
}

class Projectile : public Entity
{
private:
	int quantity;	// number of projectile
	int damage;		// damage of the projectile
	float speed;	// projectile speed (pixels traveled per second)
	bool collide;	// checks to see if the projectile has collided

public:

	Projectile();	// Default Constructor
	~Projectile();	// Destructor

	// Projectile update
	void update(float frameTime);

	// Returns the quantity
	int getQuantity() { return quantity; }
	// Returns the damage
	int getDamage() { return damage; }

	// Returns the state of collide
	bool getCollide() { return collide; }
	// Sets the state of collide
	void setCollide(bool b) { collide = b; }

};

#endif