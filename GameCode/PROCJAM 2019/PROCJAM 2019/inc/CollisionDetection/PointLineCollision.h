#pragma once

#include <cmath>

class PointLineCollision
{
	// Constructor 

public:

	PointLineCollision()
	{

	}

	// Deconstructor 

	~PointLineCollision()
	{

	}

	// Data Members 

private:

	// Member Functions 

public:

	bool m_LineCollision(float x1, float y1, float x2, float y2, float px, float py)
	{

		float l_fDist1 = m_Dist(x1, y1, px, py);
		float l_fDist2 = m_Dist(x2, y2, px, py);

		// std::cout << "Distance : " << l_fDist1 << ", " << l_fDist2 << ". ";

		float l_fLineLen = m_Dist(x1, y1, x2, y2);

		// std::cout << "Line len : " << l_fLineLen << std::endl;

		float l_fBuffer = 1.f; 

		if ((l_fDist1 + l_fDist2 >= l_fLineLen - l_fBuffer) && (l_fDist1 + l_fDist2 <= l_fLineLen + l_fBuffer))
		{
			return true;
		}

		return false; 

	}

	float m_Dist(float x1, float y1, float x2, float y2)
	{

		float l_fReturnValue = 0;

		l_fReturnValue = std::sqrt((x2 - x1) + (y2 - y1));

		return l_fReturnValue; 

	}


};