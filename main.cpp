//main.cpp : Main function to test 'random walk'
#include "Room.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int xBound, yBound;
	int xPos, yPos;
	cout << "Enter width and length of this room(m):";
	cin >> yBound >> xBound;
	cout << "Enter start position of cockroach:";
	cin >> xPos >> yPos;
	Room room(xBound, yBound, xPos, yPos);
	room.randomMove();
	room.showResult();

	system("pause");
	return 0;
}