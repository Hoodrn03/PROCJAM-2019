#pragma once

#include <iostream>
#include <cmath>

#include "SFML/Graphics.hpp"

#include "GameView.h"

#include "CollisionDetection/PointLineCollision.h"
#include "Attack.h"
#include "VectorMath.h"

#define PI 3.14159265f

/*! \class Used to create and manage a player character. 
			Has a view attached to the player to act as a movable camera. 
*/
class Player: public GameView, public PointLineCollision, public VectorMath
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

	sf::CircleShape m_AttackRadius; 

	// Moving 

	/*! \var The direction vector the used to move the player. */
	sf::Vector2f m_MovementVector;

	/*! \var The constant speed the player will move at if they are moving, they cannot move fatser than this. */
	const float m_fSpeed = 1.5f;

	bool m_bNoLeftMove = false, m_bNoRightMove = false;
	bool m_bNoUpMove = false, m_bNoDownMove = false;

private:

	// Attacking

	Attack m_clAttack; 

	bool m_bMoveUp = false, m_bMoveDown = false, m_bMoveRight = false, m_bMoveLeft = false;

	sf::Clock m_AttackTimer; 

	const float m_fAttackTimer = 0.5f;

	std::unique_ptr<sf::RenderWindow> m_ptrCurrentWindow;

	sf::Vector2f m_AttackPossition; 

	float m_fLife = 100.f; 

	float m_fImunityLimiter = 1.5f;

	sf::Clock m_ImunityTimer; 

public:

	sf::CircleShape m_UpRadius;
	sf::CircleShape m_DownRadius;
	sf::CircleShape m_LeftRadius;
	sf::CircleShape m_RightRadius;

	// Member Functions 

public:

	// Rendering 

	/*! \fn DrawPlayer Used to draw the player sprite onto the game window
	param one: The game window to draw onto. 
	*/
	void m_DrawPlayer(sf::RenderWindow& window); 

	// Update 

	/*! \fn Update Used to update the player once each loop. */
	void m_Update(); 

	bool m_CheckForDeath(); 

	// Movement 

	/*! \fn Movement Used to handle the movement of the player character. */
	void m_Movement(); 

	void m_SetPlayerStartingPos(sf::Vector2f newPos);
	void m_SetPlayerStartingPos(float x, float y);

	sf::Vector2f m_GetPlayerPosition();
	sf::Vector2f m_GetPlayerCenter(); 

	void m_LimitMovement(int direction); 

	// Attacking 

	void m_Attack(); 

	bool m_HitEnemy(sf::Vector2f enemyPos); 

	void m_IsHit(bool enemyAttack);

	sf::Vector2f m_GetAttackPosition();

	sf::FloatRect m_GetAttackRect();

	void m_SetWindowPtr(sf::RenderWindow& window);

	sf::Vector2f m_GetPlayerSize();

	float m_GetHealth(); 
};