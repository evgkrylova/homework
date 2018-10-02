#include <iostream>

using namespace std;

int exponentiating(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2)
	{
		return x * exponentiating(x, n - 1);
	}
	return exponentiating(x, n / 2) * exponentiating(x, n / 2);
}

int mass(int n)
{
	int* a = new int[5];

	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	return *a;
}

int main()
{
	int number = 1;
	cout << "Enter the base (b): ";
	cin >> number;

	int exponent = 0;
	cout << "Enter the exponent (n): ";
	cin >> exponent;

	cout << "The result of exponentiation (b^n): " << exponentiating(number, exponent);

	return 0;
}
