#include <iostream>
#include <string>
#include "BOOK.h"

using std::cout;
using std::endl;
using std::string;

BOOK::BOOK(string title, vector<string> authors, string summary, string imprint, string ISBN, vector<string> genres, string language) : MATERIAL(title, authors, language)
{
	_m_summary = summary;
	_m_imprint = imprint;
	_m_ISBN = ISBN;
	_m_genres = genres;
}

void BOOK::__show() const
{
	cout << "BOOK INFORMATION" << endl;
	cout << "ID: " << endl;
	cout << "TITLE: " << getTitle() << endl;
	cout << "AUTHORS: ";
	vector<string> authors = getAuthors();
	for (size_t i = 0; i < authors.size(); i++)
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
	cout << "IMPRINT: " << _m_imprint;
	cout << "ISBN: " << _m_ISBN << endl;
	cout << "GENRES: ";
	vector<string> genres = _m_genres;
	for (size_t i = 0; i < genres.size(); i++)
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