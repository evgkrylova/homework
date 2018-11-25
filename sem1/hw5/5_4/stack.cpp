#include <iostream>
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
	if (stack->first)
	{
		return false;
	}
	return true;
}

void deleteStack(Stack *stack)
{
	double deletingElement = stack->first->element;
	while (stackFirstElement(stack))
	{
		deletingElement = pop(stack);
	}
	delete stack;
}

double stackFirstElement(Stack *stack)
{
	if (isStackEmpty(stack))
	{
		return 0;
	}
	return stack->first->element;
}

void printStack(Stack *stack)
{
	StackElement *current = stack->first;
	while (current)
	{
		StackElement *nextElement = current->next;
		std::cout << current->element;
		current = nextElement;
	}
}

