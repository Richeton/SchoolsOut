//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "GUI.h"

//=============================================================================
// default constructor
//=============================================================================
GUI_Window::GUI_Window()
{
	player_Icon.left = 0;
	player_Icon.top = 0;

	player_Icon.right = GAME_WIDTH / 8;
	player_Icon.bottom = GAME_HEIGHT / 6;

	health_Icon.left = GAME_WIDTH / 7;
	health_Icon.top = 0;

	health_Icon.right = GAME_WIDTH / 5;
	health_Icon.bottom = GAME_HEIGHT / 12;
}

GUI_Window::~GUI_Window()
{

}


RECT GUI_Window::returnPlayer() 
{
	return player_Icon; 
}

std::string GUI_Window::returnHealth() 
{
	return healthText;
}

void GUI_Window::update(Player player)
{
	int newHealth = int(player.getHealth());
	std::string updateHealth = std::to_string(newHealth);
	healthText = updateHealth;
}