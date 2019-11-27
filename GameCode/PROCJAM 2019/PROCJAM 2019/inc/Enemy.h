#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/PointLineCollision.h"
#include "Movement.h"

class Enemy : public PointLineCollision, public Movement
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

	const float m_fDamageImunity = 2.5f;

	sf::Clock m_ImunityTimer; 

	float m_fHealth = 100.f;

	// Member Functions 

public:

	void m_CreateEnemy(sf::Vector2f enemyPos);

	void m_CreateEnemy(float x, float y);

	void m_DrawEnemy(sf::RenderWindow& window); 

	void m_Update(); 

	void m_Move(); 

	void m_MoveToPlayer(sf::Vector2f playerPos);

	sf::Vector2f m_GetEnemyCenter(); 

	void m_EnemyKnockBack(sf::Vector2f direction); 

	bool m_DestroyEnemy(); 

};