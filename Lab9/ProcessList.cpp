#include "ProcessList.h"
#include <sstream>
#include <iostream>

ProcessList::ProcessList() {
	LPID=0;
	processRegistry=NULL;
}


ProcessList::~ProcessList() {

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
	vector<Process>::size_type processCount=getProcessCount();
	if (processCount<=0) throw exception ("Process list is empty!");
	else {
		bool reg=false;
		if (processRegistry) reg=true; 
		string *tab=NULL;

		if (reg) {
			tab=new string[processCount];
			for (int i=0; i<processCount; i++) {

				stringstream ss;
				ss<<"PID:"<<getProcess(i)->getPID()<<": ";
				tab[i]=ss.str();
			}
		}
		int finishedCount=0,offset=0;
		Process *current=processList[0];

		while (finishedCount < processCount) {
			current->active();

			for (vector<Process*>::size_type i=0; i<processCount; i++) {
				int ioff = i + offset;
				if (reg) {
					if (ioff < processCount ) tab[ioff]+=processList[i]->getStateChar(); 
					else tab[ioff-processCount]+=processList[i]->getStateChar();
				}
			}

			PState afterStep = current->doStep();
			if (afterStep!=ACTIVE) {

				if (afterStep==FINISHED) finishedCount++;
				if (finishedCount < processCount)
					do {

						if (reg) offset=(++offset)%processCount;
						processList.push_back(current);
						processList.erase(processList.begin()); 
						current=processList[0];
					} while (!current->isSuspended());
			}

		}
		if (reg) {
			stringstream ss;
			for (vector<Process*>::size_type i=0; i<processCount; i++) ss << tab[i] << endl;
			processRegistry->addHistoryItem(ss.str()); 
		}
		resetProcess();
	}
}