//Cockroach.h : Declaretion of class:'Cockroach'
#ifndef COCKROACH_H
#define COCKROACH_H
#include <iostream>
using std::pair;
typedef pair<int, int> BugPos; //store postion of cockroach

//See implementation in Cockroach.cpp
class Cockroach
{
private:
	int xPos, yPos;
	int moveCount;
	int xBound, yBound;
	static enum moveSelect {N,NE,E,SE,S,SW,W,NW};//All the directions cockroach cna move.

	//private operations
	void _moveN();
	void _moveNe();
	void _moveE();
	void _moveSE();
	void _moveS();
	void _moveSW();
	void _moveW();
	void _moveNW();
public:
	Cockroach(int x = 0, int y = 0, int xb = 0, int yb = 0);
	BugPos getPos();
	void move(int dir);
	int getMoves();
};
#endif