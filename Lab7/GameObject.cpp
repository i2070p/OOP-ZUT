#include "GameObject.h"

GameObject::GameObject(std::string _info, int _hp): info(_info), hp(_hp) {
	next=NULL;
}

GameObject::~GameObject(){}

void GameObject::setNext(GameObject* _next) {
	next=_next;	
}

GameObject* GameObject::getNext() {
	return(next);
}


int GameObject::getHP() {
	return(hp);
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
