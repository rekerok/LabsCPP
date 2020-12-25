#include<iostream>
#include <windows.h>
#include <fstream>
#include "Source6a.h"
#include "Source6b.h"
#include <string>
using namespace std;
int main() {
	srand(time(NULL));
	Libary lib(15);
	ofstream a("libaryOut.txt");
	a << lib;
	lib.showLibary();


	Libary lib2;
	ifstream b("libaryOut.txt");
	b >> lib2;
	lib2.showLibary();

	system("pause");
	return 0;
}