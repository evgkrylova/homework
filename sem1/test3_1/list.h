#pragma once

using namespace std;

struct ListElement {
	int value;
	int amount;
	ListElement *next;
};

struct List {
	int size;
	ListElement *first;
};

List *createList();
void deleteList(List *list);

void add(List *list, int value);
void print(List *list);
int getValue(List *list, int index);
void sortList(List *list);

int size(List *list);
