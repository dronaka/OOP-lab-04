#include "number.h"
#include <fstream>
#include <string>


void function1() {
	std::ifstream input;
	std::ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int tmp;
	while (input) {
		input >> tmp;
		number* ptr = new number(tmp);
		output << ptr->printRow() << std::endl;
	}
}