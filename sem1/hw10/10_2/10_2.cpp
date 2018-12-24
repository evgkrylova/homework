#include <iostream>
#include <string.h>
#include "rabinKarp.h"

using namespace std;

const int standartStringSize = 256;

int main()
{
	char *string = new char[standartStringSize];
	cout << "Enter a string: ";
	cin >> string;

	char *substring = new char[standartStringSize];
	cout << "Enter a substring: ";
	cin >> substring;

	rabinKarp(string, substring);

	delete[] string;
	delete[] substring;

	return 0;
}

