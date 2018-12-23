#include <iostream>
#include <fstream>
#include "binaryTree.h"
#include "huffman.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	ofstream fout;
	fout.open("output.txt");

	BinaryTree *tree = createBinaryTree(fin);
	huffmanDecoding(tree, fin, fout);
	deleteTree(tree);

	fin.close();
	fout.close();

	return 0;
}
