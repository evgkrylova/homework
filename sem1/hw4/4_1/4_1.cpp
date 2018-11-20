#include <iostream>
#include "list.h"

using namespace std;

int lastOfSicarii(CircularList *list, int member)
{
	int indexForKilling = 0;
	do
	{
		indexForKilling = (indexForKilling + member - 1) % sizeOfCircularList(list);
		deleteFromCircularList(list, indexForKilling);
	} 
	while (sizeOfCircularList(list) > 1);
	return getElementValue(list, 0);
}


int main()
{
	int number = 0;
	cout << "Enter how many warriors are in a circle: ";
	cin >> number;

	CircularList *list = createCircularList();
	fillWithConsecutiveNumbers(list, number);

	int member = 0;
	cout << "Enter the number of victim at each step: ";
	cin >> member;

	cout << "Number of the last alive warrior: " << lastOfSicarii(list, member);

	deleteCircularList(list);

	return 0;
}

