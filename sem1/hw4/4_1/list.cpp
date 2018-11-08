#include "list.h"

CyclicList *createCyclicList()
{
	return new CyclicList{ 0, nullptr, nullptr };
}

void addToCyclicList(CyclicList *list, int x)
{
	CyclicListElement *newElement = new CyclicListElement{ x, list->first };
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

void fillWithConsecutiveNumbers(CyclicList *list, int n)
{
	for (int i = 1; i <= n; i++)
	{
		addToCyclicList(list, i);
	}
}

int getElement(CyclicList *list, int index)
{
	CyclicListElement *current = list->first;
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

int sizeOfCyclicList(CyclicList *list)
{
	return list->size;
}

void deleteFromCyclicList(CyclicList *list, int index)
{
	if (index == 0)
	{
		list->last->next = list->first->next;
		list->first = list->first->next;
		list->size--;
		return;
	}
	CyclicListElement *current = list->first;
	for (int i = 1; i < index; i++)
	{
		current = current->next;
	}
	CyclicListElement *deletingElement = current->next;
	current->next = deletingElement->next;
	list->size--;
}

void deleteCyclicList(CyclicList *list)
{
	CyclicListElement *current = list->first;
	for (int i = 0; i < list->size - 1; i++)
	{
		CyclicListElement *nextElement = current->next;
		delete current;
		current = nextElement;
	}
	delete current;
	delete list;
}

