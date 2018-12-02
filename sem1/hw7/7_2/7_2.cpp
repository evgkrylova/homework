#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
	cout << "Hello. This programme works with data structures called 'Binery Search Tree'.\n";
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

	AVLTree *tree = createAVLTree();

	while (choice != 0)
	{
		int value = 0;

		if (choice == 1)
		{
			cout << "Enter the value you want to add: ";
			cin >> value;
			addValueToTree(tree, value);
		}

		else if (choice == 2)
		{
			cout << "Enter the value you want to remove: ";
			cin >> value;
			if (!isValueInTree(tree, value))
			{
				cout << "There is no this value in the tree.\n";
			}
			else
			{
				deleteValueFromTree(tree, value);
			}
		}

		else if (choice == 3)
		{
			cout << "Enter the value to check: ";
			cin >> value;
			if (!isValueInTree(tree, value))
			{
				cout << "There is no this value in the tree.\n";
			}
			else
			{
				cout << "There is such value in the tree.\n";
			}
		}

		else if (choice == 4)
		{
			if (isTreeEmpty(tree))
			{
				cout << "The tree is empty.\n";
			}
			else
			{
				printTreeInAscendingOrder(tree);
			}
		}

		else if (choice == 5)
		{
			if (isTreeEmpty(tree))
			{
				cout << "The tree is empty.\n";
			}
			else
			{
				printTreeInDescendingOrder(tree);
			}
		}

		else if (choice == 6)
		{
			if (isTreeEmpty(tree))
			{
				cout << "The tree is empty.\n";
			}
			else
			{
				printAsTree(tree);
			}
		}

		else
		{
			cout << "There is no such command.\n";
		}

		cout << "The process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deleteTree(tree);
	return 0;
}

