#include <iostream>
#include "binary.h"

using namespace std;

int *getBinaryNotation(int decimalNotation)
{
	int *binaryNotation = new int[bitsNumber];
	int mask = 0x40000000;

	if (decimalNotation >= 0)
	{
		binaryNotation[0] = 0;
	}
	else
	{
		binaryNotation[0] = 1;
	}

	for (int i = 1; i < bitsNumber; i++)
	{
		if (mask & decimalNotation)
		{
			binaryNotation[i] = 1;
		}
		else
		{
			binaryNotation[i] = 0;
		}

		mask = mask >> 1;
	}

	return binaryNotation;
}

int *getSumOfBinaryNotations(int *a, int *b)
{
	int carry = 0;
	int *sumOfBinaryNotations = new int[bitsNumber];

	for (int i = bitsNumber - 1; i >= 0; i--)
	{
		int sumOfPositions = a[i] + b[i] + carry;
		sumOfBinaryNotations[i] = sumOfPositions % 2;
		carry = sumOfPositions / 2;
	}

	return sumOfBinaryNotations;
}

int getDecimalNotation(int *binaryNotation)
{
	int decimalNotation = 0;
	int exponent = 1;
	for (int i = bitsNumber - 1; i >= 0; i--)
	{
		decimalNotation += binaryNotation[i] * exponent;
		exponent *= 2;
	}
	return decimalNotation;
}

void printArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
	}
	cout << endl;
	return;
}

