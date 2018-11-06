#include <iostream>

using namespace std;

void buildHeap(int *numbers, int root, int lowestRow)
{
	bool isReady = false;
	int maxChild = 0;
	int leftChild = root * 2;
	int rightChild = root * 2 + 1;
	while ((leftChild <= lowestRow - 1) && (!isReady))
	{
		if ((leftChild == lowestRow - 1) || (numbers[leftChild] > numbers[rightChild]))
		{
			maxChild = leftChild;
		}
		else
		{
			maxChild = rightChild;
		}

		if (numbers[root] < numbers[maxChild])
		{
			swap(numbers[maxChild], numbers[root]);
			root = maxChild;
			leftChild = root * 2;
			rightChild = root * 2 + 1;
		}
		else
		{
			isReady = true;
		}
	}
}

void heapSort(int *numbers, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		buildHeap(numbers, i, size);
	}
	for (int i = size - 1; i >= 1; i--)
	{
		swap(numbers[0], numbers[i]);
		buildHeap(numbers, 0, i);
	}
}

void swap(int &x, int &y)
{
	int temp = y;
	y = x;
	x = temp;
}

int main()
{
	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;

	int* list = new int[size];
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

	delete[] list;

	return 0;
}
