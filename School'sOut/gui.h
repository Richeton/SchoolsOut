//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _GUI_H            // Prevent multiple definitions if this 
#define _GUI_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "player.h"
#include "game.h"



class GUI_Window
{

protected:

	RECT player_Icon, health_Icon, weapon_Icon, weapon_Ammo;
	const int   player_icon_WIDTH = 64;                // image width
	const int   player_icon_HEIGHT = 64;               // image height
	const int   COLLISION_RADIUS = 120 / 2;   // for circular collision
	const int   player_Icon_x = 0; //GAME_WIDTH / 2 - player_icon_WIDTH / 2; // location on screen
	const int   player_Icon_Y = 0; //GAME_HEIGHT / 2 - HEIGHT / 2;
	std::string healthText;
	LPD3DXFONT healthFont;			// Position to be tweaked


public:
	// constructor
	GUI_Window();
	~GUI_Window();

	RECT returnPlayer();
	std::string returnHealth();
	void update(Player player);
	//void update();


};




#endif