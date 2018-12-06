#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

bool isBinaryOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
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
	
	int length = strlen(expression);
	for (int i = 0; i < length; i++)
	{
		char currentElement = expression[i];

		if (isdigit(currentElement))
		{
			double addingElement = currentElement - '0';
			push(stack, addingElement);
		}

		else if (isBinaryOperator(currentElement))
		{
			double secondOperand = pop(stack);
			double firstOperand = pop(stack);
			push(stack, calculateBasicOperations(firstOperand, secondOperand, currentElement));
		}
	}

	return top(stack);
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

