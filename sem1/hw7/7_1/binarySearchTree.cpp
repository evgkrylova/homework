#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree *createBinaryTree()
{
	BinaryTree* newTree = new BinaryTree;
	newTree->root = nullptr;
	return newTree;
}

BinaryTreeNode *createBinaryTreeNode(int value)
{
	BinaryTreeNode *newNode = new BinaryTreeNode;
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	return newNode;
}

void deleteNode(BinaryTreeNode *&node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteNode(node->leftChild);
	deleteNode(node->rightChild);

	delete node;
}

void deleteTree(BinaryTree *&tree)
{
	deleteNode(tree->root);
	delete tree;
}

void addValueToNode(BinaryTreeNode *&node, int value)
{
	if (node == nullptr)
	{
		node = createBinaryTreeNode(value);
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

void addValueToTree(BinaryTree *tree, int value)
{
	addValueToNode(tree->root, value);
}

void deleteValueFromNode(BinaryTreeNode *&node, int value)
{
	if (node == nullptr)
	{
		return;
	}
		
	if (value == node->value)
	{
		BinaryTreeNode *deletingNode = node;
		BinaryTreeNode *changingNode = node->leftChild;
		BinaryTreeNode *right = node->rightChild;

		if (!changingNode)
		{
			if (!right)
			{
				node = nullptr;
				delete node;
				return;
			}
			node = node->rightChild;
			delete deletingNode;
			return;
		}
		
		while (changingNode)
		{
			changingNode = changingNode->rightChild;
		}
		deletingNode->value = changingNode->value;
		changingNode = nullptr;
		delete changingNode;
		return;
	}

	if (value < node->value)
	{
		return deleteValueFromNode(node->leftChild, value);
	}

	if (value > node->value)
	{
		return deleteValueFromNode(node->rightChild, value);
	}
}

void deleteValueFromTree(BinaryTree *tree, int value)
{
	deleteValueFromNode(tree->root, value);
}

bool isValueInTree(BinaryTree *tree, int value)
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

void printNodeInStorageOrder(BinaryTreeNode *node)
{
	if (!node)
	{
		cout << "null";
		return;
	}

	cout << '(' << node->value << ' ';
	printNodeInStorageOrder(node->leftChild);
	cout << ' ';
	printNodeInStorageOrder(node->rightChild);
	cout << ')';
}

void printAsTree(BinaryTree *tree)
{
	printNodeInStorageOrder(tree->root);
	cout << endl;
}

bool isTreeEmpty(BinaryTree *tree)
{
	return tree->root == nullptr;
}
