#include <iostream>

using namespace std;

struct Fraction
{
	int numerator;
	int denominator;
};

void compileFareySequence(int n)
{
	cout << "There are all simple irreducible conforming fractions: " << "\n";

	Fraction firstFraction{ 0, 1 };
	Fraction secondFraction{ 1, n };

	cout << firstFraction.numerator << "/" << firstFraction.denominator << "\n";

	while (secondFraction.numerator <= n)
	{
		int factor = (n + firstFraction.denominator) / secondFraction.denominator;
		Fraction tempFraction{ firstFraction.numerator, firstFraction.denominator };
		firstFraction.numerator = secondFraction.numerator;
		firstFraction.denominator = secondFraction.denominator;
		secondFraction.numerator = secondFraction.numerator * factor - tempFraction.numerator;
		secondFraction.denominator = secondFraction.denominator * factor - tempFraction.denominator;

		cout << firstFraction.numerator << "/" << firstFraction.denominator << "\n";
	}
}

int main()
{
	int maxDenominator = 0;
	cout << "Enter the largest possible denominator: ";
	cin >> maxDenominator;

	compileFareySequence(maxDenominator);

	return 0;
}
