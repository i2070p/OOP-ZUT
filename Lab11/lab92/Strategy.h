#pragma once
#include "stdafx.h"
#include "ProcessRegistry.h"
#include "Process.h"

class Strategy {
        public:
                Strategy(){};
                ~Strategy(){};
                virtual void run(std::vector <Process*> processList, ProcessRegistry*) = 0;
};
