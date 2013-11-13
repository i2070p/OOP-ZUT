#pragma once
#include <string>
#include <iostream>
#include <time.h>

class GameObject {
public:
	GameObject(){};
	GameObject(std::string,int);
	~GameObject();
	bool isDead();
	std::string getInfo();
	int subHP(int);
	int getHP();
	void setInfo(std::string);
	void setNext(GameObject*);
	GameObject* getNext();
protected:
	float hp;
	std::string info;
	GameObject* next;
};
