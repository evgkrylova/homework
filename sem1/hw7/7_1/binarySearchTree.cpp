#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree *createBinaryTree()
{
	return new BinaryTree{ nullptr };
}

BinaryTreeNode *createBinaryTreeNode(int value)
{
	return new BinaryTreeNode{ value, nullptr, nullptr };
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

void removeValueFromNode(BinaryTreeNode *&node, int value)
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

void removeValueFromTree(BinaryTree *tree, int value)
{
	removeValueFromNode(tree->root, value);
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

void printTreeInStorageOrder(BinaryTree *tree)
{
	printNodeInStorageOrder(tree->root);
	cout << endl;
}

bool isTreeEmpty(BinaryTree *tree)
{
	return tree->root == nullptr;
}

