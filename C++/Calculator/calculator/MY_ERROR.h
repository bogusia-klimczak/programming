#pragma once

#include <exception>

using namespace std;

class MY_ERROR : public std::exception
{
public:
	MY_ERROR() {};
	const char* what() { return "ERROR: Division by zero"; }
};