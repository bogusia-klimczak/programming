#include <iostream>
#include <math.h>
#include <string>
#include "MY_ERROR.h"

using namespace std;

double div(double a, double b);

int main()
{
	double a, b, result;
	char symbol, key;
	bool isError = false;

	while (true) {
		cout << "Type number, symbol and number:" << endl;
		cout << "a: ";
		cin >> a;
		cout << "symb: ";
		cin >> symbol;
		cout << "b: ";
		cin >> b;
		cout << "Your operation looks like: " << a << " " << symbol << " " << b << endl << endl;

		cout << "Calculating......" << endl << endl;

		if (symbol == '+') {
			result = a + b;
		}
		else if (symbol == '-') {
			result = a - b;
		}
		else if (symbol == '*') {
			result = a * b;
		}
		else if (symbol == '/') {
			try {
				result = div(a, b);
			}
			catch (MY_ERROR& err)
			{
				cout << err.what() << endl << endl;
				isError = true;
			}
		}
		else if (symbol == '^') {
			result = pow(a, b);
		}
		if (isError) {
			cout << "Result: " << a << " " << symbol << " " << b << " = |ERROR|" << endl << endl;
		}
		else {
			cout << "Result: " << a << " " << symbol << " " << b << " = " << result << endl << endl;
		}

		cout << "If you want to end, press \"Y\": ";
		cin >> key;
		cout << endl << "------------------" << endl << endl;
		if (tolower(key) == 'y') {
			break;
		}

		isError = false;
	}

	cout << "End of program";
}

double div(double a, double b) {
	if (b == 0) {
		throw MY_ERROR();
	}
	else {
		return a / b;
	}
}