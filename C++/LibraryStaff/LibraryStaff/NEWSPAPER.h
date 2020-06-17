#pragma once

#include <string>
#include <vector>
#include "MATERIAL.h"

using std::string;
using std::vector;

class NEWSPAPER : public MATERIAL
{
public:
	NEWSPAPER(string title, vector<string> authors, string language);
	~NEWSPAPER(){};
	virtual void __show() const;
};