#include "ProcessRegistry.h"


ProcessRegistry::ProcessRegistry() {
	
}

ProcessRegistry::~ProcessRegistry(){}

string ProcessRegistry::toString() {
	stringstream ss;
	ss.str("");
	for (vector<string*>::size_type i=0; i<history.size(); i++) {
		//ss << "____________" << /*getTime()*/ i << "____________\n";
		ss << history[i];
		ss << endl;
	}


	return(ss.str());
}


void ProcessRegistry::addHistoryItem() {
	stringstream ss;
	for (vector<ProcessSteps>::size_type i=0; i<p_steps.size(); i++) ss << p_steps[i].getSteps() << endl;
	history.push_back(ss.str());
}

void ProcessRegistry::addPStep(int PID, char Z){
	for (vector<ProcessSteps>::size_type i=0; i<p_steps.size(); i++) {
		if (p_steps[i].getPID()==PID) {
			p_steps[i].add(Z);
			break;
		}
	}

}

void ProcessRegistry::addLine(string line){
	history.push_back(line);
}

void ProcessRegistry::addPStep(Process* process) {
	for (vector<ProcessSteps>::size_type i=0; i<p_steps.size(); i++) {
		if (p_steps[i].getPID()==process->getPID()) {
			p_steps[i].add(process->getStateChar());
			break;
		}
	}
}

void ProcessRegistry::clear(){

	addHistoryItem();
	for (vector<ProcessSteps>::size_type i=0; i<p_steps.size(); i++) p_steps[i].~ProcessSteps(); 
	p_steps.clear();
}

void ProcessRegistry::addProcessPID(int PID){
	ProcessSteps ps(PID);
	p_steps.push_back(PID);
}

		
int ProcessSteps::getPID() {
	return(PID);
}

string ProcessSteps::getSteps() {
	return(steps);
}
		
void ProcessSteps::add(char s) {
	steps+=s;
}

ProcessSteps::ProcessSteps(int _PID): PID(_PID) {
	stringstream ss("");
	ss << "PID: " << _PID << " | ";
	steps=ss.str();
}

void ProcessSteps::clear() {
	steps="";
}