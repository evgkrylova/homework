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

CircularListElement *getElement(CircularList *list, int index)
{
	CircularListElement *current = list->first;
	int count = 0;
	if (index >= list->size)
	{
		return nullptr;
	}
	for (int i = 1; i <= index; i++)
	{
		current = current->next;
	}
	return current;
}

int getValue(CircularList *list, int index)
{
	return getElement(list, index)->value;
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
	CircularListElement *previousElement = getElement(list, index - 1);
	CircularListElement *deletingElement = previousElement->next;
	previousElement->next = deletingElement->next;
	delete deletingElement;
	list->size--;
}

void deleteCircularList(CircularList *list)
{
	for (int i = 0; i < list->size - 1; i++)
	{
		deleteFromCircularList(list, i);
	}
	delete list;
}

