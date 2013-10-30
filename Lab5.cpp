#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>

using namespace std;
enum Course {
	N = 0,
	E = 1,
	S = 2,
	W = 3
};

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
private:
	Room *south, *north, *west, *east;
	bool visited;
	string description;
};

class Maze {
public:
	Maze(int,char*);
	~Maze(){};
	void go(Course);
	void showMaze();
	string getRoomInfo();
	string toString();
private:
	Room*** rooms;
	int size;
	Room* position;

};

void Maze::go(Course course) {
	switch (course) {
		case N: if (position->getNorth()!=NULL) position=position->getNorth()->visit(); break;
		case E: if (position->getEast()!=NULL) position=position->getEast()->visit(); break;
		case S: if (position->getSouth()!=NULL) position=position->getSouth()->visit();  break;
		case W: if (position->getWest()!=NULL) position=position->getWest()->visit(); break;
	}
}

Maze::Maze(int _size, char* pattern):size(_size) {
	rooms = new Room**[size];
	for (int i=0;i<size;i++) rooms[i]=new Room*[size];
	int k=0;
	bool create=true;
	for (int z=0; z<2; z++) {
		for (int i=0; i<size;i++)
			for (int j=0; j<size;j++) {
				if (create) {
					stringstream ss;
					ss << "Room #" << ++k;
					rooms[i][j] = new Room(ss.str());
				} else {
					Room *south=NULL, *north=NULL, *west=NULL, *east=NULL;
					if (pattern[i*size+j]!='1') {
						if (i-1>=0) if (pattern[i*(size-1)+j]=='0') north=rooms[i-1][j];
						if (i+1<size) if (pattern[i*(size+1)+j]=='0') south=rooms[i+1][j];
						if (j-1>=0) if (pattern[i*size+(j-1)]=='0') west=rooms[i][j-1];
						if (j+1<size) if (pattern[i*size+(j+1)]=='0') east=rooms[i][j+1];
					}
					rooms[i][j]->setDoors(south,north,west,east);
				}

			}

			create=false;
	}
	position=rooms[0][0]->visit();
}

string Maze::getRoomInfo() {
	return(position->getDescription());
}

string Maze::toString() {
	stringstream ss;
	string up_down="";
	for (int i=0; i<size+2;i++) up_down+="X";
	ss<<up_down<<endl;
	for (int i=0; i<size;i++) {
		ss << "X";
		for (int j=0; j<size;j++) {
			if (!rooms[i][j]->isWall()) {
				if (rooms[i][j]->isVisited()) ss << "1"; else ss << "0"; 
			} else ss << "X";
		}
		ss << "X" << endl;
	}
	ss<<up_down<<endl;
	return(ss.str());

}

int main()
{
	char *pattern= "0000000000000000000000000";

	Maze *maze = new Maze(5,pattern);
	cout << maze->toString() << endl;
	maze->go(E);
	maze->go(S);
	maze->go(E);
	maze->go(E);
	maze->go(S);
	maze->go(W);
	maze->go(S);
	maze->go(W);
	maze->go(W);
	maze->go(W);
	maze->go(N);

	cout << maze->toString();

	getchar();
	return(0);
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
