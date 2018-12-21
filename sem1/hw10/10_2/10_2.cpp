#include <iostream>
#include "HWstring.h"
#include "rabinKarp.h"

using namespace std;

const int maximalSize = 100000;

int main()
{
	char word[maximalSize];
	cout << "Enter a string: ";
	cin >> word;
	String *string = createString(word);

	cout << "Enter a substring: ";
	cin >> word;
	String *subString = createString(word);

	int indexes[maximalSize];
	for (int i = 0; i < maximalSize; i++)
	{
		indexes[i] = -1;
	}

	rabinKarp(string, subString, indexes);

	int counter = 0;
	if (indexes[counter] == -1)
	{
		cout << "There is no entrances.";
		return 0;
	}

	cout << "Substrings first indexes: ";
	while (indexes[counter] != -1)
	{
		cout << indexes[counter] << ' ';
		counter++;
	}
	deleteString(string);
	deleteString(subString);

	return 0;
}

