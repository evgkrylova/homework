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
void deleteTree(AVLTree *&tree);

void addValueToTree(AVLTree *tree, int value);
void removeValueFromTree(AVLTree *tree, int value);
void printTreeInAscendingOrder(AVLTree *tree);
void printTreeInDescendingOrder(AVLTree *tree);
void printTreeInStorageOrder(AVLTree *tree);

bool isValueInTree(AVLTree *tree, int value);
bool isTreeEmpty(AVLTree *tree);

int height(AVLTreeNode *node);
int balanceFactor(AVLTreeNode *node);
void updateHeight(AVLTreeNode *node);
void balanceNode(AVLTreeNode *&node);

void rotateRight(AVLTreeNode *&node);
void rotateLeft(AVLTreeNode *&node);

