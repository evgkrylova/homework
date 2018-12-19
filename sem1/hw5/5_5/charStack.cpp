#include <iostream>
#include "charStack.h"

CharStack *createCharStack()
{
	return new CharStack{ nullptr };
}

void pushCharStack(CharStack *stack, char c)
{
	CharStackElement *newElement = new CharStackElement{ c, stack->first };
	stack->first = newElement;
}

char popCharStack(CharStack *stack)
{
	if (isCharStackEmpty(stack))
	{
		return '\0';
	}

	char result = stack->first->element;
	CharStackElement *tempElement = stack->first->next;
	delete stack->first;
	stack->first = tempElement;

	return result;
}

bool isCharStackEmpty(CharStack *stack)
{
	return !stack->first;
}

void deleteCharStack(CharStack *stack)
{
	char deletingElement = stack->first->element;

	while (topCharStack(stack))
	{
		deletingElement = popCharStack(stack);
	}

	delete stack;
}

char topCharStack(CharStack *stack)
{
	if (isCharStackEmpty(stack))
	{
		return '\0';
	}

	return stack->first->element;
}

void printCharStack(CharStack *stack)
{
	CharStackElement *current = stack->first;

	while (current)
	{
		CharStackElement *nextElement = current->next;
		std::cout << current->element;
		current = nextElement;
	}
}

int sizeCharStack(CharStack *stack)
{
	CharStackElement *current = stack->first;
	int count = 0;

	while (current)
	{
		CharStackElement *nextElement = current->next;
		count++;
		current = nextElement;
	}

	return count;
}

char *convertCharStackToArray(CharStack *stack)
{
	CharStackElement *current = stack->first;
	char *resultedString = new char[sizeCharStack(stack)];
	int index = 0;

	while (current)
	{
		CharStackElement *nextElement = current->next;
		resultedString[index++] = current->element;
		current = nextElement;
	}

	return resultedString;
}

