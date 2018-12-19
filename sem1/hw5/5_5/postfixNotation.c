#pragma once
#include "charStack.h"

bool isBinaryOperator(char c);
int priority(char c);

int lengthWithoutBrackets(char *expression);

char *shuntingYard(char *expression);
