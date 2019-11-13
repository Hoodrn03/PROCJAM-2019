#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class Attack
{
	// Constructor 

public:

	Attack();

	// Deconstructor 

	~Attack();

	// Data Memvers 

private:

	float m_fDamage = 15.f;

	std::unique_ptr<sf::RectangleShape> m_AttackBody; 

	const sf::Vector2f m_AttackSize{ 75, 25 };

	// Member Functions 

public:

	void m_CreateAttackBody(sf::Vector2f newPos);

	void m_CreateAttackBody(sf::Vector2f newPos, float rotataion);

	void m_DrawAttackBody(sf::RenderWindow & window);

	void m_UpdatePos(sf::Vector2f newPos); 

	void m_DestroyAttackBody(); 

	bool m_HitDetection(sf::Vector2f pointToCheck);

	bool m_ThisExists(); 

};