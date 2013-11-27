#pragma once
#include "Process.h"
#include <vector>

class ProcessList {
public:
	ProcessList();
	~ProcessList();
	void addProcess(int, int);
	int getLPID();
	void Run();
private:
	int incLPID();

	Process* activeProcess;
	vector <Process*> processList;
	int LPID;
};
