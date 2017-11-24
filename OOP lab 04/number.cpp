#include "number.h"
#include <fstream>
#include <iostream>
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
	//std::clog << "Death\n";
	std::unique_lock<std::mutex> lock1(mutexQueue);
	end = true;
	//cond_var.notify_all();
	lock1.unlock();
	//thr->join();
	for (auto &i : threads) {
		i.join();
	}
}

number::number(int number_t)
{
	for (int i = 0; i < number_t; i++) {
		threads.emplace_back([this]() {factorization(); });
	}
}

void number::setNumber(int number_t)
{
	//thisNumber=number_t;
	std::unique_lock<std::mutex> lock(mutexQueue);
	
	numbers.push(number_t);
	lock.unlock();
	cond_var.notify_one();
}

std::string number::printRow(std::vector<int>& multipliers)
{
	std::string result;
	result =  std::to_string(thisNumber) +" = " + std::to_string(multipliers[0]);
	for (size_t i = 1; i < multipliers.size();i++) {
		result = result + " * " +  std::to_string(multipliers[i]);
	}
	return result;
}

/*
bool number::isNumberRow()
{
	int result = 1;
	for (auto i : multipliers) {
		result *= i;
	}
	return (result == thisNumber) ? true : false;
}
*/
void number::factorization()
{
	std::thread *thr = new std::thread(&number::getMultipliers,this);	
}

void number::getMultipliers()
{
	std::clog << "1\n";
	int curNumber;
	file.open("D:\\out.txt", std::ios::app);
	while (true) {
		std::unique_lock<std::mutex> lock1(mutexQueue);
		std::cout << ">> 1 " << std::endl;
		cond_var.wait(lock1, [this] {return (!numbers.empty() || end || exit); });
		if (numbers.empty() && (end  || exit)) {
			file.close();
			break;
		}

		if (pause) {
			cond_var.wait(lock1, [this] { return !pause; });
		}

		curNumber = numbers.front();
		numbers.pop();
		thisNumber = curNumber;

		
		lock1.unlock();
		std::cout << ">> 2 " << std::endl;
		int divider = 2;

		// algo
		std::vector<int> multipliers;
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
		std::cout << ">> 3 " << std::endl;

		std::unique_lock<std::mutex> lock(mutexDividers);

		if (exit) {
			file.close();
			break;
		}

		std::cout << ">> 4 " << std::endl;

		std::string result;
		result = std::to_string(thisNumber) + " = " + std::to_string(multipliers[0]);
		for (size_t i = 1; i < multipliers.size(); i++) {
			result = result + " * " + std::to_string(multipliers[i]);
		}
		std::cout << ">> 5 " << std::endl;
		file << result << std::endl;
		std::cout << ">> 6 " << std::endl;
		//file << printRow(multipliers) << std::endl;
		lock.unlock();
	}
}

