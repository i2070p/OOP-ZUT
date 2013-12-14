#pragma once
#include "Process.h"
#include "ProcessRegistry.h"
#include "Strategy.h"
using namespace std;

class ProcessList {
public:
        ProcessList();
        ~ProcessList();
        void addProcess(int, int);
		void connectProcessRegistry(ProcessRegistry*);
        void addProcess(Process*);
		Process* getProcess(int);
		vector<Process>::size_type getProcessCount();
        int getLPID();
        void Run();
		void connectStrategy(Strategy*);
private:
        int incLPID();
		void resetProcess();
		Strategy* strategy;
		ProcessRegistry* processRegistry;
        vector <Process*> processList;
        int LPID;
};