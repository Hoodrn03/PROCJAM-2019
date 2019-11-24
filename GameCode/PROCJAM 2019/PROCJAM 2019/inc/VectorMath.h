#pragma once


#include <cmath>

constexpr auto PI = 3.14159265f;

struct Vector
{
	float x, y, z;
};

class VectorMath
{
public:

	// Constructor 

	VectorMath()
	{

	}

	// Dectonstructor 

	~VectorMath()
	{

	}

private:

	// Data Members 

public:

	// Member Functions 

	float m_CalculateMagnitude(float x1, float y1, float x2, float y2)
	{
		float l_fMagnitude = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

		return l_fMagnitude;
	}

	Vector NormaliseVector(float x1, float y1, float x2, float y2)
	{
		Vector l_CurrentVector = { x2 - x1, y2 - y1 };

		float l_fMagnitude = m_CalculateMagnitude(x1, y1, x2, y2);

		Vector l_ReturnValue = Vector{ l_CurrentVector.x / l_fMagnitude, l_CurrentVector.y / l_fMagnitude };

		return l_ReturnValue;
	}

	float m_CalculateAngleBetweenVectors()
	{

	}

};