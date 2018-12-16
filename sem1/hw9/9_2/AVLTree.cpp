#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

AVLTreeNode *createAVLTreeNode(char value, AVLTreeNode *left, AVLTreeNode *right)
{
	AVLTreeNode *newNode = new AVLTreeNode;

	newNode->symbol = value;
	newNode->leftChild = left;
	newNode->rightChild = right;

	return newNode;
};

AVLTree *createAVLTree(AVLTreeNode *root)
{
	AVLTree *newTree = new AVLTree;
	newTree->root = root;

	return newTree;
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

void addValueToNode(AVLTreeNode *&node, char symbol)
{
	if (node == nullptr)
	{
		node = createAVLTreeNode(symbol, nullptr, nullptr);
		return;
	}

	if (symbol == node->symbol)
	{
		return;
	}

	if (symbol < node->symbol)
	{
		addValueToNode(node->leftChild, symbol);
	}

	if (symbol > node->symbol)
	{
		addValueToNode(node->rightChild, symbol);
	}

	balanceNode(node);
}

void addSymbolToTree(AVLTree *tree, char symbol)
{
	addValueToNode(tree->root, symbol);
}

void removeSymbolFromNode(AVLTreeNode *&node, char symbol)
{
	if (node == nullptr)
	{
		return;
	}

	if (symbol == node->symbol)
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
		int changingValue = changingNode->symbol;
		removeSymbolFromNode(node, changingValue);
		node->symbol = changingValue;
		balanceNode(node);
		return;
	}

	if (symbol < node->symbol)
	{
		return removeSymbolFromNode(node->leftChild, symbol);
	}

	if (symbol > node->symbol)
	{
		return removeSymbolFromNode(node->rightChild, symbol);
	}

	balanceNode(node);
}

void removeSymbolFromTree(AVLTree *tree, char symbol)
{
	removeSymbolFromNode(tree->root, symbol);
}

bool isSymbolInTree(AVLTree *tree, char symbol)
{
	AVLTreeNode *currentNode = tree->root;

	while ((currentNode) && (symbol != currentNode->symbol))
	{
		if (symbol < currentNode->symbol)
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
	cout << node->symbol << ' ';
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
	cout << node->symbol << ' ';
	printNodeInDescendingOrder(node->leftChild);
}

void printTreeInDescendingOrder(AVLTree *tree)
{
	printNodeInDescendingOrder(tree->root);
	cout << endl;
}

void printNodeInStorageOrder(AVLTreeNode *node, ofstream &fout)
{
	if (!node)
	{
		fout << "null";
		return;
	}

	fout << '(' << node->symbol << ' ';
	printNodeInStorageOrder(node->leftChild, fout);
	fout << ' ';
	printNodeInStorageOrder(node->rightChild, fout);
	fout << ')';
}

void printTreeInStorageOrder(AVLTree *tree, ofstream &fout)
{
	printNodeInStorageOrder(tree->root, fout);
	cout << endl;
}

bool isTreeEmpty(AVLTree *tree)
{
	return tree->root == nullptr;
}

char getSymbol(AVLTreeNode *node)
{
	return node->symbol;
}

void huffmanCodingForNode(AVLTreeNode *node, char *digits, char **symbols, int index)
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
			symbols[node->symbol][i] = digits[i];
		}
	}
}

void huffmanCoding(AVLTree *tree, char *digits, char **symbols)
{
	if (!tree->root)
	{
		return;
	}

	huffmanCodingForNode(tree->root, digits, symbols, 0);
}

