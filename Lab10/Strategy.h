#include "stdafx.h"
#include "ProcessRegistry.h"
#include "Process.h"

class Strategy {
	public:
		Strategy(){};
		~Strategy(){};
		virtual void run(std::vector <Process*> processList, ProcessRegistry*) = 0;
};

class FIFO: public Strategy {
	public:
		FIFO(){};
		~FIFO(){};
		void run(std::vector <Process*> processList, ProcessRegistry*);
};


class SJF: public Strategy {
	public:
		SJF(){};
		~SJF(){};
		void run(std::vector <Process*> processList, ProcessRegistry*);
};
