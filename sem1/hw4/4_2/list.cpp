#include <iostream>
#include "string.h"
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
		delete current->name;
		delete current->number;
		delete current;
		current = nextElement;
	}

	delete list;
}

int listSize(List *list)
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

char *getNameByIndex(List *list, int index)
{
	ListElement *current = list->first;
	int counter = 0;
	
	while (current)
	{
		if (counter == index)
		{
			return current->name;
		}
		counter += 1;
		current = current->next;
	}
	
	return '\0';
}

char *getNumberByIndex(List *list, int index)
{
	ListElement *current = list->first;
	int counter = 0;
	
	while (current)
	{
		if (counter == index)
		{
			return current->number;
		}
		counter += 1;
		current = current->next;
	}
	
	return '\0';
}

char *getNumberByName(List *list, char *name)
{
	ListElement *current = list->first;
	
	while (current)
	{
		if (isStringsEquivalent(name, current->name))
		{
			return current->number;
		}
		current = current->next;
	}
	
	return '\0';
}

char *getNameByNumber(List *list, char *number)
{
	ListElement *current = list->first;
	
	while (current)
	{
		if (isStringsEquivalent(number, current->number))
		{
			return current->name;
		}
		current = current->next;
	}
	
	return '\0';
}

void addToList(List *list, char *name, char *number)
{
	ListElement *current = list->first;

	if (list->first == nullptr)
	{
		list->first = new ListElement{ name, number, nullptr };
		return;
	}

	while (current->next)
	{
		current = current->next;
	}

	current->next = new ListElement{ name, number, nullptr };
}

bool isStringsEquivalent(char *first, char *second)
{
	if (strlen(first) != strlen(second))
	{
		return false;
	}

	for (int i = 0; i < strlen(first); i++)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}

	return true;
}

