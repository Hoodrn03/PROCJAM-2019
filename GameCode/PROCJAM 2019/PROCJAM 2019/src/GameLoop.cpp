#include "Gameloop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

/*! \ fn RunGame : Used to begin the game loop*/
void GameLoop::m_RunGame()
{
	// begin Setup

	// Window init. 

	m_ptrWindow.reset(new GameWindow());

	m_ptrWindow->m_CreateWindow(800, 800, "PROCJAM 2019", 120);

	// Init Event Handler

	std::unique_ptr<EventHandler> l_ptrEventHandler;

	l_ptrEventHandler.reset(new EventHandler());

	// Init Grid

	m_ThisGrid.reset(new Grid());

	m_ThisGrid->m_CreateinitialGrid(50);
	m_ThisGrid->m_AddMountainToMap(); 
	m_ThisGrid->m_AddGrassToMap(); 

	// Init Player

	m_ThisPlayer.reset(new Player());

	m_ThisPlayer->m_CreateView(800, 800);

	// m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetStartingPositionFromGrid());

	m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetStartingPoint());
	m_ThisPlayer->m_SetWindowPtr(m_ptrWindow->m_GetWindow());

	// Init Enemies

	m_ThisEnemyManager.m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

	m_ThisEnemyManager.m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

	m_ThisEnemyManager.m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

	// Test Items 

	bool l_bDown = false; 

	// End of Setup

	std::thread l_First([this] { this->m_Update(); });

	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// Begin of loop 

		// Update Items

			// Update Player
		m_ThisPlayer->m_Update();
		m_ThisPlayer->m_SetCurrentWindow(m_ptrWindow->m_GetWindow());

			// Update Enemies
		m_ThisEnemyManager.m_MoveToPlayer(m_ThisPlayer->m_GetPlayerPosition());
		m_ThisEnemyManager.m_UpdateEnemies();
		m_ThisEnemyManager.m_EnemiesHit(m_ThisPlayer->m_GetAttackRect(), m_ThisPlayer->m_GetAttackPosition());
		
		m_ThisPlayer->m_IsHit(m_ThisEnemyManager.m_AttackPlayer(m_ThisPlayer->m_GetPlayerPosition()));

		
		

		// End of Update

		// Handle Events 

		l_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		// End of Events

		// Clear Window 

		m_ptrWindow->m_ClearWindow(sf::Color::Blue);

		// Beginning of drawing

		m_ThisGrid->m_DrawGrid(m_ptrWindow->m_GetWindow(), m_ThisPlayer->m_GetView());

		m_ThisPlayer->m_DrawPlayer(m_ptrWindow->m_GetWindow());

		m_ThisEnemyManager.m_DrawEnemies(m_ptrWindow->m_GetWindow());
		// End of drawing

		m_ptrWindow->m_DisplayWindow();

		// Display Window 

		// End of frame removal of items.

		m_ThisEnemyManager.m_RemoveEnemies(); 

		// End of loop 
	}

	l_First.join();
}

/*! \fn Update : Used to split some of the other functionality into a second thread. */
void GameLoop::m_Update()
{
	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// std::cout << " Update " << std::endl;

			// Update Grid

		// Add new map cells 

		m_ThisGrid->m_PlayerExitDirection(m_ThisPlayer->m_GetPlayerCenter()); 

		// Check Cell each radius is inside. 

		Cell *m_TempCell; 

		// Check Top.

		m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisPlayer->m_UpRadius.getPosition()));

		// See if it is passable 

		if (m_TempCell->m_IsPassable() == false)
		{
			// If not prevent that directional movement

			m_ThisPlayer->m_LimitMovement(0);
		}
		else
		{
			m_ThisPlayer->m_LimitMovement(4);
		}

		// Check Left

		m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisPlayer->m_LeftRadius.getPosition()));

		// See if it is passable 

		if (m_TempCell->m_IsPassable() == false)
		{
			// If not prevent that directional movement

			m_ThisPlayer->m_LimitMovement(2);
		}
		else
		{
			m_ThisPlayer->m_LimitMovement(6);
		}

		// Check Down

		m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisPlayer->m_DownRadius.getPosition()));

		// See if it is passable 

		if (m_TempCell->m_IsPassable() == false)
		{
			// If not prevent that directional movement

			m_ThisPlayer->m_LimitMovement(1);
		}
		else
		{
			m_ThisPlayer->m_LimitMovement(5);
		}

		// Check Right

		m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisPlayer->m_RightRadius.getPosition()));

		// See if it is passable 

		if (m_TempCell->m_IsPassable() == false)
		{
			// If not prevent that directional movement

			m_ThisPlayer->m_LimitMovement(3);
		}
		else
		{
			m_ThisPlayer->m_LimitMovement(7);
		}

		
	}
}
