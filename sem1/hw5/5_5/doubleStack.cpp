#include <iostream>
#include <string.h>
#include "doubleStack.h"

DoubleStack *createDoubleStack()
{
	return new DoubleStack{ nullptr };
}

void pushDoubleStack(DoubleStack *stack, double x)
{
	stack->first = new DoubleStackElement{ x, stack->first };
}

double popDoubleStack(DoubleStack *stack)
{
	if (isDoubleStackEmpty(stack))
	{
		return 0;
	}

	double result = stack->first->element;
	DoubleStackElement *tempElement = stack->first->next;
	delete stack->first;
	stack->first = tempElement;

	return result;
}

bool isDoubleStackEmpty(DoubleStack *stack)
{
	return !stack->first;
}

void deleteDoubleStack(DoubleStack *stack)
{
	double deletingElement = stack->first->element;

	while (topDoubleStack(stack))
	{
		deletingElement = popDoubleStack(stack);
	}

	delete stack;
}

double topDoubleStack(DoubleStack *stack)
{
	if (isDoubleStackEmpty(stack))
	{
		return 0;
	}

	return stack->first->element;
}

void printDoubleStack(DoubleStack *stack)
{
	DoubleStackElement *current = stack->first;

	while (current)
	{
		DoubleStackElement *nextElement = current->next;
		std::cout << current->element;
		current = nextElement;
	}
}

