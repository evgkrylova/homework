#pragma once
#include "binaryTree.h"

void huffmanCoding(BinaryTree *tree, char *digits, char **symbols);
void huffmanDecoding(BinaryTree *tree, ifstream &fin, ofstream &fout);
