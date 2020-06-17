#include <iostream>
#include <string>
#include <vector>
#include "my_functions.h"
#include "user.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

user::user(string firstName, string lastName)
{
	_m_firstName = firstName;
	_m_lastName = lastName;
}

string user::names()
{
	return "--GUEST-- " + _m_firstName + " " + _m_lastName;
}

BOOK user::borrowBook(int id)
{
	return BOOK("Harry Potter #1 - Harry Potter and The Philosopher Stone", vector<string>{}, "Cool book", "RANOK", "1234567891234", vector<string>{}, "english");
}

void user::showBook(int id)
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<string> neededBook;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		std::string::size_type sz;
		if (dataMaterialList[1] == "book")
		{
			int this_id = stoi(dataMaterialList[0], &sz);
			if (this_id == id)
			{
				neededBook = dataMaterialList;
			}
		}
	}

	cout << "----------------------------------------------------------------------" << endl;
	cout << "Title : " << '\xab' << neededBook[2] << '\xab' << endl;
	cout << "Authors : " << neededBook[3] << endl;
	cout << "Summary : " << neededBook[4] << endl;
	cout << "Imprint : " << neededBook[5] << endl;
	cout << "ISBN : " << neededBook[6] << endl;
	cout << "Genres : " << neededBook[7] << endl;
	cout << "Language : " << neededBook[8] << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void user::showBooks()
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<vector<string>> books;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		if (dataMaterialList[1] == "book")
		{
			books.resize(books.size() + 1);
			books[j] = dataMaterialList;
			j++;
		}
	}

	for (size_t i = 0; i < books.size(); i++)
	{
		cout << "----------------------------------------------------------------------" << endl;
		cout << "ID : " << books[i][0] << endl;
		cout << "Title : " << books[i][2] << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}
}

CD user::borrowCD(int id)
{
	return CD("Seven Nation Army", vector<string>{}, "The best song ever", vector<string>{}, "english");
}

void user::showCD(int id)
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<string> neededCD;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		std::string::size_type sz;
		if (dataMaterialList[1] == "cd")
		{
			int this_id = stoi(dataMaterialList[0], &sz);
			if (this_id == id)
			{
				neededCD = dataMaterialList;
			}
		}
	}

	cout << "----------------------------------------------------------------------" << endl;
	cout << "Title : " << '\xab' << neededCD[2] << '\xab' << endl;
	cout << "Authors : " << neededCD[3] << endl;
	cout << "Summary : " << neededCD[4] << endl;
	cout << "Genres : " << neededCD[5] << endl;
	cout << "Language : " << neededCD[6] << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void user::showCDS()
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<vector<string>> cds;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		if (dataMaterialList[1] == "cd")
		{
			cds.resize(cds.size() + 1);
			cds[j] = dataMaterialList;
			j++;
		}
	}

	for (size_t i = 0; i < cds.size(); i++)
	{
		cout << "----------------------------------------------------------------------" << endl;
		cout << "ID : " << cds[i][0] << endl;
		cout << "Title : " << cds[i][2] << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}
}

void user::showNewspaper(int id)
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<string> neededNespapers;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		std::string::size_type sz;
		if (dataMaterialList[1] == "newspaper")
		{
			int this_id = stoi(dataMaterialList[0], &sz);
			if (this_id == id)
			{
				neededNespapers = dataMaterialList;
			}
		}
	}

	cout << "----------------------------------------------------------------------" << endl;
	cout << "Title : " << '\xab' << neededNespapers[2] << '\xab' << endl;
	cout << "Authors : " << neededNespapers[3] << endl;
	cout << "Language : " << neededNespapers[4] << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void user::showNewspapers()
{
	string dataMaterialsString = readFile("data_library/materials");
	vector<string> dataMaterialsList = explode(';', dataMaterialsString);

	vector<vector<string>> newspapers;

	for (size_t i = 0, j = 0; i < dataMaterialsList.size(); i++)
	{
		string dataMaterialString = dataMaterialsList[i];
		vector<string> dataMaterialList = explode(':', dataMaterialString);

		if (dataMaterialList[1] == "newspaper")
		{
			newspapers.resize(newspapers.size() + 1);
			newspapers[j] = dataMaterialList;
			j++;
		}
	}

	for (size_t i = 0; i < newspapers.size(); i++)
	{
		cout << "----------------------------------------------------------------------" << endl;
		cout << "ID : " << newspapers[i][0] << endl;
		cout << "Title : " << newspapers[i][2] << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}
}