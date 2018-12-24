#pragma once

struct CharStackElement
{
	char element;
	CharStackElement *next;
};

struct CharStack
{
	CharStackElement *first;
};

CharStack *createCharStack();
void deleteCharStack(CharStack *stack);

void pushCharStack(CharStack *stack, char c);
bool isCharStackEmpty(CharStack *stack);
char topCharStack(CharStack *stack);
char popCharStack(CharStack *stack);

void printCharStack(CharStack *stack);
char *convertCharStackToArray(CharStack *stack);

int sizeCharStack(CharStack *stack);
