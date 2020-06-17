#include <iostream>
#include <stack>

using namespace std;

void menu();

int main()
{
	int key;
	char exitGeneralKey, exitMultiplePushKey;
	stack <int> myStack;

	while (true) {
		menu();

		cin >> key;

		if (key == 1) {
			cout << "\t-1-\tpush" << endl;

			int valueToPush;
			cout << "\tEnter number to push: ";
			cin >> valueToPush;
			myStack.push(valueToPush);
			cout << "\tSuccessful action" << endl;
		}
		else if (key == 2) {
			cout << "\t-2-\tmultiple push" << endl;

			while (true) {
				int valueToPush;
				cout << "\tEnter number to push: ";
				cin >> valueToPush;
				myStack.push(valueToPush);
				cout << "\tSuccessful action" << endl;

				cout << "Want to end? - press \"y\"" << endl;
				cin >> exitMultiplePushKey;
				if (tolower(exitMultiplePushKey) == 'y') {
					break;
				}
			}
		}
		else if (key == 3) {
			cout << "\t-3-\tpop" << endl;

			if (!myStack.empty()) {
				myStack.pop();
				cout << "\tSuccessful action" << endl;
			}
			else {
				cout << "\tERROR: stack is empty. Cannot pop any element" << endl;
			}
		}
		else if (key == 4) {
			cout << "\t-4-\tshow" << endl;

			if (!myStack.empty()) {
				stack <int> tempStack = myStack;
				while (!tempStack.empty()) {
					cout << " " << tempStack.top();
					tempStack.pop();
				}
				cout << endl;
				cout << "\tSuccessful action" << endl;
			}
			else {
				cout << "\tERROR: stack is empty. Cannot show elements" << endl;
			}
		}
		else if (key == 5) {
			cout << "\t-5-\tdelete all" << endl;

			if (!myStack.empty()) {
				while (!myStack.empty()) {
					myStack.pop();
				}
				cout << "\tSuccessful action" << endl;
			}
			else {
				cout << "\tERROR: stack is empty. Cannot delete elements" << endl;
			}
		}
		else if (key == 6) {
			cout << "\t-6-\tis empty" << endl;

			if (!myStack.empty()) {
				cout << "\tNot empty" << endl;
			}
			else {
				cout << "\tIs empty" << endl;
			}
		}
		else if (key == 7) {
			cout << "\t-7-\tsize" << endl;

			cout << "\tStack size: " << myStack.size() << endl;
		}
		else if (key == 8) {
			cout << "\t-8-\texit" << endl;
			cout << "\tAre you sure you want to exit? - press \"y\"" << endl;
			cin >> exitGeneralKey;
			if (tolower(exitGeneralKey) == 'y') {
				break;
			}
		}
		else {
			cout << "\t-?-\tother" << endl;
		}
	}
	cout << "Goodbye!" << endl;

	return 0;
}

void menu() {
	cout << "-----------------------------------" << endl;
	cout << "\t\tMENU - LIFO *stos|stack*" << endl;
	cout << "\t-1-\tpush" << endl;
	cout << "\t-2-\tmultiple push" << endl;
	cout << "\t-3-\tpop" << endl;
	cout << "\t-4-\tshow" << endl;
	cout << "\t-5-\tdelete all" << endl;
	cout << "\t-6-\tis empty" << endl;
	cout << "\t-7-\tsize" << endl;
	cout << "\t-8-\texit" << endl;
	cout << "-----------------------------------" << endl;
}