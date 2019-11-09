#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class RandomGenerator
{
	// Constructor 

public:

	RandomGenerator()
	{
		srand(time(NULL));
	}

	// Deconstructor

	~RandomGenerator()
	{

	}

	// Data Members 

private:

	// Member Functions 

public:

	int m_GererateInt(int min, int max)
	{
		int l_Random = rand() % max + min;

		std::cout << l_Random << std::endl;

		return l_Random; 
	}
};