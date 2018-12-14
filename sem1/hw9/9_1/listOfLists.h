#pragma once
#include "list.h"

struct ListOfLists{
	List *first;
};

ListOfLists *createListOfLists();
void deleteListOfList(ListOfLists *list);

void addList(ListOfLists *list, List *element);
List *getList(ListOfLists *list, int index);

int sizeListOfLists(ListOfLists *list);
