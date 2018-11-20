#include "list.h"

CircularList *createCircularList()
{
	return new CircularList{ 0, nullptr, nullptr };
}

void addToCircularList(CircularList *list, int x)
{
	CircularListElement *newElement = new CircularListElement{ x, list->first };
	if (list->first == nullptr)
	{
		list->first = newElement;
		list->last = list->first;
		list->size++;
		return;
	}
	list->last->next = newElement;
	list->last = newElement;
	list->size++;
}

void fillWithConsecutiveNumbers(CircularList *list, int n)
{
	for (int i = 1; i <= n; i++)
	{
		addToCircularList(list, i);
	}
}

int getElementValue(CircularList *list, int index)
{
	CircularListElement *current = list->first;
	int count = 0;
	if (index >= list->size)
	{
		return -1;
	}
	for (int i = 1; i <= index; i++)
	{
		current = current->next;
	}
	return current->value;
}

int sizeOfCircularList(CircularList *list)
{
	return list->size;
}

void deleteFromCircularList(CircularList *list, int index)
{
	if (index == 0)
	{
		CircularListElement *current = list->first;
		list->last->next = current->next;
		list->first = current->next;
		delete current;
		list->size--;
		return;
	}
	CircularListElement *current = list->first;
	for (int i = 1; i < index; i++)
	{
		current = current->next;
	}
	CircularListElement *deletingElement = current->next;
	current->next = deletingElement->next;
	delete deletingElement;
	list->size--;
}

void deleteCircularList(CircularList *list)
{
	CircularListElement *current = list->first;
	for (int i = 0; i < list->size - 1; i++)
	{
		CircularListElement *nextElement = current->next;
		delete current;
		current = nextElement;
	}
	delete current;
	delete list;
}

