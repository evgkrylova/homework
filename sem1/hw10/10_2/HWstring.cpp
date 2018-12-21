#include <iostream>
#include <istream>
#include <string.h>
#include "HWstring.h"

using namespace std;

String *createString(char *symbols)
{
	String *string = new String;
	string->length = strlen(symbols);
	string->symbols = new char[string->length];

	for (int counter = 0; counter < string->length; counter++)
	{
		string->symbols[counter] = symbols[counter];
	}

	return string;
}

void deleteString(String *&string)
{
	delete[] string->symbols;
	delete string;
}

void readString(String *&string)
{
	deleteString(string);

	const int maxSize = 1000;
	char tmp[maxSize];
	char curSymbol = 0;
	cin.get(curSymbol);
	int size = 0;

	while (curSymbol != '\n' && curSymbol != ' ')
	{
		tmp[size] = curSymbol;
		size++;
		cin.get(curSymbol);
	}

	string->symbols = new char[size];
	string->length = size;
	for (int i = 0; i < size; ++i)
	{
		string->symbols[i] = tmp[i];
	}

	delete[] tmp;
}

String *clone(String *string)
{
	return getSubstring(string, 0, string->length - 1);
}

bool areEqual(String *firstString, String *secondString) 
{
	if (firstString->length != secondString->length)
	{
		return false;
	}

	for (int i = 0; i < firstString->length; i++)
	{
		if (firstString->symbols[i] != secondString->symbols[i])
		{
			return false;
		}
	}

	return true;
}

int length(String *string)
{
	return string->length;
}

bool isEmpty(String *string)
{
	return (string->length == 0);
}

String *getSubstring(String *string, int begin, int end)
{
	char *stringChar = convertToChar(string);
	char *subStringChar = new char[end - begin + 2];

	for (int i = 0; i <= end - begin; i++)
	{
		subStringChar[i] = stringChar[i + begin];
	}

	subStringChar[end - begin + 1] = '\0';

	String *newString = createString(subStringChar);

	delete[] subStringChar;

	return newString;
}

char *convertToChar(String *string)
{
	return string->symbols;
}

void printString(String *string)
{
	char *array = convertToChar(string);
	int size = length(string);
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
	}
}

char getChar(String *string, int index)
{
	if (0 <= index && index < string->length)
	{
		return string->symbols[index];
	}

	return '\0';
}

int stringLength(String *string)
{
	return string->length;
}

