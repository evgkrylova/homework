#pragma once

struct StackElement
{
	char element;
	StackElement *next;
};

struct Stack
{
	StackElement *first;
};

Stack *createStack();
void deleteStack(Stack *stack);

void push(Stack *stack, char c);
bool isStackEmpty(Stack *stack);
char top(Stack *stack);
char pop(Stack *stack);

void printStack(Stack *stack); 
