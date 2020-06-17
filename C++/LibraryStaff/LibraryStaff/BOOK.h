#pragma once

#include <string>
#include <vector>
#include "MATERIAL.h"

using std::string;
using std::vector;

class BOOK : public MATERIAL
{
private:
	string _m_summary, _m_imprint, _m_ISBN;
	vector<string> _m_genres;

public:
	BOOK(string title, vector<string> author, string summary, string imprint, string ISBN, vector<string> genres, string language);
	virtual ~BOOK(){};
	virtual void __show() const;
};