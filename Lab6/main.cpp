#include<iostream>
#include <windows.h>
#include <fstream>
#include "Source6a.h"
#include "Source6b.h"
#include <string>
using namespace std;
int main() {
	srand(time(NULL));
	// Lab6 part1
	Libary lib1(3);
	Libary lib2;

	lib1.showLibary();
	ofstream outLibary("outputLibary.txt");
	outLibary << lib1;
	cout << endl;
	ifstream inLibary("outputLibary.txt");
	try
	{
		cout << "attempt to open a file outputLibary\n";
		if (!inLibary.is_open())
			throw(-1);
		cout << "the file is opened successfully\n\n";
		inLibary >> lib2;
		lib2.showLibary();
	}
	catch (int) {
		cout << "file opening error\n\n";
	}


	// Lab6 part2
	Matrix matrix1(5, 0, 20);
	Matrix matrix2(5);

	ofstream outMatrix("outputMatrix.txt");
	outMatrix << matrix1;
	outMatrix.close();
	matrix1.ShowMatrix();

	ifstream inMatrix("outputMatrix.txt");
	try
	{
		cout << "attempt to open a file inputMatrix\n";
		if (!inMatrix.is_open())
			throw(-1);
		cout << "the file is opened successfully\n\n";
		inMatrix >> matrix2;
		inMatrix.close();
		matrix2.ShowMatrix();
	}
	catch (int){
		cout << "file opening error\n\n";
	}

	
	system("pause");
	return 0;
}