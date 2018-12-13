//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "player.h"

Player::Player()
{
	collisionType = entityNS::COLLISION_TYPE::BOX;
	entityType = entityNS::ENTITY_TYPE::PLAYER;
	health = 3;
}

Player::Player(Input &input)
{
	Player();
	this->input = &input;
}

Player::~Player()
{

}

void Player::update(float frameTime)
{
	Entity::update(frameTime);

	// Updates the x & y of the spriteData with relation
	// ... to the velocity * frameTime
	spriteData.x += this->velocity.x * frameTime;
	spriteData.y += this->velocity.y * frameTime;

	// (2DVECTOR velocity by DirectX)
	D3DXVECTOR2 vel = D3DXVECTOR2(0, 0);

	// This is for the 'W' key
	// Player moves up when pressed
	if (input->isKeyDown(0x57))
	{
		// Uses '-' because moving up
		// ... means decreasing in Y-axis
		vel.y = -150; // <-- Set a const for it later
					  // Player doesn't wrap around when it hits the top
		if (getY() <= (GAME_BOUNDARY_YSTART))
			setY((float)GAME_BOUNDARY_YSTART);

		setCurrentFrame(12);
		setFrames(12, 12);
	}

	// This is for the 'S' key
	// Player moves down when pressed
	if (input->isKeyDown(0x53))
	{
		// Uses '+' beause moving down
		// ... means increasing in Y-axis
		vel.y = 150;
		// Player doesn't wrap around when it hits the bottom
		// Have to '-' the 'height' of the sprite
		// ... because it starts from the 'top-left'
		// ... of the sprite
		if (getY() >= GAME_BOUNDARY_YEND - getHeight())
			setY((float)GAME_BOUNDARY_YEND - getHeight());

		// Set the sprite so it faces the correct direction
		setCurrentFrame(0);
		setFrames(0, 0);
	}

	// This is for the 'A' key
	// Player moves left when pressed
	if (input->isKeyDown(0x41))
	{
		// Uses '-' because moving left
		// ... means decreasing in X-axis
		vel.x = -150;
		// Player doesn't wrap around when it hits the left
		if (getX() <= GAME_BOUNDARY_XSTART)
			setX((float)GAME_BOUNDARY_XSTART);

		setCurrentFrame(4);
		setFrames(4, 4);

	}

	// This is for the 'D' key
	// Player moves right when pressed
	if (input->isKeyDown(0x44))
	{
		// Uses '+' because moving right
		// ... means increasing in X-axis
		vel.x = 150;
		// Player doesn't wrap around when it hits the right
		// Have to '-' the 'width' of the sprite
		// ... because it starts from the top left
		// ... of the sprite
		if (getX() >= GAME_BOUNDARY_XEND - getWidth())
			setX((float)GAME_BOUNDARY_XEND - getWidth());
		setCurrentFrame(8);
		setFrames(8, 8);

	}

	setVelocity(vel);

	/*
	*Under construction until EntityCollection is finished

	// This is for the 'Up' arrow key
	// Player shoots up when pressed
	if (input->isKeyDown(VK_UP))
	{
	//shootUp();
	}


	// This is for the 'Down' arrow key
	// Player shoots down when pressed
	if (input->isKeyDown(VK_DOWN))
	{
	//shootDown();
	}

	// This is for the 'Left' arrow key
	// Player shoots left when pressed
	if (input->isKeyDown(VK_LEFT))
	{
	//shootLeft();
	}

	// This is for the 'Right' arrow key
	// Player shoots right when pressed
	if (input->isKeyDown(VK_RIGHT))
	{

	}
	*/
}

void Player::collisions()
{
	// Collision code for Enemy

	// Collision code for Obstacles

	//

}