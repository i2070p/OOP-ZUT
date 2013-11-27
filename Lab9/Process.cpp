#include "Process.h"

Process::Process(){}
Process::~Process(){}

Process::Process(int _PID,int _stepCount, int _stepTime):
PID(_PID), stepCount(_stepCount), stepTime(_stepTime) 
{
	state=SUSPENDED;
	stepToFinish=0;
	stepStep=0;
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

void Process::stepMove() {
	if (stepStep<stepCount) stepStep++; else {
		stepStep=0;
		setState(SUSPENDED);
	}
}
