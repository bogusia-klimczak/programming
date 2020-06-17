#include <iostream>
#include <string>
#include "CD.h"

using std::cout;
using std::endl;
using std::string;

CD::CD(string title, vector<string> authors, string summary, vector<string> genres, string language) : MATERIAL(title, authors, language)
{
	_m_summary = summary;
	_m_genres = genres;
}

void CD::__show() const
{
	cout << "CDS INFORMATION" << endl;
	cout << "ID: " << endl;
	cout << "TITLE: " << getTitle() << endl;
	cout << "AUTHORS: ";
	vector<string> authors = getAuthors();
	for (int i = 0; i < authors.size(); i++)
	{
		if (i == (authors.size() - 1))
		{
			cout << authors[i];
		}
		else
		{
			cout << authors[i] << ", ";
		}
	}
	cout << endl;
	cout << "SUMMARY: " << _m_summary << endl;
	cout << "GENRES: ";
	vector<string> genres = _m_genres;
	for (int i = 0; i < genres.size(); i++)
	{
		if (i == (genres.size() - 1))
		{
			cout << genres[i];
		}
		else
		{
			cout << genres[i] << ", ";
		}
	}
	cout << endl;
	cout << "LANGUAGE: " << getLanguage() << endl;
}