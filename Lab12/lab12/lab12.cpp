// lab12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ChristmasTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	ChristmasTree ch(5);
	Branch branch("*");
	ch.setBranchType(&branch);
	std::cout << ch.toString();

	Branch branch1("+");
	ch.setBranchType(&branch1);
	std::cout << ch.toString();
	
	Branch branch2("$");
	ch.setBranchType(&branch2);
	std::cout << ch.toString();

	
	getchar();
	return 0;
}

