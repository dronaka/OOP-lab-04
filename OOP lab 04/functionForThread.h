#pragma once
#include <thread>
#include "number.h"

class myThread {
public:
	void workTask();

private:
	std::thread thr;
	number obj;
};