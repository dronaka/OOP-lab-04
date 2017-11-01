#pragma once
#include <vector>
class number {
public:
	number(int number_t);
	std::string printRow();
	bool isNumberRow();
private:
	void getMultipliers();
	int thisNumber;

	std::vector<int> multipliers;
};