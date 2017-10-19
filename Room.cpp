//Room.cpp : Implementation of class:'Room'
#include "Room.h"
#include "Cockroach.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_ITER	50000

/*
	Be careful the relationship between row¡¢column and xPos¡¢yPos!
*/

//Constructor
Room::Room(int xb, int yb,int xp,int yp)
{
	xBound = xb;
	yBound = yb;
	bug = Cockroach(xp, yp, xb, yb);
	//Create counts
	counts = new int*[yBound];
	for (int i = 0; i < yBound; i++)
	{
		counts[i] = new int[xBound];
	}
	//Initialize counts
	for (int i = 0; i < yBound; i++)
	{
		for (int j = 0; j < xBound; j++)
		{
			counts[i][j] = 0;
		}
	}

	//add 1 to current position count
	BugPos cur_pos = bug.getPos();
	counts[cur_pos.second][cur_pos.first]++;
}


//private operations
/*
	Determine whether all the positons has been passed.

	Return:bool
*/
bool Room::_finished()
{
	for (int i = 0; i < yBound; i++)
	{
		for (int j = 0; j < xBound; j++)
		{
			if (counts[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}


//public operations
/*
	Get 2d array 'counts'.

	Return:int**
*/
int** Room::getCounts()
{
	return counts;
}

/*
	Move randomly.

	Return:void
*/
void Room::randomMove()
{
	srand(time(0));
	int iters = 0;
	int num = 0;
	while (!_finished() && iters < MAX_ITER)
	{
		num = rand() % 8;
		//cout << (iters + 1) << " iterations :" << num << endl;/////////////
		bug.move(num);
		BugPos pos = bug.getPos();
		counts[pos.second][pos.first]++;
		iters++;
	}

}

/*
	Print the result,including counts of movements and
	the 2d array 'counts'.

	Return:void
*/
void Room::showResult()
{
	cout << "\nTotal movements :" << bug.getMoves() << endl;
	cout << "Counts:\n";
	for (int i = 0; i < yBound; i++)
	{
		for (int j = 0; j < xBound; j++)
		{
			cout << counts[i][j] << "  ";
		}
		cout << endl;
	}
}