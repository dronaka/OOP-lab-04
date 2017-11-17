#include <thread>
#include <vector>
#include "number.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
	number a(2147483646);
	cout << a.printRow();

	system("pause");
	return 0;
}
