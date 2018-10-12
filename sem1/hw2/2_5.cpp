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

int main()
{
	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;

	int list[100000];
	cout << "Enter elements of the list: ";
	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}

	heapSort(list, size);

	cout << "Sorted version of this list: ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	return 0;
}
