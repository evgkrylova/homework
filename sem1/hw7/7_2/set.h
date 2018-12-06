#pragma once
#include "AVLTree.h"

struct Set
{
	AVLTree *body;
};

Set *createSet();
void deleteSet(Set *&set);

void addValueToSet(Set *set);
void removeValueFromSet(Set *set);
void checkIsValueInSet(Set *set);
void printSetInAscendingOrder(Set *set);
void printSetInDescendingOrder(Set *set);
void printAsTree(Set *set);
