#include "Gameloop.h"

GameLoop::GameLoop()
{
	m_ptrWindow.reset(new GameWindow());

	m_ptrWindow->m_CreateWindow(800, 800, "PROCJAM 2019", 120);

	m_ptrEventHandler.reset(new EventHandler());
}

GameLoop::~GameLoop()
{
}

void GameLoop::m_LoseScreen()
{
	tgui::Gui l_Gui{ m_ptrWindow->m_GetWindow() };

	auto l_RestartButton = tgui::Button::create();
	l_RestartButton->setPosition(400, 300);
	l_RestartButton->setText("Restart");
	l_RestartButton->setSize(200, 100);
	l_RestartButton->connect("pressed", [=]() { this->m_RunGame(); });
	l_Gui.add(l_RestartButton);

	auto l_ExitButton = tgui::Button::create();
	l_ExitButton->setPosition(200, 300);
	l_ExitButton->setText("Main Menu");
	l_ExitButton->setSize(200, 100);
	l_ExitButton->connect("pressed", [=]() { this->m_MainMenu(); });
	l_Gui.add(l_ExitButton);

	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// Update 

		// Event Manager 

		m_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		l_Gui.handleEvent(m_ptrEventHandler->m_GetEvent());

		// Clear 

		m_ptrWindow->m_ClearWindow();

		// Draw 

		l_Gui.draw();

		// Display

		m_ptrWindow->m_DisplayWindow();
	}
}

void GameLoop::m_MainMenu()
{
	
	tgui::Gui l_Gui{ m_ptrWindow->m_GetWindow() }; 

	auto l_StartButton = tgui::Button::create();
	l_StartButton->setPosition(300, 300);
	l_StartButton->setText("Start");
	l_StartButton->setSize(200, 100);
	l_StartButton->connect("pressed", [=]() { this->m_RunGame(); });
	l_Gui.add(l_StartButton);

	auto l_ExitButton = tgui::Button::create();
	l_ExitButton->setPosition(300, 400);
	l_ExitButton->setText("Exit");
	l_ExitButton->setSize(200, 100);
	l_ExitButton->connect("pressed", [=]() { m_ptrWindow->m_GetWindow().close(); });
	l_Gui.add(l_ExitButton);


	while(m_ptrWindow->m_GetWindow().isOpen())
	{
		// Update 

		// Event Manager 

		m_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		l_Gui.handleEvent(m_ptrEventHandler->m_GetEvent());

		// Clear 

		m_ptrWindow->m_ClearWindow();

		// Draw 
		
		l_Gui.draw(); 

		// Display

		m_ptrWindow->m_DisplayWindow(); 
	}

}

/*! \ fn RunGame : Used to begin the game loop*/
void GameLoop::m_RunGame()
{
	// begin Setup

	tgui::Gui l_Gui{ m_ptrWindow->m_GetWindow() };

	// Init Grid

	m_ThisGrid.reset(new Grid());

	m_ThisGrid->m_CreateinitialGrid(50);
	m_ThisGrid->m_AddMountainToMap(); 
	m_ThisGrid->m_AddGrassToMap(); 

	// Init Player

	m_ThisPlayer.reset(new Player());

	m_ThisPlayer->m_CreateView(300, 300);

	// m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetStartingPositionFromGrid());

	m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetStartingPoint());
	m_ThisPlayer->m_SetWindowPtr(m_ptrWindow->m_GetWindow());

	auto l_HealthBar = tgui::ProgressBar::create();
	l_HealthBar->setPosition({ "&.width / 3 - width" });
	l_HealthBar->setSize(200, 20);
	l_HealthBar->setValue(100);
	l_Gui.add(l_HealthBar);

	auto label = tgui::Label::create();
	label->setText("Life");
	label->setPosition({ "&.width / 7 - width, &.height - 50" });
	label->setTextSize(18);
	l_Gui.add(label);

	// Init Enemies

	m_ThisEnemyManager.reset(new EnemyManager());

	m_ThisEnemyManager->m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

	m_ThisEnemyManager->m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

	m_ThisEnemyManager->m_AddEnemies(m_ThisGrid->m_GetStartingPoint());

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

		l_HealthBar->setValue(m_ThisPlayer->m_GetHealth());

			// Update Enemies
		m_ThisEnemyManager->m_MoveToPlayer(m_ThisPlayer->m_GetPlayerPosition());
		m_ThisEnemyManager->m_UpdateEnemies();
		m_ThisEnemyManager->m_EnemiesHit(m_ThisPlayer->m_GetAttackRect(), m_ThisPlayer->m_GetAttackPosition());
		
		m_ThisPlayer->m_IsHit(m_ThisEnemyManager->m_AttackPlayer(m_ThisPlayer->m_GetPlayerPosition()));

		m_SpawnNewEnemy();

		// End of Update

		// Handle Events 

		m_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		l_Gui.handleEvent(m_ptrEventHandler->m_GetEvent());

		// End of Events

		// Clear Window 

		m_ptrWindow->m_ClearWindow(sf::Color::Blue);

		// Beginning of drawing

		m_ThisGrid->m_DrawGrid(m_ptrWindow->m_GetWindow(), m_ThisPlayer->m_GetView());

		m_ThisPlayer->m_DrawPlayer(m_ptrWindow->m_GetWindow());

		m_ThisEnemyManager->m_DrawEnemies(m_ptrWindow->m_GetWindow());

		l_Gui.draw();

		// End of drawing
		m_ptrWindow->m_DisplayWindow();

		// Display Window 

		// End of frame removal of items.

		m_ThisEnemyManager->m_RemoveEnemies();

		if (m_ThisPlayer->m_CheckForDeath() == true)
		{
			this->m_LoseScreen(); 
		}

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

		if (m_ThisPlayer != nullptr)
		{
			m_ThisGrid->m_PlayerExitDirection(m_ThisPlayer->m_GetPlayerCenter());

			m_CheckPlayerMovement();

			m_CheckEnemyMovement();
		}
	}
}

void GameLoop::m_CheckPlayerMovement()
{
	// Check Cell each radius is inside. 

	Cell* m_TempCell;

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

void GameLoop::m_CheckEnemyMovement()
{
	// Check Enemy up Movement

	if(m_ThisEnemyManager->m_EnemyCount() > 0)
	{ 
		for (unsigned int i = 0; i < m_ThisEnemyManager->m_EnemyCount(); i++)
		{
			
			Cell* m_TempCell;

			// Check Top.

			m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisEnemyManager->m_GetEnemy(i).m_UpRadius.getPosition()));

			// See if it is passable 

			if (m_TempCell->m_IsPassable() == false)
			{
				// If not prevent that directional movement

				m_ThisEnemyManager->m_LimitMovement(0, i);
			}
			else
			{
				m_ThisEnemyManager->m_LimitMovement(4, i);
			}

			// Check Bottom 

			m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisEnemyManager->m_GetEnemy(i).m_DownRadius.getPosition()));

			// See if it is passable 

			if (m_TempCell->m_IsPassable() == false)
			{
				// If not prevent that directional movement

				m_ThisEnemyManager->m_LimitMovement(2, i);
			}
			else
			{
				m_ThisEnemyManager->m_LimitMovement(6, i);
			}

			// Check Left 

			m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisEnemyManager->m_GetEnemy(i).m_LeftRadius.getPosition()));

			// See if it is passable 

			if (m_TempCell->m_IsPassable() == false)
			{
				// If not prevent that directional movement

				m_ThisEnemyManager->m_LimitMovement(1, i);
			}
			else
			{
				m_ThisEnemyManager->m_LimitMovement(5, i);
			}

			// Check Right 

			m_TempCell = (m_ThisGrid->m_CheckPlayerInCell(m_ThisEnemyManager->m_GetEnemy(i).m_RightRadius.getPosition()));

			// See if it is passable 

			if (m_TempCell->m_IsPassable() == false)
			{
				// If not prevent that directional movement

				m_ThisEnemyManager->m_LimitMovement(3, i);
			}
			else
			{
				m_ThisEnemyManager->m_LimitMovement(7, i);
			}
		}
	}
}

void GameLoop::m_SpawnNewEnemy()
{
	if (m_ThisEnemyManager->m_EnemyCount() <= m_MaxEnemyCount)
	{
		m_ThisEnemyManager->m_AddEnemies(m_ThisGrid->m_GetStartingPoint()); 
	}

	m_MaxEnemyCount = m_ThisGrid->m_EnemySpawnModifier(); 
}
