#include <iostream>
#include <fstream>
#include "binaryTree.h"

using namespace std;

void huffmanCodingForNode(BinaryTreeNode *node, char *digits, char **symbols, int index)
{
	if (node->leftChild != nullptr)
	{
		digits[index] = '0';
		huffmanCodingForNode(node->leftChild, digits, symbols, index + 1);
	}
	if (node->rightChild != nullptr)
	{
		digits[index] = '1';
		huffmanCodingForNode(node->rightChild, digits, symbols, index + 1);
	}
	else
	{
		digits[index] = '\0';
		for (int i = 0; i <= index; i++)
		{
			symbols[node->value][i] = digits[i];
		}
	}
}

void huffmanCoding(BinaryTree *tree, char *digits, char **symbols)
{
	if (!tree->root)
	{
		return;
	}

	huffmanCodingForNode(tree->root, digits, symbols, 0);
}


