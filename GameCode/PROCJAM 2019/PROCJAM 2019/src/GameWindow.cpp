#include "GameWindow.h"

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}

/*! \fn CreateWindow : This will be used to initalize the game window.
*Param One : Int - The width of the game window.
*Param Two : Int - The height of the game window. 
*/
int GameWindow::m_CreateWindow(int width, int height)
{
	m_RenderWindow.create(sf::VideoMode(width, height), "Untitled");

	m_RenderWindow.setFramerateLimit(60); 

	if (m_RenderWindow.isOpen())
	{
		std::cout << "Window Open" << std::endl;

		return 0; 
	}

	return 1;
}

/*! \fn CreateWindow : This will be used to initalize the game window.
*Param One : Int - The width of the game window.
*Param Two : Int - The height of the game window.
*Param Three : std::string - The name for the game window. 
*/
int GameWindow::m_CreateWindow(int width, int height, std::string name)
{
	m_RenderWindow.create(sf::VideoMode(width, height), name);

	m_RenderWindow.setFramerateLimit(60);

	if (m_RenderWindow.isOpen())
	{
		std::cout << "Window Open" << std::endl;

		return 0;
	}

	return 1;
}

/*! \fn CreateWindow : This will be used to initalize the game window.
*Param One : Int - The width of the game window.
*Param Two : Int - The height of the game window.
*Param Three : std::string - The name for the game window.
*Param Four : unsinged int - A variable framerate limit for the game window. 
*/
int GameWindow::m_CreateWindow(int width, int height, std::string name, unsigned int framerateLimit)
{
	m_RenderWindow.create(sf::VideoMode(width, height), name);

	m_RenderWindow.setFramerateLimit(framerateLimit);

	if (m_RenderWindow.isOpen())
	{
		std::cout << "Window Open" << std::endl;

		return 0;
	}

	return 1;
}

/*! \fn GetWindow : This will allow for access of the game window. */
sf::RenderWindow& GameWindow::m_GetWindow()
{
	return m_RenderWindow;
}

/*! \fn GetUpperBounds : This will return the set of coordinates for the top, left of the game window */
sf::Vector2f GameWindow::m_GetUpperBounds()
{
	sf::Vector2f l_ReturnVector; 

	l_ReturnVector = sf::Vector2f(m_RenderWindow.getPosition()); 

	return l_ReturnVector;
}

/*! \fn GetLowerBounds : This will return the set of coordinates for the bottom, right of the game window */
sf::Vector2f GameWindow::m_GetLowerBounds()
{
	sf::Vector2f l_ReturnVector;

	l_ReturnVector = sf::Vector2f(m_RenderWindow.getPosition().x + m_RenderWindow.getSize().x, 
		m_RenderWindow.getPosition().y + m_RenderWindow.getSize().y);

	return l_ReturnVector;
}

/*! \fn ClearWindow : Used to clear the game window. */
void GameWindow::m_ClearWindow()
{
	m_RenderWindow.clear();
}

void GameWindow::m_ClearWindow(sf::Color clearColour)
{
	m_RenderWindow.clear(clearColour);
}

/*! \fn DisplayWindow : Used to display all of the elements onto the game window. */
void GameWindow::m_DisplayWindow()
{
	m_RenderWindow.display();
}
