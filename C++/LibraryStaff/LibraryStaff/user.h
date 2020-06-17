#pragma once

#include <string>
#include "BOOK.h"
#include "CD.h"
#include "NEWSPAPER.h"

using std::string;

class user
{
private:
	string _m_firstName, _m_lastName;

public:
	user(string fisrtName, string lastName);
	virtual ~user(){};

	virtual string names();

	BOOK borrowBook(int id);
	void showBook(int id);
	void showBooks();

	CD borrowCD(int id);
	void showCD(int id);
	void showCDS();

	void showNewspaper(int id);
	void showNewspapers();
};