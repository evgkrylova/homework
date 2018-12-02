#include <iostream>
#include <fstream>
#include "expressionTree.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	ExpressionTree *tree = createExpressionTree();
	getExpressionTree(tree, fin);

	fin.close();

	printTreeInInfixNotation(tree);
	calculateTree(tree);

	deleteTree(tree);
	return 0;
}

