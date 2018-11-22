#include <iostream>

using namespace std;

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
			if (!sign)
			{
				bottomString[index] = '-';
				bottomString[index + 1] = ' ';
				index += 2;
			}
			else
			{
				bottomString[index] = '+';
				bottomString[index + 1] = ' ';
				index += 2;
			}
		}

		if (coefficient != 1)
		{
			summandSymbolCounter += coefficientLength;
			for (int j = coefficientLength - 1; j >= 0; j--)
			{
				bottomString[index + j] = (char)(coefficient % 10 + (int)('0'));
				coefficient /= 10;
			}
			index += coefficientLength;
		}

		if (exponent)
		{
			bottomString[index] = 'x';
			index++;

			for (int j = 0; j < summandSymbolCounter; j++)
			{
				cout << ' ';
			}
			if (exponent > 1)
			{
				cout << exponent;
			}

			for (int j = 0; j < exponentLength; j++)
			{
				bottomString[index + j] = ' ';
			}
			index += exponentLength;
		}

		length += summandSymbolCounter + exponentLength;
		summandSymbolCounter = 0;

		if (!exponent)
		{
			length -= 1;
		}
	}

	length -= 1;

	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << bottomString[i];
	}
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

