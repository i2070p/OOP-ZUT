// stdafx.cpp : source file that includes just the standard includes
// lab92.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
std::string getTime() {
	time_t now = time(0);
	tm tstruct;
	char buf[10];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	std::stringstream ss;
	ss << buf;
	return(ss.str());
}

