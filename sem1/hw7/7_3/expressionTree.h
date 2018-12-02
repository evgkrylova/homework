#pragma once
#include <fstream>

using namespace std;

struct ExpressionTreeNode
{
	bool isOperand;
	char sign;
	double value;
	ExpressionTreeNode *leftChild;
	ExpressionTreeNode *rightChild;
};

struct ExpressionTree
{
	ExpressionTreeNode *root;
};

ExpressionTree *createExpressionTree();

void deleteNode(ExpressionTreeNode *&node);
void deleteTree(ExpressionTree *&tree);

ExpressionTreeNode *getNode(ifstream &fin);
void getExpressionTree(ExpressionTree *tree, ifstream &fin);

double calculateNode(ExpressionTreeNode *node);
void calculateTree(ExpressionTree *tree);

void printNodeInInfixNotation(ExpressionTreeNode *node);
void printTreeInInfixNotation(ExpressionTree *tree);
