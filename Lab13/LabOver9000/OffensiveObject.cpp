#include "OffensiveObject.h"

OffensiveObject::OffensiveObject(std::string _info,int _hp, char _outfit, int _damage, std::string _txt_shout):
GameObject(_info,_hp,_outfit), damage(_damage), txt_shout(_txt_shout) {
}

OffensiveObject::~OffensiveObject(void) {}

int OffensiveObject::attack() {
	if (damage<=0) return(0);
	return(rand()%damage);
}
std::string OffensiveObject::shout() {
  return(txt_shout);
}
