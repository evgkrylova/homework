#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	int previousNumber = 0;
	int currentNumber = 1;
	for (int i = 1; i < n; i++)
	{
		currentNumber += previousNumber;
		previousNumber = currentNumber - previousNumber;
	}

	return currentNumber;
}

int main()
{
	int number = 0;
	cout << "Enter the number of the Fibonacci sequence element: ";
	cin >> number;
	cout << "Result: " << fibonacci(number) << endl;

    return 0;
}

