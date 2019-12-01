#pragma once

#include <iostream>

#include "Enemy.h"

class EnemyManager
{
	// Constructor 

public:

	EnemyManager();

	// Deconstructor 

	~EnemyManager();

	// Data Members 

private:

	std::vector<Enemy> v_EnemyList; 

	// Member Functions 

public:

	void m_AddEnemies(sf::Vector2f enemyPos);

	void m_UpdateEnemies();

	void m_MoveToPlayer(sf::Vector2f playerPos);

	void m_EnemiesHit(sf::FloatRect playerAttack, sf::Vector2f direction); 

	bool m_AttackPlayer(sf::Vector2f playerPos); 

	void m_RemoveEnemies(); 

	void m_DrawEnemies(sf::RenderWindow& window); 


};