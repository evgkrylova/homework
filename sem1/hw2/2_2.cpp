#include "stdafx.h"
#include <iostream>

using namespace std;

void sumView(int sum, int summands[], int index, int originalNumber)
{
	int lastSummand = sum;

	if (sum == 0)
	{
		cout << originalNumber << " = ";
		for (int i = 0; i < index - 1; i++)
		{
			cout << summands[i] << " + ";
		}
		cout << summands[index - 1] << "\n";
	}
	else
	{
		if ((index > 0) && (lastSummand > summands[index - 1]))
		{
			lastSummand = summands[index - 1];
		}
		for (int i = 1; i <= lastSummand; i++)
		{
			summands[index] = i;
			sumView(sum - i, summands, index + 1, originalNumber);
		}
	}
}

int main()
{
	int number = 0;
	cout << "Enter the number: ";
	cin >> number;

	cout << "There is this number expressed as the all possible sums: " << "\n";

	int* addends = new int[number];
	int const startIndex = 0;
	sumView(number, addends, startIndex, number);

	delete addends;

	return 0;
}
