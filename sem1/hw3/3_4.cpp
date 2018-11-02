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

void bullAndCowsStep(int *tried, int *wished, int &doneSteps, bool &isFinished, int length)
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
		cout << "You won! It takes you " << doneSteps << " tries.";
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
	cout << "How many digits do you want it will be in the wished number? \nEnter the value: ";
	int size = 0;
	cin >> size;

	int *digits = new int[size];

	for (int i = 0; i < size; i++)
	{
		digits[i] = -1;
	}
	digits[0] = rand() % 9 + 1;

	cout << digits[0];

	for (int i = 1; i < size; i++)
	{
		int digit = rand() % 10;
		while (isInList(digits, digit, size))
		{
			digit = (rand() % 10);
		}
		digits[i] = digit;

		cout << digit;
	}

	cout << endl;

	cout << "Let's start! \nTry to guess the number. Enter your version: ";

	bool isGuessedCorrectly = false;
	int *trying = new int[size];
	int number = 0;
	int steps = 0;

	while (isGuessedCorrectly == false)
	{
		cin >> number;
		for (int i = size - 1; i >= 0; i--)
		{
			trying[i] = number % 10;
			number /= 10;
		}
		bullAndCowsStep(trying, digits, steps, isGuessedCorrectly, size);
	}

	delete[] digits;
	delete[] trying;

	return 0;
}
