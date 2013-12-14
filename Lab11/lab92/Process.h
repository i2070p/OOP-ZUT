#pragma once
#include "stdafx.h"

enum PState {
        ACTIVE = 0,
        FINISHED = 1,
        SUSPENDED = 2
};

class Process {
        public:
                Process();
                Process(int, int, int);
                ~Process();
                int getPID();
                int getStepCount();
				int getStepToFinish();
                int getStepTime();
				bool isActive();
				bool isFinished();
				bool isSuspended();
				void setPID(int);
				void active();
				void suspend();
				void finish();
				void reset();
                PState doStep();
				char getStateChar();
        private:
			    PState getState();
			    void setState(PState);
                int PID, stepCount, elementaryStep, stepToFinish, stepTime, stepMaxTime;
				PState state;
};