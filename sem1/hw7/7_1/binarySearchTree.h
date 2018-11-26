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
BinaryTreeNode *createBinaryTreeNode(int value);

void deleteNode(BinaryTreeNode *&node);
void deleteTree(BinaryTree *&tree);

void addValueToNode(BinaryTreeNode *&node, int value);
void addValueToTree(BinaryTree *tree, int value);

void deleteValueFromNode(BinaryTreeNode *&node, int value);
void deleteValueFromTree(BinaryTree *tree, int value);

bool isValueInTree(BinaryTree *tree, int value);

void printNodeInAscendingOrder(BinaryTreeNode *node);
void printTreeInAscendingOrder(BinaryTree *tree);

void printNodeInDescendingOrder(BinaryTreeNode *node);
void printTreeInDescendingOrder(BinaryTree *tree);

void printNodeInStorageOrder(BinaryTreeNode *node);
void printAsTree(BinaryTree *tree);

bool isTreeEmpty(BinaryTree *tree);
