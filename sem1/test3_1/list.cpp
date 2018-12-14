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
		std::cout << "Element " << current->value << ": " << current->amount << " times.";
		std::cout << std::endl;
		current = current->next;
	}
}

int size(List *list)
{
	return list->size;
}

bool areEqual(ListElement *current, int x)
{
	return current->value == x;
}

void increaseAmount(ListElement *current, int x)
{
	if (areEqual(current, x))
	{
		current->amount++;
		return;
	}
}

void add(List *list, int x)
{
	ListElement *current = list->first;

	if (list->first == nullptr || current->value > x)
	{
		list->first = new ListElement{ x, 1, list->first };
		list->size++;
		return;
	}
	
	while (current->next && current->value <= x)
	{
		increaseAmount(current, x);
		if (areEqual(current, x))
		{
			return;
		}
		current = current->next;
	}

	if (!areEqual(current, x))
	{
		ListElement *newElement = new ListElement{ x, 1, current->next };
		current->next = newElement;
		list->size++;
	}

	current->amount++;
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

