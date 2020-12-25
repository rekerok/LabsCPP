#include "Source6a.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
Libary::Libary()
{
	int tmp = rand() % (6 - 3 + 1) + 3;
	for (int i = 0; i < tmp; i++)
	{
		this->authors.push_back(random_word());
		this->publishing_houses.push_back(random_word());
	}
}

Libary::Libary(int n) : Libary()
{
	for (int i = 0; i < n; i++)
		this->addBookAuto();
}

void Libary::addBookAuto()
{
	Book tmpBook(authors, publishing_houses);
	this->book.push_back(tmpBook);
}

void Libary::addBookManually()
{
	cin.get();
	Book tmp;
	tmp.addBookManually();
	this->book.push_back(tmp);
}

void Libary::deleteBook(int index)
{
	book.erase(book.begin() + (index - 1));
}

void Libary::showLibary()
{
	for (int i = 0; i < this->book.size(); i++)
	{
		cout << i + 1 << ") "; this->book[i].Show();
		cout << endl << endl;
	}
}

void Libary::getBook(int index)
{
	cout << index << ") "; this->book[index - 1].Show();
	cout << endl << endl;
}

void Libary::showInfoLibary()
{
	this->showLibary();
	cout << "All authors\n";
	for (int i = 0; i < this->authors.size(); i++)
		cout << i + 1 << ") " << authors[i] << endl;
	cout<<endl;
	cout << "All publishing houses\n";
	for (int i = 0; i < this->publishing_houses.size(); i++)
		cout << i + 1 << ") " << publishing_houses[i] << endl;
	cout << endl;
	cout << "Number of books in the library: " << this->book.size() << endl << endl;
}

void Libary::selectAuthor()
{
	ofstream out("selectAuthor.txt");
	string tmpAuthor;
	cout << "Input the selected author -> "; getline(cin, tmpAuthor);
	for (int i = 0; i < this->book.size(); i++)
		if (equalString(book[i].get_author(), tmpAuthor))
			out << book[i] << endl;
	out.close();
}

void Libary::selectPublishingHouse()
{
	ofstream out("selectPublishingHouse.txt");
	string tmpPublishingHouse;
	cout << "Input the selected publising house -> "; getline(cin, tmpPublishingHouse);
	for (int i = 0; i < this->book.size(); i++)
		if (equalString(book[i].get_publishing_house(), tmpPublishingHouse))
			out << book[i] << endl;
	out.close();
}

void Libary::selectBetweenYears(int min, int max)
{
	ofstream out("selectBetweenYears.txt");
	cout << "You entered years from " << min << " to " << max;
	for (int i = 0; i < this->book.size(); i++)
		if (this->book[i].get_year() >= min && this->book[i].get_year() <= max)
			out << book[i] << endl;
	out.close();
}



void Libary::selectBetweenPages(int min, int max)
{
	ofstream out("selectBetweenPages.txt");
	cout << "You entered pages from " << min << " to " << max;
	for (int i = 0; i < this->book.size(); i++)
		if (this->book[i].get_pages() >= min && this->book[i].get_pages() <= max)
			out << book[i] << endl;
	out.close();
}

void Libary::sortByName()
{
	for (int i = 1; i < this->book.size(); i++)
		for (int j = i; j > 0; j--)
			if (this->book[j].get_name_book() < this->book[j - 1].get_name_book())
				swap(book[j], book[j - 1]);
			else
				break;
}

void Libary::sortByAuthor()
{
	for (int i = 1; i < this->book.size(); i++)
		for (int j = i; j > 0; j--)
			if (this->book[j].get_author() < this->book[j - 1].get_author())
				swap(book[j], book[j - 1]);
			else
				break;
}

void Libary::sortByYear()
{
	for (int i = 1; i < this->book.size(); i++)
		for (int j = i; j > 0; j--)
			if (this->book[j].get_year() < this->book[j - 1].get_year())
				swap(book[j], book[j - 1]);
			else
				break;
}

void Libary::sortByPages()
{
	for (int i = 1; i < this->book.size(); i++)
		for (int j = i; j > 0; j--)
			if (this->book[j].get_pages() < this->book[j - 1].get_pages())
				swap(book[j], book[j - 1]);
			else
				break;
}

std::ostream& operator<<(std::ostream& out, const Libary& libary)
{
	for (int i = 0; i < libary.book.size(); i++)
	{
		out << i + 1 << ") " << libary.book[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, Libary& libary)
{
	
	string tmp;
	int i = 1;
	while (!in.eof()) {
		Book book;
		for (getline(in, tmp); i != 6; getline(in, tmp), i++) {
			if (tmp == "")
				continue;
			else {
				string mainWord = selectMainWord(tmp);
				if (i == 1)
					book.set_name(mainWord);
				else if (i == 2) {
					book.set_author(mainWord);
					libary.authors.push_back(mainWord);
				}
				else if (i == 3) {
					book.set_publishing_house(mainWord);
					libary.publishing_houses.push_back(mainWord);
				}
				else if (i == 4)
					book.set_year(atoi(mainWord.c_str()));
				else
					book.set_pages(atoi(mainWord.c_str()));
			}

		}
		i = 1;
		libary.book.push_back(book);
	};
	libary.book.pop_back();
	return in;
}
