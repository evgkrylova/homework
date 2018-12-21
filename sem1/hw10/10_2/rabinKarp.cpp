#include <iostream>
#include <istream>
#include <string.h>
#include "HWstring.h"
#include "rabinKarp.h"

using namespace std;

const int mod = 1009;
const int prime = 19;

int getHash(String *string, int start, int end)
{
	int result = 0;
	for (int i = start; i < end; i++)
		result = ((result * prime) % mod + (int)getChar(string, i)) % mod;

	return result;
}

void rabinKarp(String *string, String *substring, int *indexes)
{
	if (substring->length > string->length)
	{
		return;
	}

	int start = 0;
	int subHash = getHash(substring, 0, stringLength(substring));
	int currentHash = getHash(string, 0, stringLength(substring));

	int power = 1;
	for (int i = 1; i < stringLength(substring); i++)
	{
		power = (power * prime) % mod;
	}

	int counter = 0;
	for (int i = start; i <= stringLength(string) - stringLength(substring); i++)
	{
		if (currentHash == subHash)
		{
			String *slice = getSubstring(string, i, i + stringLength(substring) - 1);
			if (areEqual(substring, slice))
			{
				indexes[counter] = i + 1;
				counter++;
			}
			deleteString(slice);
		}
		currentHash = (((((currentHash - (getChar(string, i)) * power) % mod + mod) % mod) * prime) % mod + getChar(string, i + stringLength(substring))) % mod;
	}
}

