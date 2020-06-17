#include <iostream>
#include <string>
#include "NEWSPAPER.h"

using std::cout;
using std::endl;
using std::string;

NEWSPAPER::NEWSPAPER(string title, vector<string> authors, string language) : MATERIAL(title, authors, language) {}

void NEWSPAPER::__show() const
{
	cout << "NEWSPAPER INFORMATION" << endl;
	cout << "ID: " << endl;
	cout << "TITLE: " << getTitle() << endl;
	cout << "AUTHORS: ";
	vector<string> authors = getAuthors();
	for (int i = 0; i < authors.size(); i++)
	{
		if (i == (authors.size() - 1))
		{
			cout << authors[i];
		}
		else
		{
			cout << authors[i] << ", ";
		}
	}
	cout << endl;
	cout << endl;
	cout << "LANGUAGE: " << getLanguage() << endl;
}