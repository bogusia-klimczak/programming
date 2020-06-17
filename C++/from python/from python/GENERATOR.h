#pragma once
#include <vector>
#include <fstream>

using namespace std;

class GENERATOR
{
private:
	int __min_val;
	int __max_val;
	int __amount;
	vector<int> __numbers;

public:
	GENERATOR(int min_val, int max_val, int amount);
	int __generate();
	int show();
	int save(ofstream& outfile);
	int sort();
	int randint(int min, int max);
};