#include <iostream>
#include <fstream>
#include "binaryTree.h"
#include "huffman.h"

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

void huffmanDecoding(BinaryTree *tree, ifstream &fin, ofstream &fout)
{
	char current = 0;
	while (!fin.eof())
	{
		BinaryTreeNode *temp = tree->root;
		while ((temp->leftChild) && (temp->rightChild))
		{
			fin.get(current);
			if (fin.eof())
			{
				return;
			}

			if (current == '0')
			{
				temp = temp->leftChild;
			}

			if (current == '1')
			{
				temp = temp->rightChild;
			}
		}

		fout << temp->value;
	}
}
