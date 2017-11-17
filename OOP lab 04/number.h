#pragma once
#include <vector>
#include <thread>
class number {
public:
	number(int number_t);
	void setNumber(int number_t);
	std::string printRow();
	bool isNumberRow();

private:
	void factorization();
	void getMultipliers();
	int thisNumber;
	std::vector<int> multipliers;
	std::thread thr;
};