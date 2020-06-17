#pragma once

#include <string>
#include <vector>
#include "MATERIAL.h"

using std::string;
using std::vector;

class CD : public MATERIAL
{
private:
	string _m_summary;
	vector<string> _m_genres;

public:
	CD(string title, vector<string> authors, string summary, vector<string> genres, string language);
	virtual ~CD(){};
	virtual void __show() const;
};