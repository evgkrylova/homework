#pragma once

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};

struct BinaryTree
{
	BinaryTreeNode *root;
};

BinaryTree *createBinaryTree();
void deleteTree(BinaryTree *&tree);

void addValueToTree(BinaryTree *tree, int value);
void removeValueFromTree(BinaryTree *tree, int value);
bool isValueInTree(BinaryTree *tree, int value);
void printTreeInAscendingOrder(BinaryTree *tree);
void printTreeInDescendingOrder(BinaryTree *tree);
void printTreeInStorageOrder(BinaryTree *tree);

bool isValueInTree(BinaryTree *tree, int value);
bool isTreeEmpty(BinaryTree *tree);
