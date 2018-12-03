#pragma once

struct StackElement
{
	double element;
	StackElement *next;
};

struct Stack
{
	StackElement *first;
};

Stack *createStack();
void deleteStack(Stack *stack);

void push(Stack *stack, double x);
bool isStackEmpty(Stack *stack);
double top(Stack *stack);
double pop(Stack *stack);

void printStack(Stack *stack);
