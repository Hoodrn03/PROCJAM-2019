#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/*! \class RandomGenerator : Used to generate random items. */
class RandomGenerator
{
	// Constructor 

public:

	RandomGenerator()
	{
		// Sets a new seed for the random generator, allows for truely random numbers.

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

	/*! \fn GenerateInt : Used to output an integer value between a min and a max. 
	param one : int : The minimun number the generator can output. 
	param two : int : The maximum number the generator can output. 
	*/
	int m_GererateInt(int min, int max)
	{
		int l_Random = rand() % max + min;

		std::cout << l_Random << std::endl;

		return l_Random; 
	}
};