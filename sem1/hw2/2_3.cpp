#include <iostream>

using namespace std;

struct fraction_t
{
	int numerator;
	int denominator;
};

void compileFareySequence(int n)
{
	cout << "There are all simple irreducible conforming fractions: " << "\n";

	fraction_t first_fraction{ 0, 1 };
	fraction_t second_fraction{ 1, n };

	cout << first_fraction.numerator << "/" << first_fraction.denominator << "\n";

	while (second_fraction.numerator <= n)
	{
		int factor = (n + first_fraction.denominator) / second_fraction.denominator;
		fraction_t temp_fraction{ first_fraction.numerator, first_fraction.denominator };
		first_fraction.numerator = second_fraction.numerator;
		first_fraction.denominator = second_fraction.denominator;
		second_fraction.numerator = second_fraction.numerator * factor - temp_fraction.numerator;
		second_fraction.denominator = second_fraction.denominator * factor - temp_fraction.denominator;

		cout << first_fraction.numerator << "/" << first_fraction.denominator << "\n";
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
