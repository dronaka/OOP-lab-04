#include "number.h"
#include <iostream>
#include <string>
number::number(int number_t) : thisNumber(number_t)
{
	getMultipliers();
}

std::string number::printRow()
{
	std::string result;
	result =  std::to_string(thisNumber) +" = " + std::to_string(multipliers[0]);
	for (size_t i = 1; i < multipliers.size();i++) {
		result =  " * " +  std::to_string(multipliers[i]);
	}
	std::cout << std::endl;
}

bool number::isNumberRow()
{
	int result = 1;
	for (auto i : multipliers) {
		result *= i;
	}
	return (result == thisNumber) ? true : false;
}

void number::getMultipliers()
{
	int divider = 2;
	int curNumber = thisNumber;
	while (divider <= sqrt(curNumber)) {
		if (curNumber % divider == 0) {
			multipliers.push_back(divider);
			curNumber /= divider;
		}
		else divider++;
	}
	if (curNumber != 1) {
		multipliers.push_back(curNumber);
	}
	

	/*
	int divider = 2;
	int curNumber = thisNumber;
	while (curNumber > 1)	{
		if (curNumber % divider == 0) {
			multipliers.push_back(divider);
			curNumber /= divider;
		}
		//else divider++;
	}
	*/
}
//task
