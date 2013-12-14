#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "ProcessList.h"
#include "ProcessRegistry.h"
#include <time.h>
#include "FIFO.h"
#include "SJF.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
        srand(time(0));
        ProcessList pl;

        ProcessRegistry pr;
        SJF sjf;
		FIFO fifo;
        pl.connectProcessRegistry(&pr);
        pl.addProcess(3,5);
        pl.addProcess(2,6);
        pl.addProcess(3,3);
        pl.addProcess(5,1);
        pl.addProcess(6,2);
        pl.addProcess(1,9);
        pl.addProcess(4,5);
        pl.addProcess(3,2);
		
		pl.connectStrategy(&fifo);
        pl.Run();
		pl.connectStrategy(&sjf);
		pl.Run();

        cout << pr.toString();
        getchar();
        return 0;
}