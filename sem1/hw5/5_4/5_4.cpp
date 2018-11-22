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

double calculateBasicOperations(double a, double b, char binaryOperator)
{
	switch (binaryOperator)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}

double calculate(char *expression)
{
	Stack *stack = createStack();

	for (int i = 0; i < strlen(expression); i++)
	{
		char currentElement = expression[i];
		int code = (int)(currentElement);

		if ((code >= (int)('0')) & (code <= (int)('9')))
		{
			double addingElement = (int)(currentElement) - (int)('0');
			push(stack, addingElement);
		}

		else if (isBinaryOperator(currentElement))
		{
			double secondOperand = pop(stack);
			double firstOperand = pop(stack);
			push(stack, calculateBasicOperations(firstOperand, secondOperand, currentElement));
		}
	}

	return stackFirstElement(stack);
}

int main()
{
	int const maxLength = 1000;
	char *expression = new char[maxLength];
	cout << "Enter the expression you want to calculate.\n";
	cout << "Please, do not use the spaces.\n";
	cin >> expression;
	cout << endl;

	cout << "This expression equals: " << calculate(expression);

	delete[] expression;

	return 0;
}
