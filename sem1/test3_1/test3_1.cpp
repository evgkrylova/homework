#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List *list = createList();
	cout << "Enter the elements and 0 when you want to exit: ";
	cout << endl;
	int currentValue = 0;
	cin >> currentValue;
	if (currentValue)
	{
		do 
		{
			add(list, currentValue);
			cin >> currentValue;
		} 
		while (currentValue);
	}
	
	sortList(list);
	print(list);
	deleteList(list);

	return 0;
}


