#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

/*! \class Attack : Used to allow for entities to spawn an attack object. */
class Attack
{
	// Constructor 

public:

	Attack();

	// Deconstructor 

	~Attack();

	// Data Memvers 

private:

	/*! \var The damage the attack will deal if it hits another object. */
	const float m_fDamage = 15.f;

	/*! \var The main body for the attack, it will be a pointer so it can be easily be created and deleted during the game. */
	std::unique_ptr<sf::RectangleShape> m_AttackBody; 

	/*! \var The constant size for the attack sprite. */
	const sf::Vector2f m_AttackSize{ 75, 25 };

	// Member Functions 

public:

	/*! \fn CreateAttackBody : Used to initalize the attck object. 
	param one : vector2f : The position to spawn the attack. 
	*/
	void m_CreateAttackBody(sf::Vector2f newPos);

	/*! \fn CreateAttackBody (overload one): Used to initalize the attck object.
	param one : vector2f : The position to spawn the attack.
	param two : float : the rotation for the attack object. 
	*/
	void m_CreateAttackBody(sf::Vector2f newPos, float rotataion);

	/*! \fn DrawAttackBody : Used to display the attack on the screen. 
	param one : renderwindow : The main game window. 
	*/
	void m_DrawAttackBody(sf::RenderWindow & window);

	/*! \fn UpdatePos : Used to move the attack body to a new position 
	param one : vector2f : the new position for the sprite. 
	*/
	void m_UpdatePos(sf::Vector2f newPos); 

	/*! \fn DestroyAttackBody : Used to destroy the current attack object in the game. */
	void m_DestroyAttackBody(); 

	/*! \fn HitDetection : Used to check if a given point is inside the attack body. 
	param one : vector2f : the coord for the object to check. 
	*/
	bool m_HitDetection(sf::Vector2f pointToCheck);

	/*! \fn ThisExists : Used to check if there is currently an attack body in the game. */
	bool m_ThisExists(); 

};