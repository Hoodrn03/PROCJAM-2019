
#include <SFML/Graphics.hpp>

#include "GameLoop.h"

int main()
{
	// Start of game. 

	std::unique_ptr<GameLoop> l_ptrGameLoop;

	l_ptrGameLoop.reset(new GameLoop); 

	l_ptrGameLoop->m_MainMenu(); 

	// Exit Game. 

	return 0;
}