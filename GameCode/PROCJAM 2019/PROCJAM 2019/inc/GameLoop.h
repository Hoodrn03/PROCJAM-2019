#pragma once

#include <thread>

#include <SFML/Graphics.hpp>

#include <TGUI/TGUI.hpp>

#include "GameWindow.h"
#include "EventHandler.h"

#include "Grid.h"
#include "Player.h"
#include "Attack.h"
#include "EnemyManager.h"

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

	/*! \var This will be used to manage the main game window. */
	std::unique_ptr<GameWindow> m_ptrWindow;


	std::unique_ptr<EventHandler> m_ptrEventHandler;

	/*! \var This will control the main functionality of the player character. */
	std::unique_ptr<Player> m_ThisPlayer;

	std::unique_ptr <EnemyManager> m_ThisEnemyManager;

	/*! \var This will hold and maintain the grid/map in the game. */
	std::unique_ptr<Grid> m_ThisGrid;

	int m_MaxEnemyCount = 5; 

	// Member Functions 

public:

	void m_LoseScreen(); 

	void m_MainMenu(); 

	/*! \fn RunGame : Used to begin the game loop*/
	void m_RunGame(); 

	/*! \fn Update : Used to split some of the other functionality into a second thread. */
	int m_Update();

	void m_CheckPlayerMovement();

	void m_CheckEnemyMovement(); 

	void m_SpawnNewEnemy(); 

};