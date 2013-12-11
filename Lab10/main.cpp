

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "ProcessList.h"
#include "ProcessRegistry.h"
#include <time.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	srand(time(0));
	ProcessList pl;

	ProcessRegistry pr;
	FIFO strategy;


	pl.connectStrategy(&strategy);
	pl.connectProcessRegistry(&pr);
	pl.addProcess(3,5);
	pl.addProcess(2,6);
	pl.addProcess(3,3);
	pl.addProcess(12,1);

	pl.addProcess(6,2);
	pl.addProcess(1,9);
	pl.addProcess(2,5);
	pl.addProcess(3,2);
	pl.addProcess(1,1);

	pl.Run();

	pl.Run();

	pl.addProcess(4,3);
	pl.Run();

	cout << pr.toString();
	getchar();
	return 0;
}

