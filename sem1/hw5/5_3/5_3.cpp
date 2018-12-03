#include <iostream>
#include "stack.h"

using namespace std;

bool isBinaryOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
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

		if (isdigit(currentElement))
		{
			cout << currentElement;
		}

		else if (currentElement == '(')
		{
			push(operatorStack, currentElement);
		}

		else if (currentElement == ')')
		{
			while (top(operatorStack) != '(')
			{
				cout << pop(operatorStack);
			}
			char deletedBracket = pop(operatorStack);
		}

		else if (isBinaryOperator(currentElement))
		{
			while ((isBinaryOperator(top(operatorStack))) && (binaryOperatorPrecedence(currentElement) <= binaryOperatorPrecedence(top(operatorStack))))
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

