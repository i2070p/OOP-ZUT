#include "ProcessRegistry.h"


ProcessRegistry::ProcessRegistry() {
	
}

ProcessRegistry::~ProcessRegistry(){}

string ProcessRegistry::toString() {
	stringstream ss;
	for (vector<string*>::size_type i=0; i<history.size(); i++) {
		ss << "____________" << /*getTime()*/ i << "____________\n";
		ss << history[i];
		ss << endl;
	}
	return(ss.str());
}


void ProcessRegistry::addHistoryItem(string _item) {
	history.push_back(_item);
}