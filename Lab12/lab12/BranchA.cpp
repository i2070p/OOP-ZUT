#include "StdAfx.h"
#include "BranchA.h"


BranchA::BranchA(void) {}


BranchA::~BranchA(void) {}

string draw(int width) {
	string s="";
	for(int i=0; i<width;i++) s+="*";
	return(s);
}