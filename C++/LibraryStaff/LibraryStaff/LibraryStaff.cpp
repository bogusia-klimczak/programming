#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "user.h"
#include "STUFF.h"

#include "BOOK.h"
#include "CD.h"
#include "NEWSPAPER.h"

#include "my_functions.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void main_menu();
void stuff_menu();
void guest_menu();
void operations_on_books_menu();
void operations_on_cds_menu();
void operations_on_newspapers_menu();

void stuff_func();
void guest_func();
void operations_on_books_func(STUFF stuff);
void operations_on_cds_func(STUFF stuff);
void operations_on_newspapers_func(STUFF stuff);

void main_menu()
{
	cout << "	MAIN MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers to:" << endl;
	cout << "		(01)	log in as stuff" << endl;
	cout << "		(02)	log in as guest" << endl;
	cout << "		(03)	exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void stuff_menu()
{
	cout << "	STUFF MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers to:" << endl;
	cout << "		(01)	operate on books" << endl;
	cout << "		(02)	operate on CDs" << endl;
	cout << "		(03)	operate on newspapers" << endl;
	cout << "		(04)	exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void guest_menu()
{
	cout << "	NORMAL USER MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers:" << endl;
	cout << "		(01)	to show book" << endl;
	cout << "		(02)	to show all books" << endl;
	cout << "		(03)	to show author" << endl;
	cout << "		(04)	to show all authors" << endl;
	cout << "		(05)	to exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void operations_on_books_menu()
{
	cout << "	STUFF MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers to:" << endl;
	cout << "		(01)	add book" << endl;
	cout << "		(02)	change book" << endl;
	cout << "		(03)	remove book" << endl;
	cout << "		(04)	show book" << endl;
	cout << "		(05)	show all books" << endl;
	cout << "		(06)	exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void operations_on_cds_menu()
{
	cout << "	STUFF MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers to:" << endl;
	cout << "		(01)	add CD" << endl;
	cout << "		(02)	change CD" << endl;
	cout << "		(03)	remove CD" << endl;
	cout << "		(04)	show CD" << endl;
	cout << "		(05)	show all CDs" << endl;
	cout << "		(06)	exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void operations_on_newspapers_menu()
{
	cout << "	STUFF MENU" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "	Type one of the following numbers to:" << endl;
	cout << "		(01)	add newspaper" << endl;
	cout << "		(02)	change newspaper" << endl;
	cout << "		(03)	remove newspaper" << endl;
	cout << "		(04)	show newspaper" << endl;
	cout << "		(05)	show all newspapers" << endl;
	cout << "		(06)	exit" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

void stuff_func()
{
	cout << "	Type in your ID: ";
	int id;
	cin >> id;

	cout << "	Type in your PASSWORD: ";
	string passwd;
	cin >> passwd;

	cout << endl;

	STUFF stuff(id, passwd);

	if (stuff.isErr())
	{
		cout << stuff.getErr() << endl;
		return;
	}

	cout << stuff.names() << endl;

	while (true)
	{
		stuff_menu();

		cout << "	";
		string key;
		cin >> key;

		if (key == "1")
		{
			cout << "	(01)	You've chosen option to operate on books" << endl;
			operations_on_books_func(stuff);
		}
		else if (key == "2")
		{
			cout << "	(02)	You've chosen option to operate on CDs" << endl;
			operations_on_cds_func(stuff);
		}
		else if (key == "3")
		{
			cout << "	(03)	You've chosen option to operate on newspapers" << endl;
			operations_on_newspapers_func(stuff);
		}
		else if (key == "4")
		{
			cout << "	(04)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}
}

void guest_func()
{
	cout << "	Type in your first name: ";
	string firstName;
	cin >> firstName;

	cout << "	Type in your last name: ";
	string lastName;
	cin >> lastName;
	cout << endl;

	user user(firstName, lastName);

	cout << user.names() << endl;

	while (true)
	{
		guest_menu();
		cout << "	";
		string key;
		cin >> key;

		if (key == "1")
		{
			cout << "	(01)	You've chosen option to show book" << endl;
			cout << "	Book id: ";
			int id_book_to_show;
			cin >> id_book_to_show;
			user.showBook(id_book_to_show);
		}
		else if (key == "2")
		{
			cout << "	(02)	You've chosen option to show all books" << endl;
			user.showBooks();
		}
		else if (key == "3")
		{
			cout << "	(03)	You've chosen option to show author" << endl;
		}
		else if (key == "4")
		{
			cout << "	(04)	You've chosen option to show all authors" << endl;
		}
		else if (key == "5")
		{
			cout << "	(05)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}
}

void operations_on_books_func(STUFF stuff)
{
	while (true)
	{
		operations_on_books_menu();

		cout << "	";
		string key;
		cin >> key;

		if (key == "1")
		{
			cout << "	(01)	You've chosen option to add book" << endl;

			string add_key;
			cout << "Are you really sure you want to add book? " << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> add_key;
				cin.ignore(1);
				if (add_key == "Y" || add_key == "y")
				{
					vector<string> authors = {""}, genres = {""};
					string name, summary, imprint, ISBN, language;

					cout << "	Title: ";
					getline(cin, name);

					cin.ignore(1);

					cout << "	Author: ";
					getline(cin, authors[0]);

					cin.ignore(1);

					while (true)
					{
						cout << "Do you want to add more authors? Press \"Y\"/\"y\" to add or \"N\"/\"n\" to cancel" << endl;
						string add_more_authors_key;
						getline(cin, add_more_authors_key);
						cin.ignore(1);
						if (add_more_authors_key == "Y" || add_more_authors_key == "y")
						{
							cout << "	Next author: ";
							authors.resize(authors.size() + 1);
							getline(cin, authors[authors.size() - 1]);
							cin.ignore(1);
						}
						else if (add_more_authors_key == "N" || add_more_authors_key == "n")
						{
							cout << "	No more authors" << endl;
							break;
						}
						else
						{
							cout << "Wrong option" << endl;
						}
					}

					cin.ignore(1);

					cout << "	Summary: ";
					getline(cin, summary);

					cin.ignore(1);

					cout << "	Imprint: ";
					getline(cin, imprint);

					cin.ignore(1);

					cout << "	ISBN: ";
					getline(cin, ISBN);

					cin.ignore(1);

					cout << "	Genre: ";
					getline(cin, genres[0]);

					cin.ignore(1);

					while (true)
					{
						cout << "Do you want to add more genres? Press \"Y\"/\"y\" to add or \"N\"/\"n\" to cancel" << endl;
						string add_more_genres_key;
						getline(cin, add_more_genres_key);
						cin.ignore(1);
						if (add_more_genres_key == "Y" || add_more_genres_key == "y")
						{
							cout << "	Next genre: ";
							genres.resize(genres.size() + 1);
							getline(cin, genres[genres.size() - 1]);
							cin.ignore(1);
						}
						else if (add_more_genres_key == "N" || add_more_genres_key == "n")
						{
							cout << "	No more genres" << endl;
							break;
						}
						else
						{
							cout << "Wrong option" << endl;
						}
					}

					cin.ignore(1);

					cout << "	Language: ";
					getline(cin, language);

					BOOK newBook = stuff.addBOOK(name, authors, summary, imprint, ISBN, genres, language);
					cout << "	Successfully added!" << endl;
					break;
				}
				else if (add_key == "N" || add_key == "n")
				{
					cout << "	Addition canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}

		else if (key == "2")
		{
			cout << "	(02)	You've chosen option to change book" << endl;

			cout << "	Book id: ";
			int id_book_to_change;
			cin >> id_book_to_change;
			string change_key;
			cout << "Are you really sure you want to change book: " << endl;
			stuff.showBook(id_book_to_change);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> change_key;
				if (change_key == "Y" || change_key == "y")
				{
					BOOK newBook = stuff.changeBOOK(id_book_to_change);
					cout << "	Successfully changed!" << endl;
					break;
				}
				else if (change_key == "N" || change_key == "n")
				{
					cout << "	Changing canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "3")
		{
			cout << "	(03)	You've chosen option to remove book" << endl;

			cout << "	Book id: ";
			int id_book_to_remove;
			cin >> id_book_to_remove;
			string delete_key;
			cout << "Are you really sure you want to delete book: " << endl;
			stuff.showBook(id_book_to_remove);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> delete_key;
				if (delete_key == "Y" || delete_key == "y")
				{
					stuff.removeBOOK(id_book_to_remove);
					cout << "	Successfully deleted!" << endl;
					break;
				}
				else if (delete_key == "N" || delete_key == "n")
				{
					cout << "	Deletion canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "4")
		{
			cout << "	(04)	You've chosen option to show book" << endl;
			cout << "	Book id: ";
			int id_book_to_show;
			cin >> id_book_to_show;
			stuff.showBook(id_book_to_show);
		}
		else if (key == "5")
		{
			cout << "	(05)	You've chosen option to show all books" << endl;
			stuff.showBooks();
		}
		else if (key == "6")
		{
			cout << "	(06)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}
}

void operations_on_cds_func(STUFF stuff)
{
	while (true)
	{
		operations_on_cds_menu();

		cout << "	";
		string key;
		cin >> key;

		if (key == "1")
		{
			cout << "	(01)	You've chosen option to add CD" << endl;

			string add_key;
			cout << "Are you really sure you want to add CD? " << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> add_key;
				cin.ignore(1);
				if (add_key == "Y" || add_key == "y")
				{
					vector<string> authors = {""}, genres = {""};
					string name, summary, language;

					cout << "	Title: ";
					getline(cin, name);

					cin.ignore(1);

					cout << "	Author: ";
					getline(cin, authors[0]);

					cin.ignore(1);

					while (true)
					{
						cout << "Do you want to add more authors? Press \"Y\"/\"y\" to add or \"N\"/\"n\" to cancel" << endl;
						string add_more_authors_key;
						getline(cin, add_more_authors_key);
						cin.ignore(1);
						if (add_more_authors_key == "Y" || add_more_authors_key == "y")
						{
							cout << "	Next author: ";
							authors.resize(authors.size() + 1);
							getline(cin, authors[authors.size() - 1]);
							cin.ignore(1);
						}
						else if (add_more_authors_key == "N" || add_more_authors_key == "n")
						{
							cout << "	No more authors" << endl;
							break;
						}
						else
						{
							cout << "Wrong option" << endl;
						}
					}

					cin.ignore(1);

					cout << "	Summary: ";
					getline(cin, summary);

					cin.ignore(1);

					cout << "	Genre: ";
					getline(cin, genres[0]);

					cin.ignore(1);

					while (true)
					{
						cout << "Do you want to add more genres? Press \"Y\"/\"y\" to add or \"N\"/\"n\" to cancel" << endl;
						string add_more_genres_key;
						getline(cin, add_more_genres_key);
						cin.ignore(1);
						if (add_more_genres_key == "Y" || add_more_genres_key == "y")
						{
							cout << "	Next genre: ";
							genres.resize(genres.size() + 1);
							getline(cin, genres[genres.size() - 1]);
							cin.ignore(1);
						}
						else if (add_more_genres_key == "N" || add_more_genres_key == "n")
						{
							cout << "	No more genres" << endl;
							break;
						}
						else
						{
							cout << "Wrong option" << endl;
						}
					}

					cin.ignore(1);

					cout << "	Language: ";
					getline(cin, language);

					CD newCD = stuff.addCD(name, authors, summary, genres, language);
					cout << "	Successfully added!" << endl;
					break;
				}
				else if (add_key == "N" || add_key == "n")
				{
					cout << "	Addition canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}

		else if (key == "2")
		{
			cout << "	(02)	You've chosen option to change CD" << endl;

			cout << "	CD id: ";
			int id_cd_to_change;
			cin >> id_cd_to_change;
			string change_key;
			cout << "Are you really sure you want to change CD: " << endl;
			stuff.showCD(id_cd_to_change);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> change_key;
				if (change_key == "Y" || change_key == "y")
				{
					CD newCD = stuff.changeCD(id_cd_to_change);
					cout << "	Successfully changed!" << endl;
					break;
				}
				else if (change_key == "N" || change_key == "n")
				{
					cout << "	Changing canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "3")
		{
			cout << "	(03)	You've chosen option to remove CD" << endl;

			cout << "	CD id: ";
			int id_cd_to_remove;
			cin >> id_cd_to_remove;
			string delete_key;
			cout << "Are you really sure you want to delete CD: " << endl;
			stuff.showCD(id_cd_to_remove);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> delete_key;
				if (delete_key == "Y" || delete_key == "y")
				{
					stuff.removeCD(id_cd_to_remove);
					cout << "	Successfully deleted!" << endl;
					break;
				}
				else if (delete_key == "N" || delete_key == "n")
				{
					cout << "	Deletion canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "4")
		{
			cout << "	(04)	You've chosen option to show CD" << endl;
			cout << "	CD id: ";
			int id_cd_to_show;
			cin >> id_cd_to_show;
			stuff.showCD(id_cd_to_show);
		}
		else if (key == "5")
		{
			cout << "	(05)	You've chosen option to show all CDs" << endl;
			stuff.showCDS();
		}
		else if (key == "6")
		{
			cout << "	(06)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}
}

void operations_on_newspapers_func(STUFF stuff)
{
	while (true)
	{
		operations_on_newspapers_menu();

		cout << "	";
		string key;
		cin >> key;

		if (key == "1")
		{
			cout << "	(01)	You've chosen option to add newspaper" << endl;

			string add_key;
			cout << "Are you really sure you want to add newspaper? " << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> add_key;
				cin.ignore(1);
				if (add_key == "Y" || add_key == "y")
				{
					vector<string> authors = {""};
					string name, language;

					cout << "	Title: ";
					getline(cin, name);

					cin.ignore(1);

					cout << "	Author: ";
					getline(cin, authors[0]);

					cin.ignore(1);

					while (true)
					{
						cout << "Do you want to add more authors? Press \"Y\"/\"y\" to add or \"N\"/\"n\" to cancel" << endl;
						string add_more_authors_key;
						getline(cin, add_more_authors_key);
						cin.ignore(1);
						if (add_more_authors_key == "Y" || add_more_authors_key == "y")
						{
							cout << "	Next author: ";
							authors.resize(authors.size() + 1);
							getline(cin, authors[authors.size() - 1]);
							cin.ignore(1);
						}
						else if (add_more_authors_key == "N" || add_more_authors_key == "n")
						{
							cout << "	No more authors" << endl;
							break;
						}
						else
						{
							cout << "Wrong option" << endl;
						}
					}

					cin.ignore(1);

					cout << "	Language: ";
					getline(cin, language);

					NEWSPAPER newNewspaper = stuff.addNEWSPAPER(name, authors, language);
					cout << "	Successfully added!" << endl;
					break;
				}
				else if (add_key == "N" || add_key == "n")
				{
					cout << "	Addition canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}

		else if (key == "2")
		{
			cout << "	(02)	You've chosen option to change newspaper" << endl;

			cout << "	Newspaper id: ";
			int id_newspaper_to_change;
			cin >> id_newspaper_to_change;
			string change_key;
			cout << "Are you really sure you want to change newspaper: " << endl;
			stuff.showNewspaper(id_newspaper_to_change);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> change_key;
				if (change_key == "Y" || change_key == "y")
				{
					NEWSPAPER newNewspaper = stuff.changeNEWSPAPER(id_newspaper_to_change);
					cout << "	Successfully changed!" << endl;
					break;
				}
				else if (change_key == "N" || change_key == "n")
				{
					cout << "	Changing canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "3")
		{
			cout << "	(03)	You've chosen option to remove newspaper" << endl;

			cout << "	Newspaper id: ";
			int id_newspaper_to_remove;
			cin >> id_newspaper_to_remove;
			string delete_key;
			cout << "Are you really sure you want to delete newspaper: " << endl;
			stuff.showNewspaper(id_newspaper_to_remove);
			cout << "?" << endl;
			while (true)
			{
				cout << "Press \"Y\"/\"y\" (yes) or \"N\"/\"n\" (no): ";
				cin >> delete_key;
				if (delete_key == "Y" || delete_key == "y")
				{
					stuff.removeNEWSPAPER(id_newspaper_to_remove);
					cout << "	Successfully deleted!" << endl;
					break;
				}
				else if (delete_key == "N" || delete_key == "n")
				{
					cout << "	Deletion canceled!" << endl;
					break;
				}
				else
				{
					cout << "	Unknown option!" << endl;
				}
			}
		}
		else if (key == "4")
		{
			cout << "	(04)	You've chosen option to show newspaper" << endl;
			cout << "	Newspaper id: ";
			int id_newspaper_to_show;
			cin >> id_newspaper_to_show;
			stuff.showNewspaper(id_newspaper_to_show);
		}
		else if (key == "5")
		{
			cout << "	(05)	You've chosen option to show all newspapers" << endl;
			stuff.showNewspapers();
		}
		else if (key == "6")
		{
			cout << "	(06)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}
}

int main()
{
	system("mode con cols=70 lines=9999");

	const char *_Path = "data_library";
	if (!is_dir(_Path))
	{
		create_library(_Path);
	}

	while (true)
	{
		main_menu();
		cout << "	";
		string key;
		cin >> key;
		if (key == "1")
		{
			cout << "	(01)    You've chosen option to log in as stuff" << endl;
			stuff_func();
		}
		else if (key == "2")
		{
			cout << "	(02)    You've chosen option to log in as guest" << endl;
			guest_func();
		}
		else if (key == "3")
		{
			cout << "	(03)    You've chosen option to exit" << endl;
			break;
		}
		else
		{
			cout << "	(nn)    Unknown verison of option" << endl;
		}
	}

	system("pause");
}