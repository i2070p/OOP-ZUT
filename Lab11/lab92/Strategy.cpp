#include "Strategy.h"
#include "stdafx.h"
using namespace std;


void FIFO::run(std::vector <Process*> processList, ProcessRegistry* processRegistry) {
        vector<Process>::size_type processCount=processList.size();
        if (processCount<=0) throw exception ("Process list is empty!");
        else {
                bool reg=false;
                if (processRegistry) reg=true;
                string *tab=NULL;

                if (reg) {
                        tab=new string[processCount];
                        for (int i=0; i<processCount; i++) {

                                stringstream ss;
                                ss<<"PID:"<<processList[i]->getPID()<<": ";
                                tab[i]=ss.str();
                        }
                }
                int finishedCount=0,offset=0;
                Process *current=processList[0];

                while (finishedCount < processCount) {
                        current->active();
                        for (vector<Process*>::size_type i=0; i<processCount; i++) {
                                if (reg) {
                                        int ioff = i + offset;
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
                for (vector<Process*>::size_type i=0; i<processList.size(); i++) processList[i]->reset();
        }
}


void SJF::run(std::vector <Process*> processList, ProcessRegistry* processRegistry) {
        vector<Process>::size_type processCount=processList.size();
        if (processCount<=0) throw exception ("Process list is empty!");
        else {
                bool reg=false;
                if (processRegistry) reg=true;
                string *tab=NULL;

                if (reg) {
                        tab=new string[processCount];
                        for (int i=0; i<processCount; i++) {

                                stringstream ss;
                                ss<<"PID:"<<processList[i]->getPID()<<": ";
                                tab[i]=ss.str();
                        }
                }

                int finishedCount=0,offset=0;
                Process *current=processList[0];

                while (finishedCount < processCount) {
                        current->active();
                        for (vector<Process*>::size_type i=0; i<processCount; i++) {
                                if (reg) {
                                        int ioff = i + offset;
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
                for (vector<Process*>::size_type i=0; i<processList.size(); i++) processList[i]->reset();
        }        
}