#include <iostream>
#include <string>
#include <vector>
#include "MATERIAL.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

MATERIAL::MATERIAL(string title, vector<string> authors, string language)
{
	_m_title = title;
	_m_authors = authors;
	_m_language = language;
}

int MATERIAL::getId() const
{
	return _m_id;
}

string MATERIAL::getTitle() const
{
	return _m_title;
}

vector<string> MATERIAL::getAuthors() const
{
	return _m_authors;
}

string MATERIAL::getLanguage() const
{
	return _m_language;
}