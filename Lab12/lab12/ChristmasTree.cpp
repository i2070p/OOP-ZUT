#include "StdAfx.h"
#include "ChristmasTree.h"


ChristmasTree::ChristmasTree(void) {

}

ChristmasTree::ChristmasTree(int _width): width(2*_width) {

}

string ChristmasTree::toString() {
	stringstream ss;
	
	ss << endl;
	for (int i=1; i<width; i++) {
		for (int j=0; j<width-i; j++) ss << " ";
		ss << branch->getBranch(i*2) << endl;
	}
	for (int j=0; j<width-1; j++) ss << " ";
	ss << "||" << endl;
	return(ss.str());
}

ChristmasTree::~ChristmasTree(void) {

}

void ChristmasTree::setBranchType(Branch* _branch) {
	branch=_branch;
}