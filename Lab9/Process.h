#pragma once
#include "stdafx.h"
using namespace std;

enum PState {
	ACTIVE = 0,
	FINISHED   = 1,
	SUSPENDED  = 2
};

class Process {
	public:
		Process();
		Process(int, int, int);
		~Process();
		void setPID(int);
		int getPID();
		int getStepCount();
	    int getStepToFinish();
		int getStepTime();
		void setState(PState);
		void stepMove();
		PState getState();
		int stepStep;
	private:
		int PID, stepCount, stepToFinish, stepTime;
		PState state;
};
