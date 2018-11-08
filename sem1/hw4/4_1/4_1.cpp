#include <iostream>
#include "list.h"

using namespace std;

int lastOfSicarii(CyclicList *list, int member)
{
	int indexForKilling = (member - 1) % sizeOfCyclicList(list);
	while (sizeOfCyclicList(list) > 1)
	{
		deleteFromCyclicList(list, indexForKilling);
		indexForKilling = (indexForKilling + member - 1) % sizeOfCyclicList(list);
	}
	return list->first->value;
}


int main()
{
	int number = 0;
	cout << "Enter how many warriors are in a circle: ";
	cin >> number;

	CyclicList *list = createCyclicList();
	fillWithConsecutiveNumbers(list, number);

	int member = 0;
	cout << "Enter the number of victim at each step: ";
	cin >> member;

	cout << "Number of the last alive warrior: " << lastOfSicarii(list, member);

	deleteCyclicList(list);

	return 0;
}

