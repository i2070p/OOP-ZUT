#pragma once
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include "Room.h"
#include "OffensiveObject.h"

using namespace std;
enum Course {
	N = 0,
	E = 1,
	S = 2,
	W = 3
};


class Maze {
public:
	Maze(int,char*);
	~Maze(){};
	GameObject* go(Course);
	void showMaze();
	string getRoomInfo();
	string toString();
	void addObj(GameObject*);
	void addPlayer(OffensiveObject*);
private:
	Room*** rooms;
	int size;
	Room* position;
	OffensiveObject* player;
	GameObject* step(Room*);
};

