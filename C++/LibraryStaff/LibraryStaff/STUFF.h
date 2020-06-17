#pragma once

#include <string>
#include "user.h"

using std::string;

class STUFF : public user
{
private:
	int _m_id;
	string _m_firstName, _m_lastName, _m_passwd;
	string Err;
	bool is_Err;

public:
	STUFF(int id, string passwd);
	virtual ~STUFF(){};

	virtual string names();

	bool isErr();
	string getErr();

	BOOK addBOOK(string name, vector<string> authors, string summary, string imprint, string ISBN, vector<string> genres, string language);
	BOOK changeBOOK(int id);
	bool removeBOOK(int id);

	CD addCD(string name, vector<string> authors, string summary, vector<string> genres, string language);
	CD changeCD(int id);
	bool removeCD(int id);

	NEWSPAPER addNEWSPAPER(string name, vector<string> authors, string language);
	NEWSPAPER changeNEWSPAPER(int id);
	bool removeNEWSPAPER(int id);
};