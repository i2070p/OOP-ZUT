#include "FIFO.h"
#include "stdafx.h"
using namespace std;


void FIFO::run(std::vector <Process*> processList, ProcessRegistry* processRegistry) {
        vector<Process>::size_type processCount=processList.size();
        if (processCount<=0) throw exception ("Process list is empty!");
        else {
                bool reg=false;
                if (processRegistry) reg=true;
                string *tab=NULL;

                if (reg) for (int i=0; i<processCount; i++) processRegistry->addProcessPID(processList[i]->getPID());
                int finishedCount=0,offset=0;
                Process *current=processList[0];

                while (finishedCount < processCount) {
                        current->active();
                        for (vector<Process*>::size_type i=0; i<processCount; i++) 
							if (reg) processRegistry->addPStep(processList[i]->getPID(), processList[i]->getStateChar());
      

                        PState afterStep = current->doStep();
                        if (afterStep!=ACTIVE) {

                                if (afterStep==FINISHED) finishedCount++;
                                if (finishedCount < processCount)
                                        do {
                                                processList.push_back(current);
                                                processList.erase(processList.begin());
                                                current=processList[0];
                                        } while (!current->isSuspended());
                        }

                }
               if (reg) {
				   processRegistry->addLine("Strategy: FIFO");
				   processRegistry->clear();
			   }
               for (vector<Process*>::size_type i=0; i<processList.size(); i++) processList[i]->reset();
        }
}

