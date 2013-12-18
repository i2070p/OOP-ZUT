#pragma once
#include "stdafx.h"
#include "Branch.h"
using namespace std;

class ChristmasTree {
public:
	ChristmasTree(void);
	ChristmasTree(int);
	~ChristmasTree(void);
	void setBranchType(Branch*);
	string toString();
private:
	int width;
	Branch* branch;
};

