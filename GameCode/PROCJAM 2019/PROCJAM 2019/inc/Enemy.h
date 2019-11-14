#pragma once

#include "SFML/Graphics.hpp"

class Enemy
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

	// Member Functions 

public:

	void m_CreateEnemy(sf::Vector2f enemyPos);

};