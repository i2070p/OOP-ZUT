#include "GameObject.h"
#include "stdafx.h"
GameObject::GameObject(std::string _info, int _hp, char _outfit): info(_info), hp(_hp), outfit(_outfit) {

}

GameObject::~GameObject(){}





int GameObject::getHP() {
	return(hp);
}

char GameObject::getOutfit() {
	return(outfit);
}

int GameObject::subHP(int m_hp) {
	int tmp = m_hp;
	if (hp-m_hp<=0) { 
		tmp=hp;
		hp=0; 
	} else hp=hp-m_hp;
	return(tmp);
}

bool GameObject::isDead() {
	if (hp<=0) return(true); 
	return(false);
}

std::string GameObject::getInfo() {
	return(info);
}

void GameObject::setInfo(std::string _info) {
	info=_info;
}
