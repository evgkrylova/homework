#pragma once
#include "binarySearchTree.h"

struct Set
{
	BinaryTree *body;
};

Set *createSet();
void deleteSet(Set *&set);

void addValueToSet(Set *set);
void removeValueFromSet(Set *set);
void checkIsValueInSet(Set *set);
void printSetInAscendingOrder(Set *set);
void printSetInDescendingOrder(Set *set);
void printAsTree(Set *set);
