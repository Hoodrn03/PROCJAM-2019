#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/PointLineCollision.h"

class Enemy : public PointLineCollision
{
	// Constructor 

public:

	Enemy();

	// Deconstructor 

	~Enemy();

	// Data Members 

private:

	sf::RectangleShape m_EnemyBody; 

	const sf::Vector2f m_EnemySize{ 25, 25 };

	sf::CircleShape m_DetectionRadius;

	// Member Functions 

public:

	void m_CreateEnemy(sf::Vector2f enemyPos);

	void m_DrawEnemy(sf::RenderWindow& window); 

	void m_Update(); 

	void m_MoveToPlayer(sf::Vector2f playerPos);

};