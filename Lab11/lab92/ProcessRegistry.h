#pragma once
#include <sstream>
#include "stdafx.h"

using namespace std;
class ProcessSteps { 
	public:
		ProcessSteps(int _PID);
		~ProcessSteps(){};
		int getPID();
		string getSteps();
		void add(char);
		void clear();
	private:
		int PID;
		string steps;
};

class ProcessRegistry {
public:
        ProcessRegistry();

        ~ProcessRegistry();
		string toString();
		void addPStep(int, char);
		void addPStep(Process*);
		void addHistoryItem();
		void addProcessPID(int);
		void addLine(string);
		void clear();
private:
		vector <string> history;
		vector <ProcessSteps> p_steps;
};