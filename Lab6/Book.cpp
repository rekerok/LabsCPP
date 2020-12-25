#include "Book.h"
#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;
Book::Book() {

}
Book::Book(vector<string>& all_authors, vector<string>& all_publishing_house) {
	this->name_book = random_word();
	this->author = all_authors[rand() % ((all_authors.size() - 1) - 0 + 1) + 0];
	this->publishing_house = all_publishing_house[rand() % ((all_publishing_house.size() - 1) - 0 + 1) + 0];
	this->year = rand() % (2020 - 1400 + 1) + 1400;
	this->pages = rand() % (500 - 100 + 1) + 10;
}
Book::Book(string name_book, string author, string publishing_house, int year, int pages)
{
	this->name_book = name_book;
	this->author = author;
	this->publishing_house = publishing_house;
	this->year = year;
	this->pages = pages;
}
void Book::addBookManually()
{
	cout << "Name book: ";	getline(cin, this->name_book);
	cout << "Author: "; getline(cin, this->author);
	cout << "Publishing House: "; getline(cin, this->publishing_house);
	cout << "Year: "; cin >> this->year;
	cout << "Pages: ";	cin >> this->pages;
}
void Book::Show() {
	cout << "Name Book \"" << this->name_book << "\"\n";
	cout << "Author \"" << this->author << "\"\n";
	cout << "Publishing house \"" << this->publishing_house << "\"\n";
	cout << "Year \"" << this->year << "\"\n";
	cout << "Pages \"" << this->pages << "\"\n";
	cout << "================================================\n";
}
string Book::get_name_book() { return this->name_book; }
string Book::get_author() { return this->author; }
string Book::get_publishing_house() { return this->publishing_house; }
int Book::get_year() { return this->year; }
int Book::get_pages() { return this->pages; }

void Book::set_name(string name_book) { this->name_book = name_book; }
void Book::set_author(string author) { this->author = author; }
void Book::set_publishing_house(string publishing_house) { this->publishing_house = publishing_house; }
void Book::set_year(int year) { this->year = year; }
void Book::set_pages(int pages) { this->pages = pages; }

std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << "Name book: " << book.name_book;
	out << "\nAuthor: " << book.author;
	out << "\nPublishing House: " << book.publishing_house;
	out << "\nYear: " << book.year;
	out << "\nPages: " << book.pages;
	out << endl << endl;
	return out;
}
