#pragma once

struct CyclicListElement {
	int value;
	CyclicListElement *next;
};

struct CyclicList {
	int size;
	CyclicListElement *first;
	CyclicListElement *last;

};

CyclicList *createCyclicList();
void deleteCyclicList(CyclicList *list);

void addToCyclicList(CyclicList *list, int x);
void deleteFromCyclicList(CyclicList *list, int index);
void fillWithConsecutiveNumbers(CyclicList *list, int n);
int getElement(CyclicList *list, int index);
int sizeOfCyclicList(CyclicList *list);