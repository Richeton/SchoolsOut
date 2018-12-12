//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _SCHOOLSOUT_H             // Prevent multiple definitions if this 
#define _SCHOOLSOUT_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "player.h"
#include "enemy.h"
#include "textureManager.h"
#include "image.h"
#include <list>
#include "enemySpawn.h"
#include "spawner.h"
#include "entityCollection.h"
#include "gui.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class SchoolsOut : public Game
{
private:

	// game items
	TextureManager stageTexture;	// stage texture
	TextureManager gameTexture;		// game texture
	Spawner spawner;
	EntityCollection entityCollection;

	Player* player = new Player();
	float nextShootTime = 0;		// used to calculate delay (timer)
	float fireRate = 2;				// shoots 2 bullets per second

	Image background;

	GUI_Window* guiwin;

public:
	// Constructor
	SchoolsOut();

	// Destructor
	virtual ~SchoolsOut();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
};

#endif
