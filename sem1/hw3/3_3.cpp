#include "stdafx.h"

#include <iostream>

using namespace std;

int length(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

bool isIn(char x, char *y)
{
	for (int i = 0; i < length(y); i++)
	{
		if (x == y[i])
		{
			return true;
		}
	}
	return false;
}

void bullsAndCows(char *wished, char *guessed)
{
	int bulls = 0;
	int cows = 0;

	for (int i = 0; i < length(guessed); i++)
	{
		if (guessed[i] == wished[i])
		{
			bulls++;
		}
		else if (isIn(guessed[i], wished))
		{
			cows++;
		}
	}

	if (bulls == length(guessed))
	{
		cout << "You won! It took you " << tries << " tries.";
	}
	else
	{
		cout << "Answer: " << bulls << " bulls and " << cows << " cows.";
	}

}

void sumView(int n)
{
	if (n == 1)
	{
		char* a = new char['1'];
	}
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
	int* a = new int[3];
	a[0] = 4;
	a[1] = 5;
	a[2] = 29;
	return 0;
}




