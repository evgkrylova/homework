#include <iostream>
#include "binarySearchTree.h"
#include "set.h"

using namespace std;

Set *createSet()
{
	return new Set{ createBinaryTree() };
}

void deleteSet(Set *&set)
{
	deleteTree(set->body);
	delete set;
}

void addValueToSet(Set *set)
{
	int value = 0;
	BinaryTree *tree = set->body;
	cout << "Enter the value you want to add: ";
	cin >> value;
	addValueToTree(tree, value);
}

void removeValueFromSet(Set *set)
{
	BinaryTree *tree = set->body;
	int value = 0;
	cout << "Enter the value you want to remove: ";
	cin >> value;
	if (!isValueInTree(tree, value))
	{
		cout << "There is no this value in the set.\n";
		return;
	}
	removeValueFromTree(tree, value);
}

void checkIsValueInSet(Set *set)
{
	BinaryTree *tree = set->body;
	int value = 0;
	cout << "Enter the value to check: ";
	cin >> value;
	if (!isValueInTree(tree, value))
	{
		cout << "There is no this value in the set.\n";
		return;
	}
	cout << "There is such value in the set.\n";
}

void printSetInAscendingOrder(Set *set)
{
	BinaryTree *tree = set->body;
	if (isTreeEmpty(tree))
	{
		cout << "The set is empty.\n";
		return;
	}
	printTreeInAscendingOrder(tree);
}

void printSetInDescendingOrder(Set *set)
{
	BinaryTree *tree = set->body;
	if (isTreeEmpty(tree))
	{
		cout << "The set is empty.\n";
		return;
	}
	printTreeInDescendingOrder(tree);
}

void printAsTree(Set *set)
{
	BinaryTree *tree = set->body;
	if (isTreeEmpty(tree))
	{
		cout << "The set is empty.\n";
		return;
	}
	printTreeInStorageOrder(tree);
}
