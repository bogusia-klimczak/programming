#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>

#include "my_functions.h"
#include "STUFF.h"

using namespace std;

STUFF::STUFF(int id, string passwd) : user("", "")
{
	is_Err = false;

	string dataStuffMembersString = readFile("data_library/staff");

	vector<string> dataStuffMembersList = explode(';', dataStuffMembersString);

	if (dataStuffMembersList.size() == 0)
	{
		is_Err = true;
		Err = "There are not any staff-member!";
		return;
	}

	for (auto const &dataStuffMemberString : dataStuffMembersList)
	{
		vector<string> dataStuffMemberList = explode(':', dataStuffMemberString);

		std::string::size_type sz;
		if (stoi(dataStuffMemberList[0], &sz) == id)
		{
			if (dataStuffMemberList[1] == passwd)
			{
				_m_id = id;
				_m_passwd = passwd;
				_m_firstName = dataStuffMemberList[2];
				_m_lastName = dataStuffMemberList[3];
				return;
			}
			else
			{
				is_Err = true;
				Err = "Bad password!";
				return;
			}
		}
	}
	is_Err = true;
	Err = "This id do not exist";
	return;
}

string STUFF::names()
{
	return "	--STUFF-- " + _m_firstName + " " + _m_lastName;
}

bool STUFF::isErr()
{
	if (is_Err)
	{
		return true;
	}
	return false;
}

string STUFF::getErr()
{
	return Err;
}

BOOK STUFF::addBOOK(string name, vector<string> authors, string summary, string imprint, string ISBN, vector<string> genres, string language)
{
	string gottenDataMaterialsString = readFile("data_library/materials");

	vector<string> gottenDataMaterialsList = explode(';', gottenDataMaterialsString);

	int max_id = 0;

	for (auto const &gottenDataMaterialString : gottenDataMaterialsList)
	{
		vector<string> gottenDataMaterialList = explode(':', gottenDataMaterialString);
		std::string::size_type sz;
		int i = stoi(gottenDataMaterialList[0], &sz);
		if (i > max_id)
		{
			max_id = i;
		}
	}

	max_id += 1;

	string StringAuthors = authors[0];
	for (size_t i = 1; i < authors.size(); i++)
	{
		StringAuthors = StringAuthors + "|" + authors[i];
	}

	string StringGenres = genres[0];
	for (size_t i = 1; i < genres.size(); i++)
	{
		StringGenres = StringGenres + "|" + genres[i];
	}

	gottenDataMaterialsList.resize(gottenDataMaterialsList.size() + 1);
	gottenDataMaterialsList[gottenDataMaterialsList.size() - 1] = to_string(max_id) + ":book:" + name + ":" + StringAuthors + ":" + summary + ":" + imprint + ":" + ISBN + ":" + StringGenres + ":" + language;
	string result = implode(';', gottenDataMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << result;
	file.close();

	return BOOK(name, authors, summary, imprint, ISBN, genres, language);
}

BOOK STUFF::changeBOOK(int id)
{
	string gottenMaterialsString = readFile("data_library/materials");
	vector<string> gottenMaterialsList = explode(';', gottenMaterialsString);

	vector<string> neededBook;

	for (auto const &gottenMaterialString : gottenMaterialsList)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialString);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			neededBook = gottenMaterialList;
			break;
		}
	}
	cout << "Leave empty to do not change" << endl;
	cout << "Change to ->" << endl;

	vector<string> authors = {""}, genres = {""};
	string title, summary, imprint, ISBN, language;

	cin.ignore();

	cout << "	Title: ";
	getline(cin, title);

	cin.ignore();

	cout << "	Author: ";
	getline(cin, authors[0]);

	cin.ignore();

	while (true)
	{
		cout << "	Do you want to add more authors? Press \"Y\"/\"y\" to add and \"N\"/\"n\" to not" << endl;

		string addAuthorKey;
		getline(cin, addAuthorKey);

		cin.ignore();

		if (addAuthorKey == "Y" || addAuthorKey == "y")
		{
			cout << "	Next author: ";
			authors.resize(authors.size() + 1);
			getline(cin, authors[authors.size() - 1]);

			cin.ignore();
		}
		else if (addAuthorKey == "N" || addAuthorKey == "n")
		{
			cout << "	Adding more authors canceled" << endl;
			break;
		}
		else
		{
			cout << "	Wrong option" << endl;
		}
	}

	cout << "	Summary: ";
	getline(cin, summary);

	cin.ignore();

	cout << "	Imprint: ";
	getline(cin, imprint);

	cin.ignore();

	cout << "	ISBN: ";
	getline(cin, ISBN);

	cin.ignore();

	cout << "	Genre: ";
	getline(cin, genres[0]);

	cin.ignore();

	while (true)
	{
		cout << "	Do you want to add more genres? Press \"Y\"/\"y\" to add and \"N\"/\"n\" to not" << endl;

		string addGenreKey;
		getline(cin, addGenreKey);

		cin.ignore();

		if (addGenreKey == "Y" || addGenreKey == "y")
		{
			cout << "	Next genre: ";
			genres.resize(genres.size() + 1);
			getline(cin, genres[genres.size() - 1]);

			cin.ignore();
		}
		else if (addGenreKey == "N" || addGenreKey == "n")
		{
			cout << "	Adding more authors canceled" << endl;
			break;
		}
		else
		{
			cout << "	Wrong option" << endl;
		}
	}

	cout << "	Language: ";
	getline(cin, language);

	cin.ignore();

	vector<string> result = neededBook;

	if (title != "")
	{
		result[2] = title;
	}
	string stringAuthors = implode('|', authors);
	if (stringAuthors != "")
	{
		result[3] = stringAuthors;
	}
	if (summary != "")
	{
		result[4] = summary;
	}
	if (imprint != "")
	{
		result[5] = imprint;
	}
	if (ISBN != "")
	{
		result[6] = ISBN;
	}
	string stringGenres = implode('|', genres);
	if (stringGenres != "")
	{
		result[7] = stringGenres;
	}
	if (language != "")
	{
		result[8] = language;
	}

	for (size_t i = 0; i < gottenMaterialsList.size(); i++)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialsList[i]);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			gottenMaterialsList[i] = implode(':', result);
			break;
		}
	}

	string resultDataString = implode(';', gottenMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return BOOK(title, authors, summary, imprint, ISBN, genres, language);
}

bool STUFF::removeBOOK(int id)
{
	string gottenDataString = readFile("data_library/materials");

	vector<string> gottenDataVector = explode(';', gottenDataString);

	std::string::size_type sz;

	for (size_t i = 0; i < gottenDataVector.size(); i++)
	{
		vector<string> book = explode(':', gottenDataVector[i]);
		if (stoi(book[0], &sz) == id)
		{
			gottenDataVector.erase(gottenDataVector.begin() + i);
			break;
		}
	}

	string resultDataString = implode(';', gottenDataVector);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return true;
}

CD STUFF::addCD(string name, vector<string> authors, string summary, vector<string> genres, string language)
{
	string gottenDataMaterialsString = readFile("data_library/materials");

	vector<string> gottenDataMaterialsList = explode(';', gottenDataMaterialsString);

	int max_id = 0;

	for (auto const &gottenDataMaterialString : gottenDataMaterialsList)
	{
		vector<string> gottenDataMaterialList = explode(':', gottenDataMaterialString);
		std::string::size_type sz;
		int i = stoi(gottenDataMaterialList[0], &sz);
		if (i > max_id)
		{
			max_id = i;
		}
	}

	max_id += 1;

	string StringAuthors = authors[0];
	for (size_t i = 1; i < authors.size(); i++)
	{
		StringAuthors = StringAuthors + "|" + authors[i];
	}

	string StringGenres = genres[0];
	for (size_t i = 1; i < genres.size(); i++)
	{
		StringGenres = StringGenres + "|" + genres[i];
	}

	gottenDataMaterialsList.resize(gottenDataMaterialsList.size() + 1);
	gottenDataMaterialsList[gottenDataMaterialsList.size() - 1] = to_string(max_id) + ":cd:" + name + ":" + StringAuthors + ":" + summary + ":" + StringGenres + ":" + language;
	string result = implode(';', gottenDataMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << result;
	file.close();

	return CD(name, authors, summary, genres, language);
}

CD STUFF::changeCD(int id)
{
	string gottenMaterialsString = readFile("data_library/materials");
	vector<string> gottenMaterialsList = explode(';', gottenMaterialsString);

	vector<string> neededBook;

	for (auto const &gottenMaterialString : gottenMaterialsList)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialString);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			neededBook = gottenMaterialList;
			break;
		}
	}
	cout << "Leave empty to do not change" << endl;
	cout << "Change to ->" << endl;

	vector<string> authors = {""}, genres = {""};
	string title, summary, language;

	cin.ignore();

	cout << "	Title: ";
	getline(cin, title);

	cin.ignore();

	cout << "	Author: ";
	getline(cin, authors[0]);

	cin.ignore();

	while (true)
	{
		cout << "	Do you want to add more authors? Press \"Y\"/\"y\" to add and \"N\"/\"n\" to not" << endl;

		string addAuthorKey;
		getline(cin, addAuthorKey);

		cin.ignore();

		if (addAuthorKey == "Y" || addAuthorKey == "y")
		{
			cout << "	Next author: ";
			authors.resize(authors.size() + 1);
			getline(cin, authors[authors.size() - 1]);

			cin.ignore();
		}
		else if (addAuthorKey == "N" || addAuthorKey == "n")
		{
			cout << "	Adding more authors canceled" << endl;
			break;
		}
		else
		{
			cout << "	Wrong option" << endl;
		}
	}

	cout << "	Summary: ";
	getline(cin, summary);

	cin.ignore();

	cout << "	Genre: ";
	getline(cin, genres[0]);

	cin.ignore();

	while (true)
	{
		cout << "	Do you want to add more genres? Press \"Y\"/\"y\" to add and \"N\"/\"n\" to not" << endl;

		string addGenreKey;
		getline(cin, addGenreKey);

		cin.ignore();

		if (addGenreKey == "Y" || addGenreKey == "y")
		{
			cout << "	Next genre: ";
			genres.resize(genres.size() + 1);
			getline(cin, genres[genres.size() - 1]);

			cin.ignore();
		}
		else if (addGenreKey == "N" || addGenreKey == "n")
		{
			cout << "	Adding more authors canceled" << endl;
			break;
		}
		else
		{
			cout << "	Wrong option" << endl;
		}
	}

	cout << "	Language: ";
	getline(cin, language);

	cin.ignore();

	vector<string> result = neededBook;

	if (title != "")
	{
		result[2] = title;
	}
	string stringAuthors = implode('|', authors);
	if (stringAuthors != "")
	{
		result[3] = stringAuthors;
	}
	if (summary != "")
	{
		result[4] = summary;
	}
	string stringGenres = implode('|', genres);
	if (stringGenres != "")
	{
		result[5] = stringGenres;
	}
	if (language != "")
	{
		result[6] = language;
	}

	for (size_t i = 0; i < gottenMaterialsList.size(); i++)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialsList[i]);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			gottenMaterialsList[i] = implode(':', result);
			break;
		}
	}

	string resultDataString = implode(';', gottenMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return CD(title, authors, summary, genres, language);
}

bool STUFF::removeCD(int id)
{
	string gottenDataString = readFile("data_library/materials");

	vector<string> gottenDataVector = explode(';', gottenDataString);

	std::string::size_type sz;

	for (size_t i = 0; i < gottenDataVector.size(); i++)
	{
		vector<string> book = explode(':', gottenDataVector[i]);
		if (stoi(book[0], &sz) == id)
		{
			gottenDataVector.erase(gottenDataVector.begin() + i);
			break;
		}
	}

	string resultDataString = implode(';', gottenDataVector);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return true;
}

NEWSPAPER STUFF::addNEWSPAPER(string name, vector<string> authors, string language)
{
	string gottenDataMaterialsString = readFile("data_library/materials");

	vector<string> gottenDataMaterialsList = explode(';', gottenDataMaterialsString);

	int max_id = 0;

	for (auto const &gottenDataMaterialString : gottenDataMaterialsList)
	{
		vector<string> gottenDataMaterialList = explode(':', gottenDataMaterialString);
		std::string::size_type sz;
		int i = stoi(gottenDataMaterialList[0], &sz);
		if (i > max_id)
		{
			max_id = i;
		}
	}

	max_id += 1;

	string StringAuthors = authors[0];
	for (size_t i = 1; i < authors.size(); i++)
	{
		StringAuthors = StringAuthors + "|" + authors[i];
	}

	gottenDataMaterialsList.resize(gottenDataMaterialsList.size() + 1);
	gottenDataMaterialsList[gottenDataMaterialsList.size() - 1] = to_string(max_id) + ":newspaper:" + name + ":" + StringAuthors + ":" + language;
	string result = implode(';', gottenDataMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << result;
	file.close();

	return NEWSPAPER(name, authors, language);
}

NEWSPAPER STUFF::changeNEWSPAPER(int id)
{
	string gottenMaterialsString = readFile("data_library/materials");
	vector<string> gottenMaterialsList = explode(';', gottenMaterialsString);

	vector<string> neededBook;

	for (auto const &gottenMaterialString : gottenMaterialsList)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialString);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			neededBook = gottenMaterialList;
			break;
		}
	}
	cout << "Leave empty to do not change" << endl;
	cout << "Change to ->" << endl;

	vector<string> authors = {""};
	string title, language;

	cin.ignore();

	cout << "	Title: ";
	getline(cin, title);

	cin.ignore();

	cout << "	Author: ";
	getline(cin, authors[0]);

	cin.ignore();

	while (true)
	{
		cout << "	Do you want to add more authors? Press \"Y\"/\"y\" to add and \"N\"/\"n\" to not" << endl;

		string addAuthorKey;
		getline(cin, addAuthorKey);

		cin.ignore();

		if (addAuthorKey == "Y" || addAuthorKey == "y")
		{
			cout << "	Next author: ";
			authors.resize(authors.size() + 1);
			getline(cin, authors[authors.size() - 1]);

			cin.ignore();
		}
		else if (addAuthorKey == "N" || addAuthorKey == "n")
		{
			cout << "	Adding more authors canceled" << endl;
			break;
		}
		else
		{
			cout << "	Wrong option" << endl;
		}
	}

	cout << "	Language: ";
	getline(cin, language);

	cin.ignore();

	vector<string> result = neededBook;

	if (title != "")
	{
		result[2] = title;
	}
	string stringAuthors = implode('|', authors);
	if (stringAuthors != "")
	{
		result[3] = stringAuthors;
	}
	if (language != "")
	{
		result[4] = language;
	}

	for (size_t i = 0; i < gottenMaterialsList.size(); i++)
	{
		vector<string> gottenMaterialList = explode(':', gottenMaterialsList[i]);
		std::string::size_type sz;
		if (stoi(gottenMaterialList[0], &sz) == id)
		{
			gottenMaterialsList[i] = implode(':', result);
			break;
		}
	}

	string resultDataString = implode(';', gottenMaterialsList);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return NEWSPAPER(title, authors, language);
}

bool STUFF::removeNEWSPAPER(int id)
{
	string gottenDataString = readFile("data_library/materials");

	vector<string> gottenDataVector = explode(';', gottenDataString);

	std::string::size_type sz;

	for (size_t i = 0; i < gottenDataVector.size(); i++)
	{
		vector<string> book = explode(':', gottenDataVector[i]);
		if (stoi(book[0], &sz) == id)
		{
			gottenDataVector.erase(gottenDataVector.begin() + i);
			break;
		}
	}

	string resultDataString = implode(';', gottenDataVector);

	ofstream file;
	file.open("data_library/materials", ios::trunc);
	file << resultDataString;
	file.close();

	return true;
}