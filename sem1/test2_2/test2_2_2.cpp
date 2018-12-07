#include <iostream>
#include "list.h"

using namespace std;

void insertionSort(List *list)
{
	int length = size(list);
	for (int i = 1; i < length; i++)
	{
		int j = i;
		while ((j > 0) && (getValue(list, j) < getValue(list, j - 1)))
		{
			swapValues(list, j, j - 1);
			j--;
		}
	}
}

int main()
{
	List *list = createList();
	int size = 0;
	cout << "Enter the number of elements in the list: ";
	cin >> size;

	cout << "Enter the elements: ";
	for (int i = 0; i < size; i++)
	{
		int currentValue = 0;
		cin >> currentValue;
		add(list, currentValue);
	}
		
	insertionSort(list);
	cout << "Sorted version of this list: ";
	print(list);

	deleteList(list);
	return 0;
}

