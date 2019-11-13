#include "Attack.h"

Attack::Attack()
{
}

Attack::~Attack()
{
}

void Attack::m_CreateAttackBody(sf::Vector2f newPos)
{
	m_AttackBody.reset(new sf::RectangleShape());

	m_AttackBody->setSize(m_AttackSize);

	m_AttackBody->setOrigin(sf::Vector2f(m_AttackBody->getPosition().x + m_AttackSize.x / 2, m_AttackBody->getPosition().y + m_AttackSize.y / 2));

	m_AttackBody->setPosition(newPos); 
}

void Attack::m_CreateAttackBody(sf::Vector2f newPos, float rotataion)
{
	m_AttackBody.reset(new sf::RectangleShape());

	m_AttackBody->setSize(m_AttackSize);

	m_AttackBody->setOrigin(sf::Vector2f(m_AttackBody->getPosition().x + m_AttackSize.x / 2, m_AttackBody->getPosition().y + m_AttackSize.y / 2));

	m_AttackBody->setPosition(newPos);

	m_AttackBody->setRotation(rotataion);
}

void Attack::m_DrawAttackBody(sf::RenderWindow & window)
{
	if (m_AttackBody.get() != nullptr)
	{
		window.draw(*m_AttackBody);
	}
}

void Attack::m_UpdatePos(sf::Vector2f newPos)
{
	if (m_AttackBody.get() != nullptr)
	{
		m_AttackBody->setPosition(newPos);
	}
}

void Attack::m_DestroyAttackBody()
{
	m_AttackBody.reset(new sf::RectangleShape());
}

bool Attack::m_HitDetection(sf::Vector2f pointToCheck)
{
	if (m_AttackBody->getGlobalBounds().contains(pointToCheck))
	{
		return true; 
	}

	return false;
}

bool Attack::m_ThisExists()
{
	if (m_AttackBody.get() != nullptr)
	{
		return true; 
	}

	return false;
}
