#include <iostream>
#include "list.h"

List *createList()
{
	return new List{ 0, nullptr };
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
	return list->size;
}

void addToHead(List *list, int x)
{
	ListElement *newElement = new ListElement{ x, list->first };
	list->first = newElement;
	list->size++;
}

void addToTail(List *list, int x)
{
	ListElement *current = list->first;

	if (list->first == nullptr)
	{
		list->first = new ListElement{ x, list->first };
		list->size++;
		return;
	}

	while (current->next)
	{
		current = current->next;
	}
	ListElement *newElement = new ListElement{ x, current->next };
	current->next = newElement;

	list->size++;
}

int getValue(List *list, int index)
{
	ListElement *current = list->first;
	int length = size(list);

	if (index >= length)
	{
		return -1;
	}

	for (int i = 1; i < length - index; i++)
	{
		current = current->next;
	}

	return current->value;
}

void sortList(List *list)
{
	if (!list->first)
	{
		return;
	}
	int size = list->size;

	ListElement *startElement = list->first;
	ListElement *prevoiusForStart = list->first;

	for (int i = 1; i < size; i++)
	{
		ListElement *currentElement = startElement;
		ListElement *minimalElement = startElement;
		ListElement *prevoiusForCurrent = startElement;
		ListElement *prevoiusForMinimal = startElement;

		for (int j = i; j <= size; j++)
		{
			if (minimalElement->value > currentElement->value)
			{
				prevoiusForMinimal = prevoiusForCurrent;
				minimalElement = currentElement;
			}
			prevoiusForCurrent = currentElement;
			currentElement = currentElement->next;
		}

		if (minimalElement != startElement)
		{
			if (minimalElement == startElement->next)
			{
				ListElement *temp = minimalElement->next;
				minimalElement->next = startElement;
				startElement->next = temp;
				prevoiusForStart->next = minimalElement;
			}
			
			else
			{
				ListElement *temp = minimalElement->next;
				minimalElement->next = startElement->next;
				startElement->next = temp;

				temp = prevoiusForMinimal->next;

				if (i == 1)
				{
					prevoiusForMinimal->next = list->first;
					list->first = temp;
				}
				else
				{
					prevoiusForMinimal->next = prevoiusForStart->next;
					prevoiusForStart->next = temp;
				}
			}
		}

		prevoiusForStart = minimalElement;
		startElement = minimalElement->next;
	}
}

