#include <thread>
#include <vector>
#include "number.h"


using namespace std;



int main() {
	number*aa = new number(124);
	number a(345);
	thread potok1(&number::printRow,a);
	


	potok1.join();
	system("pause");
	return 0;
}
