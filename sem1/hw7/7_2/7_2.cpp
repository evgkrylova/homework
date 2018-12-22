#include <iostream>
#include "AVLTree.h"
#include "set.h"

using namespace std;

int main()
{
	cout << "Hello. This programme works with data structures called 'AVL tree'.\n";
	cout << "Enter the command if you want:\n\t 0 - to exit;\n";
	cout << "\t 1 - to add a value;\n";
	cout << "\t 2 - to remove an existing value;\n";
	cout << "\t 3 - to know if a value can be found in the tree;\n";
	cout << "\t 4 - to print all existing values in ascending order;\n";
	cout << "\t 5 - to print all existing values in descending order;\n";
	cout << "\t 6 - to print all existing values the way the tree is stored.\n";
	cout << "\nYour command: ";

	int choice = -1;
	cin >> choice;

	Set *set = createSet();

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addValueToSet(set);
			break;
		case 2:
			removeValueFromSet(set);
			break;
		case 3:
			checkIsValueInSet(set);
			break;
		case 4:
			printSetInAscendingOrder(set);
			break;
		case 5:
			printSetInDescendingOrder(set);
			break;
		case 6:
			printAsTree(set);
			break;
		}

		cout << "The process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deleteSet(set);
	return 0;
}

