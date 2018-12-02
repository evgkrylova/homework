#pragma once

struct AVLTreeNode
{
	int value;
	int height;
	AVLTreeNode *leftChild;
	AVLTreeNode *rightChild;
};

struct AVLTree
{
	AVLTreeNode *root;
};

AVLTree *createAVLTree();
AVLTreeNode *createAVLTreeNode(int value);

void deleteNode(AVLTreeNode *&node);
void deleteTree(AVLTree *&tree);

void addValueToNode(AVLTreeNode *&node, int value);
void addValueToTree(AVLTree *tree, int value);

void deleteValueFromNode(AVLTreeNode *&node, int value);
void deleteValueFromTree(AVLTree *tree, int value);

bool isValueInTree(AVLTree *tree, int value);

void printNodeInAscendingOrder(AVLTreeNode *node);
void printTreeInAscendingOrder(AVLTree *tree);

void printNodeInDescendingOrder(AVLTreeNode *node);
void printTreeInDescendingOrder(AVLTree *tree);

void printNodeInStorageOrder(AVLTreeNode *node);
void printAsTree(AVLTree *tree);

bool isTreeEmpty(AVLTree *tree);

int height(AVLTreeNode *node);
int balanceFactor(AVLTreeNode *node);
void updateHeight(AVLTreeNode *node);
void balanceNode(AVLTreeNode *&node);

void rotateRight(AVLTreeNode *&node);
void rotateLeft(AVLTreeNode *&node);

