#include <iostream>
#include <string>
#include <vector>

using namespace std;

void funct();

void funct() {
	string formula;
	double x;

	cout << "f(x) = ";
	getline(cin, formula);
	cout << "x = ";
	cin >> x;
	cout << "wzor funkcji: f(x) = " << formula << endl;
	cout << "podany x: x = " << x << endl;

	vector <char> chars;
	chars.clear();
	for (int i = 0; i < formula.size(); i++)
	{
		if (formula[i] == ' ') {
			continue;
		}
		else {
			chars.push_back(formula[i]);
		}
	}

	char m;
	string my_str = "";
	for (int i = 0; i < chars.size(); i++) {
		m = chars[i];
		if (m == 'x') {
			my_str += to_string(x) + " ";
		}
		else if (isalpha(m)) {
			my_str += m;
			try {
				if (chars[i + 1] == ',') {
					my_str += '.';
				}
			}
			catch (...) {
				// nothing
			}
			try {
				if (!isalpha(chars[i + 1])) {
					my_str += " ";
				}
			}
			catch (...) {
				// nothing
			}
		}
		else if (m == '+') {
			my_str += '+';
		}
		else if (m == '-') {
			my_str += '-';
		}
		else if (m == '*') {
			my_str += '*';
		}
		else if (m == '/') {
			my_str += '/';
		}
	}

	cout << "obliczanie:" << endl << my_str << endl;
}

int main()
{
	funct();
}