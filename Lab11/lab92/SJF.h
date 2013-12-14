#include "Strategy.h"
#include "ProcessList.h"
class SJF: public Strategy {
        public:
                SJF(){};
                ~SJF(){};
                void run(std::vector <Process*> processList, ProcessRegistry*);
		private:
			int find(std::vector <Process*>, Process*);
};