#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

/*! \ class Used to create an manage a view within the game. */
class GameView
{
	// Constructor 

public:

	GameView();

	// Deconstructor 

	~GameView();

	// Data Members 

private:

	/*! \var The view managed by this class. */
	sf::View m_ThisView; 

	/*! \var The current position of this view, used to prevent moving the view is stationary. */
	sf::Vector2f m_CurrentPosition;

	// Member Functions

public:

	/*! \fn CreateView Used to give the empty view a size. 
	param one: The width for the view.
	param two: The height for the view.
	*/
	void m_CreateView(float width, float height);

	/*! \fn MoveView This will set the center of the view to a new position. 
	param one: The new position for the view.
	*/
	void m_MoveView(sf::Vector2f newPos);

	/*! \fn SetCurrentWindow This will assign this view to the window. 
	param one: The game window to assign the view. 
	*/
	void m_SetCurrentWindow(sf::RenderWindow& window);

	sf::Vector2f m_GetUpperBounds();

	sf::Vector2f m_GetLowerBounds(); 

	sf::View& m_GetView(); 
};