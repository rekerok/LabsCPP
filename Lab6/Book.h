#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Book
{
private:
	string name_book;
	string author;
	string publishing_house;
	int year;
	int pages;
public:
	Book();
	Book(vector<string>& all_authors, vector<string>& all_publishing_house);
	Book(string name_book, string author, string publishing_house, int year, int pages);
	
	void addBookManually();
	
	void Show();

	string get_name_book();
	string get_author();
	string get_publishing_house();
	int get_year();
	int get_pages();
	
	void set_name(string name_book);
	void set_author(string author);
	void set_publishing_house(string publishing_house);
	void set_year(int year);
	void set_pages(int pages);

	friend std::ostream& operator<< (std::ostream& out, const Book& book);
	friend std::istream& operator>> (std::istream& in, Book& book);
};