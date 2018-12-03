#include <iostream>
#include "string.h"
#include "stack.h"

Stack *createStack()
{
	return new Stack{ nullptr };
}

void push(Stack *stack, double x)
{
	StackElement *newElement = new StackElement{ x, stack->first };
	stack->first = newElement;
}

double pop(Stack *stack)
{
	if (isStackEmpty(stack))
	{
		return 0;
	}

	double result = stack->first->element;
	StackElement *tempElement = stack->first->next;
	delete stack->first;
	stack->first = tempElement;

	return result;
}

bool isStackEmpty(Stack *stack)
{
	return !stack->first;
}

void deleteStack(Stack *stack)
{
	StackElement *current = stack->first;
	while (current)
	{
		StackElement *nextElement = current->next;
		delete current;
		current = nextElement;
	}
	delete stack;
}

double top(Stack *stack)
{
	if (isStackEmpty(stack))
	{
		return 0;
	}
	return stack->first->element;
}

void printStack(Stack *stack)
{
	while (top(stack))
	{
		std::cout << pop(stack);
	}
}

