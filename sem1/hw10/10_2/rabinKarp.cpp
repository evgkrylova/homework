#include <iostream>
#include <istream>
#include <string.h>
#include "rabinKarp.h"

using namespace std;

const int standartStringSize = 256;
const int mod = 1009;
const int prime = 19;

int getHash(char *string, int stringLength)
{
	int result = 0;
	for (int i = 0; i < stringLength; i++)
	{
		result = ((result * prime) + string[i]) % mod;
	}

	return result;
}

void updateHash(int &currentHash, char *string, int substringLength, int power, int i)
{
	currentHash = (((((currentHash - string[i] * power) % mod + mod) % mod) * prime) % mod + string[i + substringLength]) % mod;
}

bool areCharEqual(char *firstString, int firstLength, char *secondString, int secondLength, int startIndex)
{
	for (int i = 0; i < secondLength; i++)
	{
		if (firstString[i + startIndex] != secondString[i])
		{
			return false;
		}
	}

	return true;
}

void printArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ' ' << array[i];
	}
}

void rabinKarp(char *string, char *substring)
{
	int stringLength = strlen(string);
	int substringLength = strlen(substring);

	if (stringLength < substringLength)
	{
		cout << "There is no entrances.";
		return;
	}

	int *entrances = new int[standartStringSize] {0};

	int substringHash = getHash(substring, substringLength);
	int currentHash = getHash(string, substringLength);

	int power = 1;
	for (int i = 1; i < substringLength; i++)
	{
		power = (power * prime) % mod;
	}

	int currentIndex = 0;

	for (int i = 0; i < stringLength - substringLength + 1; i++)
	{
		if (currentHash == substringHash)
		{
			if (areCharEqual(string, stringLength, substring, substringLength, i))
			{
				entrances[currentIndex++] = i;
			}
		}

		updateHash(currentHash, string, substringLength, power, i);
	}

	if (currentIndex)
	{
		cout << "Substrings first indexes:";
		printArray(entrances, currentIndex);
	}
	else
	{
		cout << "There is no entrances.";
	}

	delete[] entrances;
}

