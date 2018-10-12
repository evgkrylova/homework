#include "stdafx.h"
#include <iostream>

using namespace std;

void compilingFareySequence(int n)
{
	int firstNumerator = 0;
	int firstDenominator = 1;
	int secondNumerator = 1;
	int secondDenominator = n;

	cout << firstNumerator << "/" << firstDenominator << "\n";

	while (secondNumerator <= n)
	{
		int factor = (n + firstDenominator) / secondDenominator;
		int tempNumerator = firstNumerator;
		int tempDenominator = firstDenominator;
		firstNumerator = secondNumerator;
		firstDenominator = secondDenominator;
		secondNumerator = secondNumerator * factor - tempNumerator;
		secondDenominator = secondDenominator * factor - tempDenominator;

		cout << firstNumerator << "/" << firstDenominator << "\n";
	}
}

int main()
{
	int maxDenominator = 0;
	cout << "Enter the largest possible denominator: ";
	cin >> maxDenominator;

	cout << "There are all simple irreducible conforming fractions: " << "\n";

	compilingFareySequence(maxDenominator);

	return 0;
}
