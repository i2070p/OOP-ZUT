#include "SJF.h"
#include <algorithm>

int SJF::find(std::vector <Process*> processList, Process* process) {
	for (vector<Process*>::size_type i=0; i<processList.size(); i++) if (processList[i]==process) return(i);
	return(-1);
}

void SJF::run(std::vector <Process*> processList, ProcessRegistry* processRegistry) {
	vector<Process>::size_type processCount=processList.size();


	if (processCount<=0) throw exception ("Process list is empty!");
	else {
		bool reg=false;
		if (processRegistry) reg=true;

		if (reg) for (int i=0; i<processCount; i++) processRegistry->addProcessPID(processList[i]->getPID());
		int finishedCount=0;

		sort(processList.begin(), processList.end(), [](Process* p1, Process* p2) {return (p1->getStepTime() < p2->getStepTime());});

		Process *current=processList[0];
		current->active();
		//******************
		while (finishedCount < processCount) {
			if(reg) for (vector<Process*>::size_type i=0; i<processList.size(); i++) processRegistry->addPStep(processList[i]);

			PState afterStep = current->doStep();

			if (afterStep!=ACTIVE) {
				if (afterStep==FINISHED) finishedCount++;

				if (finishedCount < processCount) {

					processList.push_back(current);
					processList.erase(processList.begin()+find(processList,current)); 
					
					sort(processList.begin(), processList.end()-1, [](Process* p1, Process* p2) {return (p1->getStepTime() < p2->getStepTime());});
					
					for (vector<Process*>::size_type i=0; i<processList.size(); i++) {
						if (processList[i]->isSuspended()) {
							current=processList[i];
							current->active();
							break;
						}
					}

				}
			}
		}
		//******************

		if (reg) {
			processRegistry->addLine("Strategy: SJF");
			processRegistry->clear();
		}
		for (vector<Process*>::size_type i=0; i<processList.size(); i++) processList[i]->reset();
	}
}

