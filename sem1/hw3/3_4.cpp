#include "stdafx.h"
#include <time.h>
#include <iostream>

using namespace std;

bool isInList(int list[], int element, int lengthOfList)
{
	for (int i = 0; i < lengthOfList; i++)
	{
		if (list[i] == element)
		{
			return true;
		}
	}
	return false;
}

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

void bullAndCowsStep(int tried[], int wished[], int length, int &doneSteps, bool &isFinished)
{
	int bulls = 0;
	int cows = 0;
	for (int i = 0; i < length; i++)
	{
		if (tried[i] == wished[i])
		{
			bulls++;
		}
		else if (isInList(wished, tried[i], length))
		{
			cows++;
		}
	}
	doneSteps++;
	if (bulls == length)
	{

		cout << "You won! It takes you " << doneSteps;
		if (doneSteps != 1)
		{
			cout << " tries.";
		}
		else
		{
			cout << " try.";
		}
		isFinished = true;
	}
	else
	{
		cout << "There are " << bulls << " bulls and " << cows << " cows. \nTry again: ";
	}
}


int main()
{
	srand(time(0));
	cout << "Hello! It's the game called 'Bulls and cows'.\n";
	cout << "How many digits do you want it will be in the secret number? \nEnter the value: ";
	int size = 0;
	cin >> size;

	int *number = new int[size];

	for (int i = 0; i < size; i++)
	{
		number[i] = -1;
	}
	number[0] = rand() % 9 + 1;

	for (int i = 1; i < size; i++)
	{
		int digit = rand() % 10;
		while (isInList(number, digit, size))
		{
			digit = (rand() % 10);
		}
		number[i] = digit;
	}

	cout << "Let's start! \nTry to guess the number. Enter your version: ";

	bool isGuessedCorrectly = false;
	int *trying = new int[size];
	int steps = 0;
	int tryingAsNumber = 0;

	while (isGuessedCorrectly == false)
	{
		cin >> tryingAsNumber;
		for (int i = 0; i < size; i++)
		{
			trying[i] = tryingAsNumber / exponentiating(10, size - 1 - i);
			tryingAsNumber = tryingAsNumber % exponentiating(10, size - 1 - i);
		}

		bullAndCowsStep(trying, number, size, steps, isGuessedCorrectly);
	}

	delete number;
	delete trying;

	return 0;
}
