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
	void openFile();
	number(int number_t);
	void setNumber(int number_t);
	std::string printRow(std::vector<int>& multipliers);
	//bool isNumberRow();
	void setExitSignal() { exit = true; };
	void setPauseSignal(bool signal) { pause = signal; };

private:
	std::vector<std::thread> threads;
	std::mutex mutexDividers,mutexQueue;
	//void factorization();
	// getMultipliers();
	//int thisNumber;
	//std::vector<int> multipliers;
	//std::thread *thr;
	std::queue<int> numbers;
	std::fstream file;
	bool end=false;
	bool exit = false;
	bool pause = false;
	std::condition_variable cond_var;
};