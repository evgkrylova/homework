#include <iostream>
#include "charStack.h"
#include "doubleStack.h"

bool isBinaryOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int priority(char c)
{
	if ((c == '+') || (c == '-'))
	{
		return 0;
	}
	return 1;
}

int lengthWithoutBrackets(char *expression)
{
	int length = strlen(expression);
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		if ((expression[i] != '(') && (expression[i] != ')'))
		{
			result++;
		}
	}

	return result;
}

char *shuntingYard(char *expression)
{
	CharStack *operatorStack = createCharStack();
	int length = strlen(expression);
	int resultedLength = lengthWithoutBrackets(expression);
	char *resultedString = new char[resultedLength];
	int index = 0;

	for (int i = 0; i < length; i++)
	{
		char currentElement = expression[i];

		if (isdigit(currentElement))
		{
			resultedString[index++] = currentElement;
		}

		else if (currentElement == '(')
		{
			pushCharStack(operatorStack, currentElement);
		}

		else if (currentElement == ')')
		{
			while (topCharStack(operatorStack) != '(')
			{
				resultedString[index++] = popCharStack(operatorStack);
			}
			char deletedBracket = popCharStack(operatorStack);
		}

		else if (isBinaryOperator(currentElement))
		{
			while ((isBinaryOperator(topCharStack(operatorStack))) && (priority(currentElement) <= priority(topCharStack(operatorStack))))
			{
				resultedString[index++] = popCharStack(operatorStack);
			}
			pushCharStack(operatorStack, currentElement);
		}
	}

	char *endOfStack = convertCharStackToArray(operatorStack);
	for (int i = 0; i < sizeCharStack(operatorStack); i++)
	{
		resultedString[index + i] = endOfStack[i];
	}

	deleteCharStack(operatorStack);
	delete[] endOfStack;
	return resultedString;
}
