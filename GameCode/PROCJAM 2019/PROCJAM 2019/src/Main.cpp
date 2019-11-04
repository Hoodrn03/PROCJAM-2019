
#include <SFML/Graphics.hpp>

#include "GameLoop.h"

int main()
{
	// Start of game. 

	std::unique_ptr<GameLoop> l_ptrGameLoop;

	l_ptrGameLoop.reset(new GameLoop); 

	l_ptrGameLoop->m_RunGame(); 

	// Exit Game. 

	return 0;
}