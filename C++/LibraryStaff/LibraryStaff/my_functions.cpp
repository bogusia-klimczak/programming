#include <direct.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "my_functions.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;

bool is_dir(const char *dir)
{
	DWORD flag = GetFileAttributes(dir);
	if (flag == 0xFFFFFFFFUL)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
			return false;
	}
	if (!(flag & FILE_ATTRIBUTE_DIRECTORY))
		return false;
	return true;
}

void create_library(const char *_Path)
{
	if (_mkdir(_Path) == 0)
	{
		if (_chdir(_Path) == 0)
		{
			ofstream books("materials");
			books.close();
			ofstream staff("staff");
			staff.close();
		}
		else
		{
			switch (errno)
			{
			case ENOENT:
				cout << "Path was not found." << endl;
				break;
			case EINVAL:
				cout << "Invalid buffer." << endl;
				break;
			default:
				cout << "Unknown error." << endl;
				break;
			}
			exit(0);
			system("pause");
		}
	}
	else
	{
		switch (errno)
		{
		case EEXIST:
			cout << "Directory was not created because dirname is the name of an existing file, directory, or device." << endl;
			break;
		case ENOENT:
			cout << "Path was not found." << endl;
			break;
		default:
			cout << "Unknown error." << endl;
			break;
		}
		exit(0);
		system("pause");
	}
}

vector<string> explode(char delimiter, string const &string)
{
	vector<std::string> result;
	istringstream iss(string);

	for (std::string token; getline(iss, token, delimiter);)
	{
		result.push_back(move(token));
	}

	return result;
}

string implode(char glue, vector<string> pieces)
{
	string result = "";
	int i = 0;
	for (auto const &piece : pieces)
	{
		if (i == (pieces.size() - 1))
		{
			result += piece;
		}
		else
		{
			result += piece + glue;
		}
		i++;
	}
	return result;
}

string readFile(const string &fileName)
{
	long file_size;
	ifstream f(fileName);
	f.seekg(0, ios::end);
	file_size = f.tellg();
	if (file_size == -1 || file_size == 0)
	{
		return "";
	}
	string s(file_size, ' ');
	f.seekg(0);
	f.read(&s[0], file_size);
	return s;
}