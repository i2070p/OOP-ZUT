#include "ProcessList.h"
#include <sstream>
#include <iostream>
#include <algorithm>


ProcessList::ProcessList() {
	LPID=0;
	processRegistry=NULL;
}


ProcessList::~ProcessList() {

}

void ProcessList::connectStrategy(Strategy* _strategy) {
	strategy=_strategy;
}

void ProcessList::connectProcessRegistry(ProcessRegistry *_processRegistry) {
	processRegistry=_processRegistry;
}

vector<Process>::size_type ProcessList::getProcessCount() {
	return(processList.size());
}


void ProcessList::addProcess(int stepCount, int stepTime) {
	Process *new_process = new Process(incLPID(),stepCount,stepTime); 
	processList.push_back(new_process);
}

void ProcessList::addProcess(Process* _process) {
	processList.push_back(_process);
}

int ProcessList::getLPID() {
	return(LPID);
}

int ProcessList::incLPID() {
	return(LPID++);
}


Process* ProcessList::getProcess(int id) {
	if (id >= 0 && id < getProcessCount() ) return(processList[id]);
	return(NULL);
}

void ProcessList::resetProcess() {
	for (vector<Process*>::size_type i=0; i<getProcessCount(); i++) processList[i]->reset(); 
}


void ProcessList::Run() {
	if (strategy) strategy->run(processList, processRegistry);
}