#include "Process.h"

Process::Process(){}
Process::~Process(){}

Process::Process(int _PID,int _stepCount, int _stepMaxTime):
PID(_PID), stepCount(_stepCount), stepMaxTime(_stepMaxTime) {
	reset();
}

void Process::setPID(int _pid) {
	PID=_pid;
}

int Process::getPID() {
	return(PID);
}

int Process::getStepCount() {
	return(stepCount);
}

int Process::getStepToFinish() {
	return(stepToFinish);
}
int Process::getStepTime() {
	return(stepTime);
}

void Process::setState(PState _state) {
	state=_state;
}

PState Process::getState() {
	return(state);
}

PState Process::doStep() {
	if (elementaryStep+1<stepTime) elementaryStep++; else {
		elementaryStep=0;
		stepTime=rand()%stepMaxTime+1;
		if (--stepToFinish!=0) {
			setState(SUSPENDED);
			return(SUSPENDED); 
		} else { 
			setState(FINISHED);
			return(FINISHED);
		}
	}
	return(ACTIVE);
}

bool Process::isActive() {
	if (getState()==ACTIVE) return(true);
	return(false);
}

bool Process::isSuspended() {
	if (getState()==SUSPENDED) return(true);
	return(false);
}

bool Process::isFinished() {
	if (getState()==FINISHED) return(true);
	return(false);
}

void Process::active() {
	setState(ACTIVE);
}

void Process::suspend() {
	setState(SUSPENDED);
}

void Process::finish() {
	setState(FINISHED);
}

char Process::getStateChar() {
	switch (state) {
	case ACTIVE: return('A');
	case SUSPENDED: return('S');
	case FINISHED: return('F');
	}
}

void Process::reset() {
	stepTime=rand()%stepMaxTime+1;
	state=SUSPENDED;
	stepToFinish=stepCount;
	elementaryStep=0;
}