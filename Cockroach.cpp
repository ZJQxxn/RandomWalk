//Cockroach.cpp : Implementation of clas:'Cockroach'
#include "Cockroach.h"

//Constructor
Cockroach::Cockroach(int x, int y,int xb,int yb)
	:xPos(x)
	, yPos(y)
	, xBound(xb)
	, yBound(yb)
	, moveCount(0)
{

}


//private operations
/*
	Move northward.

	Return:void
*/
void Cockroach::_moveN()
{
	if ((yPos - 1) >= 0)
	{
		yPos--;
		moveCount++;
	}
}

/*
	Move northeastward.

	Return:void
*/
void Cockroach::_moveNe()
{
	if (((yPos - 1) >= 0) && ((xPos + 1) < xBound))
	{
		yPos--;
		xPos++;
		moveCount++;
	}
}
/*
	Move eastward.

	Return:void
*/
void Cockroach::_moveE()
{
	if ((xPos + 1) < xBound)
	{
		xPos++;
		moveCount++;
	}
}

/*
	Move southeastward.

	Return:void
*/
void Cockroach::_moveSE()
{
	if (((xPos + 1) < xBound) && ((yPos + 1) < yBound))
	{
		xPos++;
		yPos++;
		moveCount++;
	}
}

/*
	Move southward.

	Return:void
*/
void Cockroach::_moveS()
{
	if ((yPos + 1) < yBound)
	{
		yPos++;
		moveCount++;
	}
}

/*
	Move southwestward.

	Return:void
*/
void Cockroach::_moveSW()
{
	if (((yPos + 1) < yBound) && ((xPos - 1) >= 0))
	{
		yPos++;
		xPos--;
		moveCount++;
	}
}

/*
	Move westward.

	Return:void
*/
void Cockroach::_moveW()
{
	if ((xPos - 1) >= 0)
	{
		xPos--;
		moveCount++;
	}
}

/*
	Move northwestward.

	Return:void
*/
void Cockroach::_moveNW()
{
	if (((xPos - 1) >= 0) && ((yPos - 1) >= 0))
	{
		xPos--;
		yPos--;
		moveCount++;
	}
}


//Public operations
/*
	Get the current position of the cockroach.

	Return:type:'BugPos'	A pair of integers indicate current postion.
*/
BugPos Cockroach::getPos()
{
	return pair<int, int>(xPos, yPos);
}

/*
	Get movement counts.

	Return:int
*/
int Cockroach::getMoves()
{
	return moveCount;
}

/*
	Move the cockroach.


	Parameter:dir	int		The direction you want move to.
*/
void Cockroach::move(int dir)
{
	switch (dir)
	{
	case 0:
		_moveN();
		break;
	case 1:
		_moveNe();
		break;
	case 2:
		_moveE();
		break;
	case 3:
		_moveSE();
		break;
	case 4:
		_moveS();
		break;
	case 5:
		_moveSW();
		break;
	case 6:
		_moveW();
		break;
	case 7:
		_moveNW();
		break;
	default:
		break;
	}
}
