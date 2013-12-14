#include "Strategy.h"
using namespace std;

class FIFO: public Strategy {
        public:
                FIFO(){};
                ~FIFO(){};
                void run(std::vector <Process*> processList, ProcessRegistry*);
};