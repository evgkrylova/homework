#include "stdafx.h"
#include <iostream>

using namespace std;

void buildingHeap(int *numbers, int root, int bottom)
{
	int maxChild;
	bool isReady = false;
	while ((root * 2 <= bottom) && (not isReady))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[maxChild];
			numbers[maxChild] = numbers[root];
			numbers[root] = temp;
			root = maxChild;
		}
		else
			isReady = true;
	}
}

void heapSort(int *numbers, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		buildingHeap(numbers, i, size - 1);
	for (int i = size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		buildingHeap(numbers, 0, i - 1);
	}
}

int length(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

int main()
{
	char firstString[100000];
	cout << "Enter the first string: ";
	cin >> firstString;

	char secondString[100000];
	cout << "Enter the second string: ";
	cin >> secondString;

	int firstLength = length(firstString);
	int secondLength = length(secondString);

	if (firstLength != secondLength)
	{
		cout << "These stings are not anagrams.";
	}
	else
	{
		int* firstList = new int[firstLength];
		for (int i = 0; i < firstLength; i++)
		{
			firstList[i] = (int)(firstString[i]);
		}

		int* secondList = new int[secondLength];
		for (int i = 0; i < secondLength; i++)
		{
			secondList[i] = (int)(secondString[i]);
		}

		heapSort(firstList, firstLength);
		heapSort(secondList, secondLength);

		int i = 0;
		while ((firstList[i] == secondList[i]) && (i < firstLength))
		{
			i++;
		}

		if (i == firstLength)
		{
			cout << "These stings are anagrams.";
		}
		else
		{
			cout << "These stings are not anagrams.";
		}

		delete firstList;
		delete secondList;
	}

	return 0;
}
