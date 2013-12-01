#pragma once
#include "Process.h"
#include "ProcessRegistry.h"

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
private:
        int incLPID();
		void resetProcess();
		ProcessRegistry* processRegistry;
        vector <Process*> processList;
        int LPID;
};