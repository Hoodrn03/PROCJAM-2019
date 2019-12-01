#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/PointLineCollision.h"
#include "Movement.h"

/*! \class This will maintain a single enemy within the game world. */
class Enemy : public PointLineCollision, public Movement
{
	// Constructor 

public:

	Enemy();

	/*! \fn Constructor (overload) 
	Param One - sf::vector2f The new position for the enemy. 
	*/
	Enemy(sf::Vector2f enemyPos);

	// Deconstructor 

	~Enemy();

	// Data Members 

private:

	/*! \var This is the main body for the enemy within the game world. */
	sf::RectangleShape m_EnemyBody; 

	/*! \var This is the size ratios for the enemy. */
	sf::Vector2f m_EnemySize{ 25, 25 };

	/*! \var This is the detection radius for the enemy if the player enters it then the enemy will travel towards them. */
	sf::CircleShape m_DetectionRadius;

	/*! \var This will be the radius for the enemy's attack if the player is inside it then they will be hit. */
	sf::CircleShape m_AttackRadius; 

	/*! \var This is the time the enemy is immune to damage. */
	float m_fDamageImunity = 2.5f;

	/*! \var A clock which will manage the enemy's current immunity. */
	sf::Clock m_ImunityTimer; 

	/*! \var The current health for the enemy. Once it reaches 0 they die. */
	float m_fHealth = 100.f;

	// Member Functions 

public:

	/*! \fn CreateEnemy
	Param One - sf::vector2f The new position for the enemy.
	*/
	void m_CreateEnemy(sf::Vector2f enemyPos);

	/*! \fn CreateEnemy (overload)
	Param One - float The new x position for the enemy.
	Param Two - float The new y position for the enemy.
	*/
	void m_CreateEnemy(float x, float y);

	/*! \fn DrawEnemy 
	Param One - sf::RenderWindow The main game window. */
	void m_DrawEnemy(sf::RenderWindow& window); 

	/*! \fn Update */
	void m_Update(); 

	/*! \fn Move */
	void m_Move(); 

	/*! \fn MoveToPlayer 
	Param One - sf::vector2f The player's current position
	*/
	void m_MoveToPlayer(sf::Vector2f playerPos);

	bool m_HitPlayer(sf::Vector2f playerPos); 

	/*! \fn GetEnemyCenter */
	sf::Vector2f m_GetEnemyCenter(); 

	/*! \fn EnemyKnockback 
	Param One - sf::Vector2f The direction to knock the enemy to*/
	void m_EnemyKnockBack(sf::Vector2f direction); 

	/*! \fn Destroy Enemy. */
	bool m_DestroyEnemy(); 

};