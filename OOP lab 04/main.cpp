#include <thread>
#include <vector>
#include "number.h"
#include <iostream>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;



int main() {
	mutex lock;
	number	lol;
	fstream file("D:\\in.txt");
	int a;
	while (file >> a) {

		lol.setNumber(a);
		
	}
	lol.~number();
	system("pause");
	return 0;
}
