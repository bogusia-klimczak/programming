#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	cout << "Guess the number from 0 to 100" << endl;
	int liczba = (rand() % 101);
	int n;
	while (1) {
		cin >> n;
		if (n == liczba) {
			cout << "You won!" << endl;;
			break;
		}
		else if (n < liczba) {
			cout << "More" << endl;;
		}
		else {
			cout << "Less" << endl;;
		}
	}
}