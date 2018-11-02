#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;

	int* list = new int[size];;
	cout << "Enter elements of the list: ";
	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}

	quickSort(list, 0, size - 1);

	int i = size - 1;
	while ((i > 0) && (list[i] != list[i - 1]))
	{
		i--;
	}

	if ((i == 0) && (list[i] != list[i + 1]))
	{
		cout << "All elements are unique.";
	}
	else
	{
		cout << "The largest not unique element is " << list[i] << ".";
	}

	delete[] list;

	return 0;
}
