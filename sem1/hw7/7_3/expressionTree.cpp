#include <iostream>
#include <fstream>
#include "expressionTree.h"

using namespace std;

int convertCharToInt(char c)
{
	return (int)(c)-(int)('0');
}

ExpressionTree *createExpressionTree()
{
	ExpressionTree *newTree = new ExpressionTree;
	newTree->root = nullptr;
	return newTree;
}

void deleteNode(ExpressionTreeNode *&node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteNode(node->leftChild);
	deleteNode(node->rightChild);

	delete node;
}

void deleteTree(ExpressionTree *&tree)
{
	deleteNode(tree->root);
	delete tree;
}

ExpressionTreeNode *getNode(ifstream &fin)
{
	char currentSymbol = fin.get();
	ExpressionTreeNode* newNode = new ExpressionTreeNode;

	if (isdigit(currentSymbol))
	{
		int currentOperand = convertCharToInt(currentSymbol);
		char nextSymbol = fin.get();
		while (isdigit(nextSymbol))
		{
			currentOperand = currentOperand * 10 + convertCharToInt(nextSymbol);
			nextSymbol = fin.get();
		}
		fin.unget();
		newNode->isOperand = true;
		newNode->value = currentOperand;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
	}

	else if (currentSymbol == '(')
	{
		currentSymbol = fin.get();
		newNode->isOperand = false;
		newNode->sign = currentSymbol;
		char skippingSpace = fin.get();
		newNode->leftChild = getNode(fin);
		skippingSpace = fin.get();
		newNode->rightChild = getNode(fin);
		char skippingClosedBracket = fin.get();
	}
	return newNode;
}

void getExpressionTree(ExpressionTree *tree, ifstream &fin)
{
	tree->root = getNode(fin);
}

double calculateNode(ExpressionTreeNode *node)
{
	if (node->isOperand)
	{
		return node->value;
	}

	if (node->sign == '+')
	{
		return calculateNode(node->leftChild) + calculateNode(node->rightChild);
	}
	if (node->sign == '-')
	{
		return calculateNode(node->leftChild) - calculateNode(node->rightChild);
	}
	if (node->sign == '*')
	{
		return calculateNode(node->leftChild) * calculateNode(node->rightChild);
	}
	if (node->sign == '/')
	{
		return calculateNode(node->leftChild) / calculateNode(node->rightChild);
	}

	else
	{
		cout << "Input is not expression." << endl;
		return 0;
	}
}

void calculateTree(ExpressionTree *tree)
{
	cout << "The result of a calculation: " << calculateNode(tree->root) << endl;
}

void printNodeInInfixNotation(ExpressionTreeNode *node)
{
	if ((node->leftChild) || (node->rightChild))
	{
		cout << '(';
		printNodeInInfixNotation(node->leftChild);
		cout << ' ' << node->sign << ' ';
		printNodeInInfixNotation(node->rightChild);
		cout << ')';
	}

	else
	{
		cout << node->value;
	}
}

void printTreeInInfixNotation(ExpressionTree *tree)
{
	cout << "The infix notation of the expression: ";
	printNodeInInfixNotation(tree->root);
	cout << endl;
}

