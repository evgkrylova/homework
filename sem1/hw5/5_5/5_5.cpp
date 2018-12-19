#include <iostream>
#include <string.h>
#include "doubleStack.h"
#include "charStack.h"
#include "postfixNotation.h"
#include "calculate.h"

using namespace std;

int main()
{
	int const maxLength = 1000;
	char *expression = new char[maxLength];
	
	cout << "Enter the expression you want to calculate.\n";
	cout << "Please, do not use the spaces.\n";
	cin >> expression;
	cout << endl;

	char *expressionInPostfixNotation = shuntingYard(expression);
	int newLength = lengthWithoutBrackets(expression);

	cout << "This expression equals: " << calculate(expressionInPostfixNotation, newLength);

	delete[] expression;
	delete[] expressionInPostfixNotation;

	return 0;
}

