#include <thread>
#include <vector>
#include "number.h"
#include <iostream>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;



int main() {
	number	lol(1);
	fstream file("D:\\in.txt");
	string a;
//	int b;
	while (file >> a) {
		if (a == "exit")
			lol.setExitSignal();
		else
			if (a == "pause")
				lol.setPauseSignal(1);
			else
				if (a == "resume")
					lol.setPauseSignal(0);
				else {
					int b = stoi(a);
					lol.setNumber(b);
				}
	}
	//lol.~number();
	//system("pause");
	return 0;
}
