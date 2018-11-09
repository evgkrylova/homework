#pragma once

struct ListElement {
	char *name;
	char *number;
	ListElement *next;
};

struct List {
	ListElement *first;
};

List *createList();
void deleteList(List *list);

void addToList(List *list, char *name, char *number);
int listSize(List *list);

char *getNameByIndex(List *list, int index);
char *getNumberByIndex(List *list, int index);
char *getNumberByName(List *list, char *name);
char *getNameByNumber(List *list, char *number);

bool isStringsEquivalent(char *first, char *second);
