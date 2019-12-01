#include "Attack.h"

//					File Start						\\

// Constructor 
Attack::Attack()
{
}

// Deconstructor
Attack::~Attack()
{
}

/*! \fn CreateAttackBody : Used to initalize the attck object.
param one : vector2f : The position to spawn the attack.
*/
void Attack::m_CreateAttackBody(sf::Vector2f newPos)
{
	m_AttackBody.reset(new sf::RectangleShape());

	m_AttackBody->setSize(m_AttackSize);

	m_AttackBody->setOrigin(sf::Vector2f(m_AttackBody->getPosition().x + m_AttackSize.x / 2, m_AttackBody->getPosition().y + m_AttackSize.y / 2));

	m_AttackBody->setPosition(newPos); 
}

/*! \fn CreateAttackBody (overload one): Used to initalize the attck object.
param one : vector2f : The position to spawn the attack.
param two : float : the rotation for the attack object.
*/
void Attack::m_CreateAttackBody(sf::Vector2f newPos, float rotataion)
{
	m_AttackBody.reset(new sf::RectangleShape());

	m_AttackBody->setSize(m_AttackSize);

	m_AttackBody->setOrigin(sf::Vector2f(m_AttackBody->getPosition().x + m_AttackSize.x / 2, m_AttackBody->getPosition().y + m_AttackSize.y / 2));

	m_AttackBody->setPosition(newPos);

	m_AttackBody->setRotation(rotataion);
}

/*! \fn DrawAttackBody : Used to display the attack on the screen.
param one : renderwindow : The main game window.
*/
void Attack::m_DrawAttackBody(sf::RenderWindow & window)
{
	if (m_AttackBody.get() != nullptr)
	{
		window.draw(*m_AttackBody);
	}
}

/*! \fn UpdatePos : Used to move the attack body to a new position
param one : vector2f : the new position for the sprite.
*/
void Attack::m_UpdatePos(sf::Vector2f newPos)
{
	if (m_AttackBody.get() != nullptr)
	{
		m_AttackBody->setPosition(newPos);
	}
}

/*! \fn DestroyAttackBody : Used to destroy the current attack object in the game. */
void Attack::m_DestroyAttackBody()
{
	m_AttackBody.reset(new sf::RectangleShape());
}

/*! \fn HitDetection : Used to check if a given point is inside the attack body.
param one : vector2f : the coord for the object to check.
*/
bool Attack::m_HitDetection(sf::Vector2f pointToCheck)
{
	if (m_AttackBody->getGlobalBounds().contains(pointToCheck))
	{
		return true; 
	}

	return false;
}

/*! \fn ThisExists : Used to check if there is currently an attack body in the game. */
bool Attack::m_ThisExists()
{
	if (m_AttackBody.get() != nullptr)
	{
		return true; 
	}

	return false;
}

sf::FloatRect Attack::m_GetAttackRect()
{
	return m_AttackBody->getGlobalBounds();
}

//					File End						\\