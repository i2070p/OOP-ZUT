#include "ProcessList.h"
#include <sstream>
ProcessList::ProcessList() {
	LPID=0;
}

ProcessList::~ProcessList() {

}

void ProcessList::addProcess(int stepCount, int stepTime) {
	Process *new_process = new Process(incLPID(),stepCount,stepTime); //5, 2 - dorobic losowanie
	processList.push_back(new_process);
}

int ProcessList::getLPID() {
	return(LPID);
}

int ProcessList::incLPID() {
	return(++LPID);
}

void ProcessList::Run() {
	activeProcess=processList[0];
	activeProcess->setState(ACTIVE);
	vector<Process>::size_type size=processList.size();
	
	stringstream ss;

	for (vector<Process*>::size_type i=0; i<size; i++) {
		
		if (processList[i]==activeProcess) {
				activeProcess->stepMove();
		} 
		ss << processList[i]->getState<< endl; 
	}
}
