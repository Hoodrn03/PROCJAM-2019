#pragma once

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "EventHandler.h"

#include "Grid.h"
#include "Player.h"

/*! \class Used to hold the main game loop. */
class GameLoop
{
	// Constructor 

public:

	GameLoop();

	// Deconstructor 

	~GameLoop();

	// Data Members 

private:



	// Member Functions 

public:

	/*! \ fn RunGame : Used to begin the game loop*/
	void m_RunGame(); 

};