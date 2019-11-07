#pragma once

class BoxCollision
{
	// Constructor 

public:

	BoxCollision()
	{

	}

	// Deconstructor 

	~BoxCollision()
	{

	}

	// Data Members 

private:

	// Member Functions 

public:

	bool m_InsideBox(float boxX, float boxY, float boxWidth, float boxHeight, float px, float py)
	{

		if ((px > boxX && py > boxY) && (px < boxX + boxWidth && py < boxY + boxHeight))
		{
			return true;
		}

		return false; 
	}

	int m_ExitBox(float boxX, float boxY, float boxWidth, float boxHeight, float px, float py)
	{
		float l_fCollBuffer = 15.f;

		// Top
		if ((px > boxX) && (px < boxX + boxWidth) && (py > boxY - l_fCollBuffer) && (py < boxY + l_fCollBuffer))
		{
			std::cout << "Top" << std::endl;

			return 1;
		}
		// Bottom
		else if ((px > boxX) && (px < boxX + boxWidth) && (py > (boxY + boxHeight) - l_fCollBuffer) && (py < (boxY + boxHeight) + l_fCollBuffer))
		{
			std::cout << "Bottom" << std::endl;

			return 2;
		}
		// Left
		else if ((py > boxY) && (py < boxY + boxHeight) && (px > (boxX) - l_fCollBuffer) && (px < (boxX) + l_fCollBuffer))
		{
			std::cout << "Left" << std::endl;

			return 3;
		}
		// Right
		else if ((py > boxY) && (py < boxY + boxHeight) && (px > (boxX + boxWidth) - l_fCollBuffer) && (px < (boxX + boxWidth) + l_fCollBuffer))
		{
			std::cout << "Right" << std::endl;

			return 4;
		}

		return -1;
	}

};