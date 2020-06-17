#include <iostream>

#include "GENERATOR.h"

void bubble_sort(vector<int>& arr)
{
	int max_element = arr.size() - 1, index, temp;

	while (max_element >= 0)
	{
		index = 0;
		while (index <= max_element - 1)
		{
			if (arr[index] > arr[index + 1])
			{
				temp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = temp;
			}
			index += 1;
		}
		max_element = max_element - 1;
	}
}

GENERATOR::GENERATOR(int min_val, int max_val, int amount)
{
	__min_val = min_val;
	__max_val = max_val;
	__amount = amount;
	__numbers.clear();
	__generate();
}

int GENERATOR::__generate()
{
	int number;

	for (int i = 0; i < __amount; i++)
	{
		number = randint(__min_val, __max_val);
		__numbers.push_back(number);
	}

	return 0;
}

int GENERATOR::show()
{
	for (size_t i = 0; i < __numbers.size(); i++)
	{
		cout << __numbers[i] << " ";
	}
	cout << "" << endl;
	return 0;
}

int GENERATOR::save(ofstream& outfile)
{
	// outfile.open("numbers_from_Python", 'w');

	for (size_t i = 0; i < __numbers.size(); i++)
	{
		outfile << __numbers[i] << " ";
	}

	outfile << endl;
	return 0;
}

int GENERATOR::sort()
{
	bubble_sort(__numbers);
	return 0;
}

int GENERATOR::randint(int min, int max) {
	return rand() % (max - min + 1) + min;
}