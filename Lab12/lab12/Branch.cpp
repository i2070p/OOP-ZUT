#include "Branch.h"
#include "StdAfx.h"

Branch::Branch(){}

Branch::~Branch(){}

Branch::Branch(string _sort): sort(_sort) {

}

string Branch::getBranch(int width) {
	string s="";
	for (int i=0; i<width; i++) s+=sort;
	return(s);	
}