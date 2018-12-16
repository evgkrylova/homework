#pragma once
#include <fstream>

using namespace std;

struct AVLTreeNode
{
	char symbol;
	int height;
	AVLTreeNode *leftChild;
	AVLTreeNode *rightChild;
};

struct AVLTree
{
	AVLTreeNode *root;
};

AVLTreeNode *createAVLTreeNode(char value, AVLTreeNode *leftChild, AVLTreeNode *rightChild);
AVLTree *createAVLTree(AVLTreeNode *root);
void deleteTree(AVLTree *&tree);

void addSymbolToTree(AVLTree *tree, char symbol);
char getSymbol(AVLTreeNode *node);
void removeSymbolFromTree(AVLTree *tree, char symbol);
bool isSymbolInTree(AVLTree *tree, char symbol);
void printTreeInAscendingOrder(AVLTree *tree);
void printTreeInDescendingOrder(AVLTree *tree);
void printTreeInStorageOrder(AVLTree *tree, ofstream &fout);

bool isSymbolInTree(AVLTree *tree, char symbol);
bool isTreeEmpty(AVLTree *tree);
void huffmanCoding(AVLTree *tree, char *digits, char **symbols);
