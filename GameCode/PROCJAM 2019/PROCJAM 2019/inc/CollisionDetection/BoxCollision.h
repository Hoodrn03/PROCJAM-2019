#pragma once

/*! \class BoxCollision This will be used to detect if a box contains a point as well as 
			using AABB to detect collisions. */
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

	/*! \fn InsideBox - Used to check if a point is within a box. 
	param one : float : The left side of the box.
	param two : float : the top of the box.
	param three : float : The width of the box. 
	param four : float : The height of the box. 
	param five : float : The X position to check. 
	param six : float : The Y position to check. 
	*/
	bool m_InsideBox(float boxX, float boxY, float boxWidth, float boxHeight, float px, float py)
	{

		if ((px > boxX && py > boxY) && (px < boxX + boxWidth && py < boxY + boxHeight))
		{
			return true;
		}

		return false; 
	}

	/*! \fn ExitBox - This will output the direction the point has left the box from, (1 - top, 2 - bottom, 3 - left, 4 - right).
	param one : float : The left side of the box.
	param two : float : the top of the box.
	param three : float : The width of the box.
	param four : float : The height of the box.
	param five : float : The X position to check.
	param six : float : The Y position to check.
	*/
	int m_ExitBox(float boxX, float boxY, float boxWidth, float boxHeight, float px, float py)
	{
		float l_fCollBuffer = 15.f;

		// Top
		if ((px > boxX) && (px < boxX + boxWidth) && (py > boxY - l_fCollBuffer) && (py < boxY + l_fCollBuffer))
		{
			// std::cout << "Top" << std::endl;

			return 0;
		}
		// Bottom
		else if ((px > boxX) && (px < boxX + boxWidth) && (py > (boxY + boxHeight) - l_fCollBuffer) && (py < (boxY + boxHeight) + l_fCollBuffer))
		{
			// std::cout << "Bottom" << std::endl;

			return 1;
		}
		// Left
		else if ((py > boxY) && (py < boxY + boxHeight) && (px > (boxX) - l_fCollBuffer) && (px < (boxX) + l_fCollBuffer))
		{
			// std::cout << "Left" << std::endl;

			return 2;
		}
		// Right
		else if ((py > boxY) && (py < boxY + boxHeight) && (px > (boxX + boxWidth) - l_fCollBuffer) && (px < (boxX + boxWidth) + l_fCollBuffer))
		{
			// std::cout << "Right" << std::endl;

			return 3;
		}

		return -1;
	}

};