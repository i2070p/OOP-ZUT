
#include "PassiveObject.h"
#include "stdafx.h"

PassiveObject::PassiveObject(std::string _info,int _hp,char _outfit, int _defense, int _size):
GameObject(_info,_hp, _outfit), defense(_defense), size(_size){
}

int PassiveObject::defend(int attack) {
	int def;
	if (defense>0) def = rand() % defense; else def=0;
	if ((attack-def)<=0) return(subHP(0)); else return(subHP(attack-def));
}

int PassiveObject::getSize(){
	return(size);
}

PassiveObject::~PassiveObject(){}
