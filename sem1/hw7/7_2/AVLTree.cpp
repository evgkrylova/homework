#include <iostream>
#include "AVLTree.h"

using namespace std;

AVLTree *createAVLTree()
{
	AVLTree* newTree = new AVLTree;
	newTree->root = nullptr;
	return newTree;
}

AVLTreeNode *createAVLTreeNode(int value)
{
	AVLTreeNode *newNode = new AVLTreeNode;
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	updateHeight(newNode);
	return newNode;
}

void deleteNode(AVLTreeNode *&node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteNode(node->leftChild);
	deleteNode(node->rightChild);

	delete node;
}

void deleteTree(AVLTree *&tree)
{
	deleteNode(tree->root);
	delete tree;
}

void addValueToNode(AVLTreeNode *&node, int value)
{
	if (node == nullptr)
	{
		node = createAVLTreeNode(value);
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

	balanceNode(node);
}

void addValueToTree(AVLTree *tree, int value)
{
	addValueToNode(tree->root, value);
}

void removeValueFromNode(AVLTreeNode *&node, int value)
{
	if (node == nullptr)
	{
		return;
	}

	if (value == node->value)
	{
		AVLTreeNode *changingNode = node->leftChild;
		AVLTreeNode *right = node->rightChild;

		if (!changingNode)
		{
			if (!right)
			{
				node = nullptr;
				delete node;
				return;
			}
			delete node;
			node = right;
			return;
		}

		while (changingNode->rightChild)
		{
			changingNode = changingNode->rightChild;
		}

		int changingValue = changingNode->value;
		removeValueFromNode(node, changingValue);
		node->value = changingValue;
		balanceNode(node);
		return;
	}

	if (value < node->value)
	{
		removeValueFromNode(node->leftChild, value);
	}

	if (value > node->value)
	{
		removeValueFromNode(node->rightChild, value);
	}
	
	balanceNode(node);
}

void removeValueFromTree(AVLTree *tree, int value)
{
	removeValueFromNode(tree->root, value);
}

bool isValueInTree(AVLTree *tree, int value)
{
	AVLTreeNode *currentNode = tree->root;

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

void printNodeInAscendingOrder(AVLTreeNode *node)
{
	if (!node)
	{
		return;
	}

	printNodeInAscendingOrder(node->leftChild);
	cout << node->value << ' ';
	printNodeInAscendingOrder(node->rightChild);
}

void printTreeInAscendingOrder(AVLTree *tree)
{
	printNodeInAscendingOrder(tree->root);
	cout << endl;
}

void printNodeInDescendingOrder(AVLTreeNode *node)
{
	if (!node)
	{
		return;
	}

	printNodeInDescendingOrder(node->rightChild);
	cout << node->value << ' ';
	printNodeInDescendingOrder(node->leftChild);
}

void printTreeInDescendingOrder(AVLTree *tree)
{
	printNodeInDescendingOrder(tree->root);
	cout << endl;
}

void printNodeInStorageOrder(AVLTreeNode *node)
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

void printTreeInStorageOrder(AVLTree *tree)
{
	printNodeInStorageOrder(tree->root);
	cout << endl;
}

bool isTreeEmpty(AVLTree *tree)
{
	return tree->root == nullptr;
}

int height(AVLTreeNode *node)
{
	return node ? node->height : 0;
}

int balanceFactor(AVLTreeNode *node)
{
	return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(AVLTreeNode *node)
{
	int heightLeftChild = height(node->leftChild);
	int heightRightChild = height(node->rightChild);
	node->height = ((heightLeftChild > heightRightChild) ? heightLeftChild : heightRightChild) + 1;
}

void rotateRight(AVLTreeNode *&node)
{
	AVLTreeNode* temp = node->leftChild;
	node->leftChild = temp->rightChild;
	temp->rightChild = node;
	updateHeight(node);
	updateHeight(temp);
	node = temp;
}

void rotateLeft(AVLTreeNode *&node)
{
	AVLTreeNode* temp = node->rightChild;
	node->rightChild = temp->leftChild;
	temp->leftChild = node;
	updateHeight(node);
	updateHeight(temp);
	node = temp;
}

void balanceNode(AVLTreeNode *&node)
{
	updateHeight(node);
	int factor = balanceFactor(node);
	if (factor == 2)
	{
		if (balanceFactor(node->rightChild) < 0)
		{
			rotateRight(node->rightChild);
		}
		rotateLeft(node);
	}
	else if (factor == -2)
	{
		if (balanceFactor(node->leftChild) > 0)
		{
			rotateLeft(node->leftChild);
		}
		rotateRight(node);
	}
}

