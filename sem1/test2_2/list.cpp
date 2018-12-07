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

ListElement *getElement(List *list, int index)
{
	ListElement *current = list->first;
	if (index >= size(list))
	{
		return nullptr;
	}
	for (int i = 1; i <= index; i++)
	{
		current = current->next;
	}
	return current;
}

void swapValues(List *list, int firstIndex, int secondIndex)
{
	ListElement *firstElement = getElement(list, firstIndex);
	ListElement *secondElement = getElement(list, secondIndex);

	int temp = firstElement->value;
	firstElement->value = secondElement->value;
	secondElement->value = temp;
}

