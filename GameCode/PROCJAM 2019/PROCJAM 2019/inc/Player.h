#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "GameView.h"

#include "CollisionDetection/PointLineCollision.h"

/*! \class Used to create and manage a player character. 
			Has a view attached to the player to act as a movable camera. 
*/
class Player: public GameView, public PointLineCollision
{
	// Constructor 

public:

	Player();

	// Deconstructor

	~Player();

	// Data Members 

private:

	/*! \var The main body used to display the player. */
	sf::RectangleShape m_PlayerBody;

	/*! \var The direction vector the used to move the player. */
	sf::Vector2f m_MovementVector;

	/*! \var The constant speed the player will move at if they are moving, they cannot move fatser than this. */
	const float m_fSpeed = 1.5f;

	bool m_bNoLeftMove = false, m_bNoRightMove = false;
	bool m_bNoUpMove = false, m_bNoDownMove = false;

	// Member Functions 

public:

	/*! \fn DrawPlayer Used to draw the player sprite onto the game window
	param one: The game window to draw onto. 
	*/
	void m_DrawPlayer(sf::RenderWindow& window); 

	/*! \fn Update Used to update the player once each loop. */
	void m_Update(); 

	void m_CheckMovementDirectionOne(sf::FloatRect currentCellBounds, bool passableTile);

	void m_CheckMovementDirectionTwo(sf::FloatRect currentCellBounds, bool passableTile);

	/*! \fn Movement Used to handle the movement of the player character. */
	void m_Movement(); 

	void m_SetPlayerStartingPos(sf::Vector2f newPos); 

	sf::Vector2f m_GetPlayerPosition(); 

	sf::Vector2f m_GetPlayerSize();
};