#pragma once

struct CircularListElement {
	int value;
	CircularListElement *next;
};

struct CircularList {
	int size;
	CircularListElement *first;
	CircularListElement *last;

};

CircularList *createCircularList();
void deleteCircularList(CircularList *list);

void addToCircularList(CircularList *list, int x);
void deleteFromCircularList(CircularList *list, int index);
void fillWithConsecutiveNumbers(CircularList *list, int n);
int getElementValue(CircularList *list, int index);
int sizeOfCircularList(CircularList *list);
