#include <iostream>
#include <windows.h>
#include <cstring>
#include <string>
#include <time.h>

using namespace std;

string random_word() {
	char temp[10];
	int letter = rand() % (5 - 3 + 1) + 3;
	bool first_letter = true;
	for (int i = 0; i < 5; i++)
	{
		temp[i] = rand() % (122 - 97 + 1) + 97;
		if (first_letter)
			temp[i] = toupper(temp[i]);
		first_letter = false;
	}
	temp[5] = '\0';
	return (string)temp;
}

class Book {
private:
	string name_book;
	string author;
	string publishing_house;
	int year;
	int pages;
	
public:
	Book();
	Book(string* all_authors, string* all_publishing_house);
	void Show();
	string get_name_book();
	string get_author();
	string get_publishing_house();
	int get_year();
	int get_pages();
	friend string random_word();
};

Book::Book() {
	cout << "Name book: ";	getline(cin, this->name_book);
	cout << "Author: "; getline(cin, this->author);
	cout << "Publishing House: "; getline(cin, this->publishing_house);
	cout << "Year: "; cin >> this->year;
	cout << "Pages: ";	cin >> this->pages;

	//	this->author = random_word(); //all_authors[rand() % (9 - 0 + 1) + 0];
	//	this->publishing_house = random_word(); 
	//	this->pages = rand() % (500 - 100 + 1) + 100; 
	//	this->year = rand() % (2020 - 1400 + 1) + 1400; 
	//	this->name_book = random_word(); 
	}
Book::Book(string* all_authors, string* all_publishing_house) {
	this->author = all_authors[rand() % (9 - 0 + 1) + 0];
	this->publishing_house = all_publishing_house[rand() % (9 - 0 + 1) + 0];
	this->pages = rand() % (500 - 100 + 1) + 10;
	this->year = rand() % (2020 - 1400 + 1) + 1400;
	this->name_book = random_word();
} 
void Book::Show() {
	cout << "Name Book \" " << this->name_book << "\"\n";
	cout << "Author \" " << this->author << "\"\n";
	cout << "Publishing house \" " << this->publishing_house << "\"\n";
	cout << "Year \" " << this->year << "\"\n";
	cout << "Pages \" " << this->pages << "\"\n";
	cout << "================================================\n";
}
string Book::get_name_book() { return this->name_book; }
string Book::get_author() { return this->author; }
string Book::get_publishing_house() { return this->publishing_house; }
int Book::get_year() { return this->year; }
int Book::get_pages() { return this->pages; }

//string* addInArray(string* arr, string str, int n) {
//
//}

bool equilString(string str1, string str2) {
	for (int i = 0; i < str1.length(); i++)
		str1[i] = tolower(str1[i]);
	
	for (int i = 0; i < str2.length(); i++)
		str2[i] = tolower(str2[i]);

	if (str1 == str2)
		return true;
	else
		return false;
}

void swithOneAuthor(Book* book, int n) {
	string author; 
	cout << "\nYour author: "; cin >> author;
	for (int i = 0; i < n; i++)
	{
		if (equilString(author, book[i].get_author()))
		{
			cout << endl;
			book[i].Show();
		}
	}
}

void swithPublishingHouse(Book* book, int n) {
	string publishing_house;
	cout << "\nYour Publishing House: "; cin >> publishing_house;
	for (int i = 0; i < n; i++)
	{
		if (equilString(publishing_house, book[i].get_publishing_house()))
		{
			cout << endl;
			book[i].Show();
		}
	}
}

void Year(Book* book, int n) {
	int your_year;
	cout << "Input yor yaer: "; cin >> your_year;
	for (int i = 0; i < n; i++)
	{
		if (book[i].get_year() >= your_year)
			book[i].Show();
	}
}

int main() {
	srand(time(NULL));
	int n;
	cout << "How books "; cin >> n;
	Book* book = new Book[n];
	delete[]book;
	return 0;
	system("pause");
}