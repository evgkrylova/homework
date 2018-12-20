#include <iostream>
#include "list.h"

List *createList()
{
	return new List{ nullptr };
}

void deleteList(List *list)
{
	ListElement *current = list->first;

	while (current)
	{
		ListElement *nextElement = current->next;
		delete current;
		current = nextElement;
	}

	delete list;
	list = nullptr;
}

void print(List *list)
{
	ListElement *current = list->first;

	while (current)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
}

int size(List *list)
{
	ListElement *current = list->first;
	int length = 0;

	while (current)
	{
		length++;
		current = current->next;
	}

	return length;
}

void add(List *list, int x)
{
	ListElement *current = list->first;

	if ((list->first == nullptr) || (current->value > x))
	{
		list->first = new ListElement{ x, list->first };
		return;
	}

	while ((current->next) && (current->next->value > x))
	{
		current = current->next;
	}

	current->next = new ListElement{ x, current->next };
}

