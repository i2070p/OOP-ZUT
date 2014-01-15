
#pragma once
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include "GameObject.h"
using namespace std;

class Room {
public:
	Room(string);
	~Room(){};
	Room* getSouth();
	Room* getNorth();
	Room* getWest();
	Room* getEast();
	Room* visit();
	bool isVisited();
	void setVisited(bool);
	bool isWall();

	void setDoors(Room *,Room *, Room *, Room *);
	string getDescription();

	void setObject(GameObject*);
	GameObject* getObject();
private:
	Room *south, *north, *west, *east;
	bool visited;
	string description;
	GameObject* object;
};