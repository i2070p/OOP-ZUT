#pragma once
#include "gameobject.h"

class PassiveObject: public GameObject {
        public:
                PassiveObject(std::string,int, char, int, int);
                ~PassiveObject(void);
                int defend(int);
				int getSize();
        protected:
                int defense, size;                 
};
