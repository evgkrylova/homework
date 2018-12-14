#include <iostream>
#include "list.h"

using namespace std;

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
		addToTail(list, currentValue);
	}

	sortList(list);
	cout << "Sorted version of this list: ";
	print(list);
	deleteList(list);

	return 0;
}

