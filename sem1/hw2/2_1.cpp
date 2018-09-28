#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
	int rememberedValue = *y;
	*y = *x;
	*x = rememberedValue;
}

int recursiveFibonacci(int x)
{
	if (x == 1)
	{
		return 0;
	}
	else if (x == 2)
	{
		return 1;
	}
	else
	{
		return (recursiveFibonacci(x - 1) + recursiveFibonacci(x - 2));
	}
}

int iterativeFibonacci(int x)
{
	if (x == 1)
	{
		return 0;
	}
	else if (x == 2)
	{
		return 1;
	}
	else
	{
		int previousNumber = 0;
		int currentNumber = 1;
		for (int i = 3; i <= x; i++)
		{
			previousNumber += currentNumber;
			swap(previousNumber, currentNumber);
		}
		return currentNumber;
	}

}

int main()
{
	int number;
	cout << "Enter the number of the Fibonacci sequence element: ";
	cin >> number;

	cout << "Factorial calculated result: " << recursiveFibonacci(number) << endl;
	cout << "Factorial calculated result: " << iterativeFibonacci(number);

	return 0;
}
