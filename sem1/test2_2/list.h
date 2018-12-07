#pragma once

using namespace std;

struct ListElement {
	int value;
	ListElement *next;
};

struct List {
	ListElement *first;
};

List *createList();
void deleteList(List *list);

void add(List *list, int value);
void print(List *list);
int getValue(List *list, int index);
void swapValues(List *list, int firstIndex, int secondIndex);

int size(List *list);
