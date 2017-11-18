#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <fstream>

class number {
public:
	number();
	~number();
	number(int number_t);
	void setNumber(int number_t);
	std::string printRow();
	bool isNumberRow();

private:
	std::mutex mutexDividers,mutexQueue;
	void factorization();
	void getMultipliers();
	int thisNumber;
	std::vector<int> multipliers;
	std::thread *thr;
	std::queue<int> numbers;
	std::fstream file;
	bool end=false;
	std::condition_variable cond_var;
};