#include <iostream>
#include "list.h"
#include "listOfLists.h"

ListOfLists *createListOfLists()
{
	return new ListOfLists{ nullptr };
}

void addList(ListOfLists *list, List *element)
{
	List *current = list->first;

	if (!list->first)
	{
		list->first = element;
		return;
	}

	while (current->next)
	{
		current = current->next;
	}

	current->next = element;
}

List *getList(ListOfLists *list, int index)
{
	List *current = list->first;

	if (index >= sizeListOfLists(list))
	{
		return nullptr;
	}

	for (int i = 1; i <= index; i++)
	{
		current = current->next;
	}

	return current;
}

int sizeListOfLists(ListOfLists *list)
{
	List *current = list->first;
	int length = 0;

	while (current)
	{
		length++;
		current = current->next;
	}

	return length;
}

void deleteListOfList(ListOfLists *list)
{
	List *current = list->first;

	while (current)
	{
		List *nextElement = current->next;
		deleteList(current);
		current = nextElement;
	}

	delete list;
}
