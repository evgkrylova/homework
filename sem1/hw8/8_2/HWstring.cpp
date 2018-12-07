#include <iostream>
#include "HWstring.h"

using namespace std;

String *createString()
{
	return new String{ 0, nullptr };
}

void deleteString(String *&string)
{
	delete[] string->symbols;
	delete string;
}

void readString(String *string)
{
	const int maxLength = 256;

	int length = 0;
	char *readingString = new char[maxLength];

	char currentSymbol = '\0';
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get(currentSymbol);

	int index = 0;
	while (currentSymbol != '\n')
	{
		readingString[index] = currentSymbol;
		index++;
		cin.get(currentSymbol);
	}
	length = index;

	string->length = length;
	string->symbols = new char[length];

	for (int i = 0; i < length; i++)
	{
		string->symbols[i] = readingString[i];
	}
}

String *clone(String *string)
{
	return getSubstring(string, 0, string->length - 1);
}

String *concatenate(String *firstString, String *secondString)
{
	String *sumString = createString();

	int sumStringLength = firstString->length + secondString->length;
	sumString->length = sumStringLength;
	sumString->symbols = new char[sumStringLength];

	for (int i = 0; i < firstString->length; i++)
	{
		sumString->symbols[i] = firstString->symbols[i];
	}
	for (int i = firstString->length; i < sumStringLength; i++)
	{
		sumString->symbols[i] = secondString->symbols[i - firstString->length];
	}

	return sumString;
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
	String *substring = createString();

	int substringLength = end - begin + 1;
	substring->length = substringLength;
	substring->symbols = new char[substringLength];

	for (int i = 0; i < substringLength; i++)
	{
		substring->symbols[i] = string->symbols[begin + i];
	}

	return substring;
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

