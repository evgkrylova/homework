#include <iostream>
#include "stack.h"

using namespace std;

bool isBinaryOperator(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
	{
		return true;
	}
	return false;
}

int binaryOperatorPrecedence(char c)
{
	if ((c == '+') || (c == '-'))
	{
		return 0;
	}
	return 1;
}

void shuntingYard(char *expression, Stack *operatorStack)
{
	cout << "Postfix notation of the expression:\n";
	for (int i = 0; i < strlen(expression); i++)
	{
		char currentElement = expression[i];
		int code = (int)(currentElement);

		if ((code >= (int)('0')) & (code <= (int)('9')))
		{
			cout << currentElement;
		}

		else if (currentElement == '(')
		{
			push(operatorStack, currentElement);
		}

		else if (currentElement == ')')
		{
			while (stackFirstElement(operatorStack) != '(')
			{
				cout << pop(operatorStack);
			}
			char deletedBracket = pop(operatorStack);
		}

		else if (isBinaryOperator(currentElement))
		{
			while ((isBinaryOperator(stackFirstElement(operatorStack))) & (binaryOperatorPrecedence(currentElement) <= binaryOperatorPrecedence(stackFirstElement(operatorStack))))
			{
				cout << pop(operatorStack);
			}
			push(operatorStack, currentElement);
		}
	}
	printStack(operatorStack);
}

int main()
{
	int const maxLength = 1000;
	char *expression = new char[maxLength];
	cout << "Enter the expression you want to convert from infix notation to postfix one.\n";
	cout << "Please, do not use the spaces.\n";
	cin >> expression;
	cout << endl;

	Stack *operatorStack = createStack();

	shuntingYard(expression, operatorStack);

	delete[] expression;
	deleteStack(operatorStack);
	return 0;
}
