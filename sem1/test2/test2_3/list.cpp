#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

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

void print(List *list, ofstream &fout)
{
	ListElement *current = list->first;
	while (current)
	{
		fout << current->value << ' ';
		current = current->next;
	}
}

void add(List *list, int value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = nullptr;

	if (list->first == nullptr)
	{
		list->first = newElement;
		return;
	}

	ListElement *temp = list->first;
	while (temp->next != nullptr)
		temp = temp->next;

	temp->next = newElement;
}

