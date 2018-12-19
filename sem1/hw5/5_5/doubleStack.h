#pragma once

struct DoubleStackElement
{
	double element;
	DoubleStackElement *next;
};

struct DoubleStack
{
	DoubleStackElement *first;
};

DoubleStack *createDoubleStack();
void deleteDoubleStack(DoubleStack *stack);

void pushDoubleStack(DoubleStack *stack, double x);
bool isDoubleStackEmpty(DoubleStack *stack);
double topDoubleStack(DoubleStack *stack);
double popDoubleStack(DoubleStack *stack);

void printDoubleStack(DoubleStack *stack);
