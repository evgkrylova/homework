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

int size(List *list);
