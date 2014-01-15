#pragma once
#include "gameobject.h"

class OffensiveObject: public GameObject {
public:
	OffensiveObject(std::string, int,char, int, std::string);
	~OffensiveObject();
	int attack();
	std::string shout();
protected:
	int damage;
	std::string txt_shout;
};
