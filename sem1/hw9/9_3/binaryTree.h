#pragma once
#include <fstream>

using namespace std;

struct BinaryTreeNode
{
	char value;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};

struct BinaryTree
{
	BinaryTreeNode *root;
};

BinaryTreeNode *createBinaryTreeNode(char value, BinaryTreeNode *left, BinaryTreeNode *right);
BinaryTree *createBinaryTree(ifstream &fin);
void deleteTree(BinaryTree *&tree);

void addValueToTree(BinaryTree *tree, char value);
void removeValueFromTree(BinaryTree *tree, char value);
bool isValueInTree(BinaryTree *tree, char value);
void printTreeInAscendingOrder(BinaryTree *tree);
void printTreeInDescendingOrder(BinaryTree *tree);
void printTreeInStorageOrder(BinaryTree *tree, ofstream &fout);

bool isValueInTree(BinaryTree *tree, char value);
bool isTreeEmpty(BinaryTree *tree);

BinaryTreeNode *readTree(ifstream &fin);
