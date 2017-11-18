#include "number.h"
#include <fstream>
#include <string>
#include <thread>
#include <queue>
#include <mutex>

number::number()
{
	factorization();
}

number::~number()
{
	std::mutex endLock;
	endLock.lock();
	end = true;
	endLock.unlock();
	thr->join();
}

number::number(int number_t) : thisNumber(number_t)
{
	factorization();
}

void number::setNumber(int number_t)
{
	//thisNumber=number_t;
	std::unique_lock<std::mutex> lock(mutexQueue);
	
	numbers.push(number_t);
	lock.unlock();
	cond_var.notify_one();
}

std::string number::printRow()
{
	std::string result;
	result =  std::to_string(thisNumber) +" = " + std::to_string(multipliers[0]);
	for (size_t i = 1; i < multipliers.size();i++) {
		result = result + " * " +  std::to_string(multipliers[i]);
	}
	return result;
}

bool number::isNumberRow()
{
	int result = 1;
	for (auto i : multipliers) {
		result *= i;
	}
	return (result == thisNumber) ? true : false;
}

void number::factorization()
{
	thr = new std::thread(&number::getMultipliers,this);	
}

void number::getMultipliers()
{
	int curNumber;
	while (!end || !numbers.empty()) {
		std::unique_lock<std::mutex> lock1(mutexQueue);
		cond_var.wait(lock1, [this] {return !numbers.empty(); });
		int divider = 2;

		curNumber = numbers.front();
		numbers.pop();
		thisNumber = curNumber;
	
			lock1.unlock();
		std::unique_lock<std::mutex> lock(mutexDividers);


		// algo
		multipliers.clear();
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
		//

		//mutexDividers.unlock();

		lock.unlock();
		file.open("D:\\out.txt", std::ios::app);
		file << printRow() << std::endl;
		file.close();
	}
}

