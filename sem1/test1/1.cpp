#include "stdafx.h"
#include <time.h>
#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
	int rememberedValue = *y;
	*y = *x;
	*x = rememberedValue;
}

void insertionSort(int *numbers, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while ((j > 0) && (numbers[j] < numbers[j - 1]))
		{
			swap(numbers[j], numbers[j - 1]);
			j--;
		}
	}
}

int main()
{
	cout << "Enter 0 if you want to set the list by yourself and \nenter 1 if you want to sort a random list: ";
	int choice = 0;
	cin >> choice;

	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;
	int  amountOfEven = (size + 1) / 2;
	int* list = new int[size];
	int* evenElements = new int[amountOfEven];

	if (choice == 0)
	{
		cout << "Enter elements of the list: \n";
		for (int i = 0; i < size; i++)
		{
			cin >> list[i];
			if (i % 2 == 0)
			{
				evenElements[i / 2] = list[i];
			}
		}
	}
	else
	{
		cout << "Generated list of random numbers in line segment [11, 42]: \n";
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			list[i] = rand() % 32 + 11;
			cout << list[i] << " ";
			if (i % 2 == 0)
			{
				evenElements[i / 2] = list[i];
			}
		}
		cout << "\n";
	}

	insertionSort(evenElements, amountOfEven);

	cout << "Sorted version of this list: \n";

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			cout << evenElements[i / 2] << " ";
		}
		else
		{
			cout << list[i] << " ";
		}
	}

	delete list;
	delete evenElements;

	return 0;
}


