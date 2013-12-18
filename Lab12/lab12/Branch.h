#pragma once
#include "stdafx.h"

using namespace std;
class Branch
{
public:
	Branch();
	Branch(string);
	~Branch();
	string getBranch(int);
protected:
	string sort;
};

