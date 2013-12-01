#pragma once
#include <sstream>
#include "stdafx.h"

using namespace std;
class ProcessRegistry {
public:
        ProcessRegistry();
        ~ProcessRegistry();
		string toString();
		void addHistoryItem(string);
private:
		vector <string> history;
};