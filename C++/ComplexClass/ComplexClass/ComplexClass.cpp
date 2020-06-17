#include <iostream>
#include "classlib.h"
using namespace std;

int main()
{
	classlib vars[9] = {
		classlib(-1, -2),
		classlib(-1, 0),
		classlib(-1, 2),
		classlib(0, -2),
		classlib(0, 0),
		classlib(0, 2),
		classlib(1, -2),
		classlib(1, 0),
		classlib(1, 2)
	};
	for (int i = 0; i < 9; i++) {
		vars[i].__show__();
		vars[i].changeForm(1);
		vars[i].__show__();
		cout << endl;
	}
}