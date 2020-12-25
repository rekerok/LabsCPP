#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
using namespace std;
class Libary
{
private:
	vector <Book> book;
	vector <string> authors;
	vector <string> publishing_houses;
public:
	Libary();
	Libary(int n);
	void addBookAuto();
	void addBookManually();
	void deleteBook(int index);
	void showLibary();
	void getBook(int index);
	void showInfoLibary();
	void selectAuthor();
	void selectPublishingHouse();
	void selectBetweenYears(int min, int max);
	void selectBetweenPages(int min, int max);
	void sortByName();
	void sortByAuthor();
	void sortByYear();
	void sortByPages();
	friend std::ostream& operator<< (std::ostream& out, const Libary& libary);
	friend std::istream& operator>> (std::istream& in, Libary& libary);
};

