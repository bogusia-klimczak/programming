#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class MATERIAL
{
private:
	int _m_id;
	string _m_title, _m_language;
	vector<string> _m_authors;

protected:
	int getId() const;
	string getTitle() const;
	vector<string> getAuthors() const;
	string getLanguage() const;

public:
	MATERIAL(string title, vector<string> authors, string language);
	virtual ~MATERIAL(){};
	virtual void __show() const = 0;
};