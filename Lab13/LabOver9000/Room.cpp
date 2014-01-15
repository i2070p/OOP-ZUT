#include "stdafx.h"
#include "Room.h"


void Room::setObject(GameObject* _obj) {
	object=_obj;
}

GameObject* Room::getObject() {
	return(object);
}


bool Room::isWall() {
	if (getEast()!=NULL || getWest()!=NULL || getNorth()!=NULL || getSouth()!=NULL) 
		return(false); else return(true);

}

Room* Room::visit() {
	setVisited(true);
	return(this);
}

void Room::setVisited(bool _visited) {
	visited=_visited;
}

Room::Room(string _description): description(_description) {
	visited=false;
	south=NULL;
	north=NULL;
	east=NULL;
	west=NULL;
}

void Room::setDoors(Room *_south,Room *_north, Room *_west, Room *_east) {
	south=_south;
	north=_north;
	west=_west;
	east=_east;
}

bool Room::isVisited() {
	return(visited);
}

Room* Room::getSouth() {
	return(south);
}

Room* Room::getNorth() {
	return(north);
}

Room* Room::getWest() {
	return(west);
}

Room* Room::getEast() {
	return(east);
}

string Room::getDescription() {
	return(description);
}