#include <iostream>
#include <windows.h>
#include <cstring>
#include "Functions.h"

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

bool equalString(string str1, string str2) {
	for (int i = 0; i < str1.length(); i++)
		str1[i] = tolower(str1[i]);

	for (int i = 0; i < str2.length(); i++)
		str2[i] = tolower(str2[i]);

	if (str1 == str2)
		return true;
	else
		return false;
}

string selectMainWord(string str)
{
	string tmp = "";
	bool thisWord = false;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == ':'){
			thisWord = true;
			i++;
			continue;
		}

		if (thisWord)
			tmp += str[i];
	}
	return tmp;
}
