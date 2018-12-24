#include <iostream>
#include "doubleStack.h"
#include "postfixNotation.h"

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

double calculate(char *expression, int length)
{
	DoubleStack *stack = createDoubleStack();

	for (int i = 0; i < length; i++)
	{
		char currentElement = expression[i];

		if (isdigit(currentElement))
		{
			double addingElement = currentElement - '0';
			pushDoubleStack(stack, addingElement);
		}

		else if (isBinaryOperator(currentElement))
		{
			double secondOperand = popDoubleStack(stack);
			double firstOperand = popDoubleStack(stack);
			pushDoubleStack(stack, calculateBasicOperations(firstOperand, secondOperand, currentElement));
		}
	}

	double result = topDoubleStack(stack);
	deleteDoubleStack(stack);
	return result;
}
