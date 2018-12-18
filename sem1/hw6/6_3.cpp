#include <iostream>

using namespace std;

void printArray(char *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
	}
}

int absoluteValue(int number)
{
	if (number > 0)
	{
		return number;
	}
	return (-1) * number;
}

int lengthOfNumber(int number)
{
	int counter = 1;
	int modulus = absoluteValue(number);
	while (modulus / 10 > 0)
	{
		counter++;
		modulus = modulus / 10;
	}
	return counter;
}

bool isPositive(int number)
{
	if (number >= 0)
	{
		return true;
	}
	return false;
}

void printCoefficient(int coefficient, int &index, int &counter, char *&string)
{
	int coefficientLength = lengthOfNumber(coefficient);
	counter += coefficientLength;
	for (int i = coefficientLength - 1; i >= 0; i--)
	{
		string[index + i] = (char)(coefficient % 10 + '0');
		coefficient /= 10;
	}
	index += coefficientLength;
}

void printExponent(int exponent, int &index, int &counter, int &length, char *&string)
{
	int exponentLength = lengthOfNumber(exponent);
	
	if (!exponent)
	{
		length -= 1;
		length += counter + exponentLength;
		counter = 0;
		return;
	}
	
	string[index] = 'x';
	index++;

	for (int j = 0; j < counter; j++)
	{
		cout << ' ';
	}

	if (exponent > 1)
	{
		cout << exponent;
	}

	for (int j = 0; j < exponentLength; j++)
	{
		string[index + j] = ' ';
	}

	index += exponentLength;
	length += counter + exponentLength;
	counter = 0;
}

void printPolynomial(int *coefficients, int degree)
{
	cout << endl;

	int length = 0;
	const int maxLength = 10000;
	char *bottomString = new char[maxLength];
	int index = 0;

	for (int i = 0; i <= degree; i++)
	{
		int summandSymbolCounter = 1;
		int coefficient = absoluteValue(coefficients[i]);
		int coefficientLength = lengthOfNumber(coefficient);
		bool sign = isPositive(coefficients[i]);
		int exponent = degree - i;
		int exponentLength = lengthOfNumber(exponent);

		if (coefficient == 0)
		{
			continue;
		}

		if ((i != 0) || ((i == 0) && (!sign)))
		{
			summandSymbolCounter += 2;
			bottomString[index] = sign ? '+' : '-';
			bottomString[index + 1] = ' ';
			index += 2;
		}

		if ((coefficient != 1) || (!exponent))
		{
			printCoefficient(coefficient, index, summandSymbolCounter, bottomString);
		}

		printExponent(exponent, index, summandSymbolCounter, length, bottomString);
	}

	cout << endl;
	printArray(bottomString, length - 1);
}

int main()
{
	int degree = 0;
	cout << "Enter the polynomial degree: ";
	cin >> degree;

	int *coefficients = new int[degree + 1];
	cout << "Enter the coefficients of the polynomial: ";
	for (int i = 0; i <= degree; i++)
	{
		cin >> coefficients[i];
	}

	printPolynomial(coefficients, degree);

	delete[] coefficients;

	return 0;
}

