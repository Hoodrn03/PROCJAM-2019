#pragma once

#include <thread>

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "EventHandler.h"

#include "Grid.h"
#include "Player.h"
#include "Attack.h"

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

	std::unique_ptr<GameWindow> m_ptrWindow;

	std::unique_ptr<Player> m_ThisPlayer;

	std::unique_ptr<Grid> m_ThisGrid;

	// Member Functions 

public:

	/*! \ fn RunGame : Used to begin the game loop*/
	void m_RunGame(); 

	void m_Update(); 

};