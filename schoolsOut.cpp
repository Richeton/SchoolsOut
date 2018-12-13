//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "schoolsOut.h"
#include <ctime>

//=============================================================================
// Constructor
//=============================================================================
SchoolsOut::SchoolsOut()
{
	guiwin = new GUI_Window();
}

//=============================================================================
// Destructor
//=============================================================================
SchoolsOut::~SchoolsOut()
{
	SAFE_DELETE(guiwin);
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SchoolsOut::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError
	time_t t;
	srand(time(&t));

	// stage texture
	if (!stageTexture.initialize(graphics, STAGE_BACKGROUND))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing stage texture"));

	// main game textures
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing player texture"));

	if (!enemyTexture.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing enemy texture"));

	if (!obstacleTexture.initialize(graphics, OBSTACLE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing obstacle texture"));

	if (!bulletTexture.initialize(graphics, BULLET_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing bullet texture"));

	// background
	if (!background.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &stageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing background"));


	// player
	if (!player->initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &playerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing player"));

	entityCollection.add(player);


	player->setEdge(-8, 8, -15, 15);


	// Set player position to a center of the game boundaries
	player->setX(GAME_BOUNDARY_XSTART + (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART) / 2);
	player->setY(GAME_BOUNDARY_YSTART + (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART) / 2);

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SchoolsOut::update()
{
	// This is for the 'Up' arrow key
	// Player shoots up when pressed
	if (input->isKeyDown(VK_UP))
	{
		if (nextShootTime >= (1 / fireRate))
		{
			// Creates a projectile
			Projectile* p = new Projectile();
			p->setX(player->getX());
			p->setY(player->getY());
			entityCollection.add(p);

			// Initialize the projectile
			if (!p->initialize(this, projectileNS::WIDTH, projectileNS::HEIGHT,
				projectileNS::TEXTURE_COLS, &bulletTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing projectiles"));

			p->setScale(0.4);
			p->setDegrees(90);
			// '0' for x because it only moves in the y-axis
			// '-' because it moves ^^^
			p->setVelocity(D3DXVECTOR2(0, -projectileNS::SPEED));
			nextShootTime = 0;
		}

		player->setLoop(false);
		player->setCurrentFrame(13);
		player->setFrames(13, 15);
		player->setFrameDelay(0.1);

	}


	// This is for the 'Down' arrow key
	// Player shoots down when pressed
	if (input->isKeyDown(VK_DOWN))
	{
		if (nextShootTime >= (1 / fireRate))
		{
			// Creates a projectile
			Projectile* p = new Projectile();
			p->setX(player->getX());
			p->setY(player->getY());
			entityCollection.add(p);

			// Initialize the projectile
			if (!p->initialize(this, projectileNS::WIDTH, projectileNS::HEIGHT,
				projectileNS::TEXTURE_COLS, &bulletTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing projectiles"));

			p->setScale(0.4);
			p->setDegrees(270);

			// '0' for x because it only moves in the y-axis
			// '+' because it moves vvv
			p->setVelocity(D3DXVECTOR2(0, projectileNS::SPEED));
			nextShootTime = 0;
		}

		player->setLoop(false);
		player->setCurrentFrame(1);
		player->setFrames(1, 3);
		player->setFrameDelay(0.1);
	}

	// This is for the 'Left' arrow key
	// Player shoots left when pressed
	if (input->isKeyDown(VK_LEFT))
	{
		if (nextShootTime >= (1 / fireRate))
		{
			// Creates a projectile
			Projectile* p = new Projectile();
			p->setX(player->getX());
			p->setY(player->getY());
			entityCollection.add(p);

			// Initialize the projectile
			if (!p->initialize(this, projectileNS::WIDTH, projectileNS::HEIGHT,
				projectileNS::TEXTURE_COLS, &bulletTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing projectiles"));

			p->setScale(0.4);
			p->setDegrees(0);

			// '0' for y because it only moves in the x-axis
			// '-' because it moves <---
			p->setVelocity(D3DXVECTOR2(-projectileNS::SPEED, 0));
			nextShootTime = 0;
		}

		player->setLoop(false);
		player->setCurrentFrame(5);
		player->setFrames(5, 7);
		player->setFrameDelay(0.1);
	}

	// This is for the 'Right' arrow key
	// Player shoots right when pressed
	if (input->isKeyDown(VK_RIGHT))
	{
		if (nextShootTime >= (1 / fireRate))
		{
			// Creates a projectile
			Projectile* p = new Projectile();
			p->setX(player->getX());
			p->setY(player->getY());
			entityCollection.add(p);

			// Initialize the projectile
			if (!p->initialize(this, projectileNS::WIDTH, projectileNS::HEIGHT,
				projectileNS::TEXTURE_COLS, &bulletTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing projectiles"));

			p->setScale(0.4);
			p->setDegrees(180);

			// '0' for y because it only moves in the x-axis
			// '+' because it moves --->
			p->setVelocity(D3DXVECTOR2(projectileNS::SPEED, 0));
			nextShootTime = 0;
		}

		player->setLoop(false);
		player->setCurrentFrame(9);
		player->setFrames(9, 11);
		player->setFrameDelay(0.1);
	}

	nextShootTime += frameTime;

	//-------------------------------------------------------------
	spawner.enemySpawn(&entityCollection, player, *this, enemyTexture, frameTime);
	spawner.obstacleSpawn(&entityCollection, player, *this, obstacleTexture, frameTime);
	entityCollection.update(frameTime);
	guiwin->update(*player);

	// Handling Player Invulnerability
	player->updateVulnerableTimer(frameTime);

	// Handle when Player health hits 0, change game state to 2 (Game Over)
	if (player->getHealth() <= 0)
		game_state = 2;
	
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SchoolsOut::ai()
{
	// enemies ai follows player
	entityCollection.ai(frameTime, player);


}

//=============================================================================
// Handle collisions
//=============================================================================
void SchoolsOut::collisions()
{
	D3DXVECTOR2 colVect;
	entityCollection.collision();

}


//=============================================================================
// Render game items
//=============================================================================
void SchoolsOut::render()
{

	graphics->spriteBegin();                // begin drawing sprites
	background.draw();
	entityCollection.render();

	graphics->spriteEnd();                  // end drawing sprites

	font->DrawText(NULL, guiwin->returnHealth().c_str(), -1, &guiwin->returnPlayer(), DT_CENTER, graphicsNS::BLACK);
	graphics->showBackbuffer();

}
//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SchoolsOut::releaseAll()
{
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SchoolsOut::resetAll()
{
	Game::resetAll();
	return;
}
