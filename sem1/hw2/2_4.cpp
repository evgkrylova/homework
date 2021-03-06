#include "stdafx.h"
#include <iostream>

using namespace std;

void quickSort(int *numbers, int left, int right)
{
	int comparing;
	int leftHold = left;
	int rightHold = right;
	comparing = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= comparing) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= comparing) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}

	numbers[left] = comparing;
	comparing = left;
	left = leftHold;
	right = rightHold;
	if (left < comparing)
		quickSort(numbers, left, comparing - 1);
	if (right > comparing)
		quickSort(numbers, comparing + 1, right);
}

int lengthOfNumber(int x)
{
	int result = 0;
	while (x / 10 > 0)
	{
		result++;
		x = x / 10;
	}
	return result + 1;
}

int main()
{
	int number = 0;
	cout << "Enter the number: ";
	cin >> number;

	int numberForWork = number;
	int digits[10000];
	int length = lengthOfNumber(number);
	int index = 0;

	for (int i = 0; i < length; i++)
	{
		digits[i] = numberForWork % 10;
		numberForWork = numberForWork / 10;
	}

	quickSort(digits, 0, length - 1);

	cout << "There is the least number from this number's digits: ";

	for (int i = 0; i < length; i++)
	{
		cout << digits[i];
	}

	return 0;
}
