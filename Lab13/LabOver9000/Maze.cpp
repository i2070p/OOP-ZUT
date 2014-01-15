#include "stdafx.h"
#include "Maze.h"

void Maze::addPlayer(OffensiveObject* _player) {
			player=_player;
	int x,y;
	do {
		x=rand()%size;
		y=rand()%size;
	} while (rooms[x][y]==NULL && !position->getWest()->isWall());

	rooms[x][y]->setObject(player);
	position=rooms[x][y];
}


GameObject* Maze::step(Room* _posC) {
	GameObject* result=NULL;
	position->setObject(NULL);
	position=_posC->visit();
	if (position->getObject()) result=position->getObject();
	position->setObject(player);
	return(result);

}
GameObject* Maze::go(Course course) {
	GameObject* result=NULL;
	switch (course) {
	case N: if (position->getNorth()!=NULL && !position->getNorth()->isWall()) {
		result=step(position->getNorth());
			}
			break;
	case E: if (position->getEast()!=NULL && !position->getEast()->isWall()) {
		result=step(position->getEast());

			}break;
	case S: if (position->getSouth()!=NULL && !position->getSouth()->isWall()) {
			result=step(position->getSouth());

			}
			break;
	case W: if (position->getWest()!=NULL && !position->getWest()->isWall() ) {
		result=step(position->getWest());
			}break;
	}
	return(result);
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
				if (rooms[i][j]->getObject()) ss << rooms[i][j]->getObject()->getOutfit(); else ss << " "; 
			} else ss << "X";
		}
		ss << "X" << endl;
	}
	ss<<up_down<<endl;
	return(ss.str());

}

void Maze::addObj(GameObject* _obj) {
	int x,y;
	do {
		x=rand()%size;
		y=rand()%size;
	} while (rooms[x][y]==NULL && !position->getWest()->isWall());
	rooms[x][y]->setObject(_obj);
}
