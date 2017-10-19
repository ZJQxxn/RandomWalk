//Room.h : Declaretion of class:'Room'
#ifndef ROOM_H
#define ROOM_H
#include "Cockroach.h"

//See implementation in Room.cpp
class Room
{
	Cockroach bug;
	int xBound, yBound;
	int **counts;

	//private operations
	bool _finished();
public:
	Room(int xb = 0, int yb = 0, int xp = 0, int yp = 0);
	void randomMove();
	int** getCounts();
	void showResult();
};
#endif