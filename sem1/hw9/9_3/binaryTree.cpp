#include <iostream>
#include <fstream>
#include "binaryTree.h"

using namespace std;

BinaryTreeNode *createBinaryTreeNode(char value, BinaryTreeNode *left, BinaryTreeNode *right)
{
	BinaryTreeNode *newNode = new BinaryTreeNode;

	newNode->value = value;
	newNode->leftChild = left;
	newNode->rightChild = right;

	return newNode;
};

BinaryTree *createBinaryTree(ifstream &fin)
{
	BinaryTree *newTree = new BinaryTree;
	newTree->root = readTree(fin);
	return newTree;
}

void deleteNode(BinaryTreeNode *&node)
{
	if (node->leftChild != nullptr)
	{
		deleteNode(node->leftChild);
	}

	if (node->rightChild != nullptr)
	{
		deleteNode(node->rightChild);
	}

	delete node;
	node = nullptr;
}

void clearBinaryTree(BinaryTree *tree)
{
	if (tree->root != nullptr)
	{
		deleteNode(tree->root);
	}
}

void deleteTree(BinaryTree *&tree)
{
	clearBinaryTree(tree);

	delete tree;
	tree = nullptr;
}

void addValueToNode(BinaryTreeNode *&node, char value)
{
	if (node == nullptr)
	{
		node = createBinaryTreeNode(value, nullptr, nullptr);
		return;
	}

	if (value == node->value)
	{
		return;
	}

	if (value < node->value)
	{
		addValueToNode(node->leftChild, value);
	}

	if (value > node->value)
	{
		addValueToNode(node->rightChild, value);
	}
}

void addValueToTree(BinaryTree *tree, char value)
{
	addValueToNode(tree->root, value);
}

void deleteChilds(BinaryTreeNode *node, BinaryTreeNode *&changingNode, BinaryTreeNode *&right)
{
	if (!node->leftChild)
	{
		deleteNode(changingNode);
	}
	if (!node->rightChild)
	{
		deleteNode(right);
	}
}

void removeValueFromNode(BinaryTreeNode *&node, char value)
{
	if (node->value == value)
	{
		if ((node->leftChild == nullptr) && (node->rightChild == nullptr))
		{
			delete node;
			node = nullptr;
		}

		else if ((node->leftChild != nullptr) && (node->rightChild != nullptr))
		{
			BinaryTreeNode *changingNode = node->leftChild;

			while (changingNode->rightChild != nullptr)
			{
				changingNode = changingNode->rightChild;
			}

			int changingValue = changingNode->value;
			removeValueFromNode(node, changingNode->value);
			node->value = changingValue;
		}

		else if (node->leftChild != nullptr)
		{
			BinaryTreeNode *changingNode = node->leftChild;
			delete node;
			node = changingNode;
		}

		else if (node->rightChild != nullptr)
		{
			BinaryTreeNode *changingNode = node->rightChild;
			delete node;
			node = changingNode;
		}

		return;

	}

	if (value < node->value)
	{
		return removeValueFromNode(node->leftChild, value);
	}

	if (value > node->value)
	{
		return removeValueFromNode(node->rightChild, value);
	}
}

void removeValueFromTree(BinaryTree *tree, char value)
{
	removeValueFromNode(tree->root, value);
}

bool isValueInTree(BinaryTree *tree, char value)
{
	BinaryTreeNode *currentNode = tree->root;

	while ((currentNode) && (value != currentNode->value))
	{
		if (value < currentNode->value)
		{
			currentNode = currentNode->leftChild;
			continue;
		}
		currentNode = currentNode->rightChild;
	}

	if (currentNode)
	{
		return true;
	}
	return false;
}

void printNodeInAscendingOrder(BinaryTreeNode *node)
{
	if (!node)
	{
		return;
	}

	printNodeInAscendingOrder(node->leftChild);
	cout << node->value << ' ';
	printNodeInAscendingOrder(node->rightChild);
}

void printTreeInAscendingOrder(BinaryTree *tree)
{
	printNodeInAscendingOrder(tree->root);
	cout << endl;
}

void printNodeInDescendingOrder(BinaryTreeNode *node)
{
	if (!node)
	{
		return;
	}

	printNodeInDescendingOrder(node->rightChild);
	cout << node->value << ' ';
	printNodeInDescendingOrder(node->leftChild);
}

void printTreeInDescendingOrder(BinaryTree *tree)
{
	printNodeInDescendingOrder(tree->root);
	cout << endl;
}

void printNodeInStorageOrder(BinaryTreeNode *node, ofstream &fout)
{
	if (!node)
	{
		fout << "null";
		return;
	}

	fout << '(' << node->value << ' ';
	printNodeInStorageOrder(node->leftChild, fout);
	fout << ' ';
	printNodeInStorageOrder(node->rightChild, fout);
	fout << ')';
}

void printTreeInStorageOrder(BinaryTree *tree, ofstream &fout)
{
	printNodeInStorageOrder(tree->root, fout);
	cout << endl;
}

bool isTreeEmpty(BinaryTree *tree)
{
	return tree->root == nullptr;
}

BinaryTreeNode *readTree(ifstream &fin)
{
	const int nullLength = 4;
	char current = '\0';
	char null = '\0';
	char space = '\0';
	char closedBracket = '\0';

	BinaryTreeNode *node = nullptr;

	fin.get(current);

	if ((current == '(') || ((current == ' ') && (fin.get() == '(')))
	{
		fin.get(current);
		fin.get(space);
		
		BinaryTreeNode *left = readTree(fin);
		BinaryTreeNode *right = readTree(fin);
		node = createBinaryTreeNode(current, left, right);

		fin.get(closedBracket);
		return node;
	}

	if ((current != ')') && (current != ' '))
	{
		for (int i = 0; i < nullLength - 1; i++)
		{
			fin.get(null);
		}
	}

	fin.get(closedBracket);
	return nullptr;
}

