#pragma once

#include <iostream>
#include <deque>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/BoxCollision.h"
#include "Random/RandomGenerator.h"

#include "Cell.h"



/*! \class This will hold the grid which will form the game map. */
class Grid : public BoxCollision, public RandomGenerator
{
	// Constructor 

public:

	Grid();

	// Deconstructor 

	~Grid();

	// Data Members 

private:


	// Member Functions 

public:

};