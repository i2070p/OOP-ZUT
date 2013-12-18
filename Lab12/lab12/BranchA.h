#pragma once
#include "branch.h"

class BranchA :
	public Branch
{
public:
	BranchA(void);
	~BranchA(void);
	string draw(int);
};

