#include <iostream>
#include "list.h"

List *createList()
{
	return new List{ nullptr, nullptr };
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

	if (list->first == nullptr)
	{
		list->first = new ListElement{ x, list->first };
		return;
	}

	while (current->next)
	{
		current = current->next;
	}
	ListElement *newElement = new ListElement{ x, current->next };
	current->next = newElement;
}

int getValue(List *list, int index)
{
	ListElement *current = list->first;

	if (index >= size(list))
	{
		return -1;
	}

	for (int i = 1; i <= index; i++)
	{
		current = current->next;
	}

	return current->value;
}

void deleteArrayOfArrays(int **&array, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] array[i];
	}

	delete[] array;
}
