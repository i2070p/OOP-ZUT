#pragma once
#include <string>
#include <iostream>
#include <time.h>

class GameObject {
public:
	GameObject(){};
	GameObject(std::string,int,char);
	~GameObject();
	bool isDead();
	std::string getInfo();
	int subHP(int);
	int getHP();
	void setInfo(std::string);
	char getOutfit();
protected:
	float hp;
	char outfit;
	std::string info;
};
