#include <iostream>
#include <fstream>
#include "binaryTree.h"
#include "queue.h"
#include "huffman.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	ofstream fout;
	fout.open("output.txt");

	const int standartStringSize = 256;

	Queue *queue = createQueue();
	int *string = new int[standartStringSize];

	for (int i = 0; i < standartStringSize; i++)
	{
		string[i] = 0;
	}

	char current = 0;
	while (!fin.eof())
	{
		fin.get(current);

		if (!fin.eof())
		{
			string[current]++;
		}
	}

	for (int i = 0; i < standartStringSize; i++)
	{
		if (string[i] != 0)
		{
			BinaryTreeNode *node = createBinaryTreeNode(i, nullptr, nullptr);
			addToQueue(node, string[i], queue);
		}
	}

	BinaryTree *tree = buildHuffmanTreeFromQueue(queue);
	printTreeInStorageOrder(tree, fout);
	fout << '\n';

	const int digitsNumber = 9;
	char digits[digitsNumber];
	char **symbols = new char *[standartStringSize];

	for (int i = 0; i < standartStringSize; i++)
	{
		symbols[i] = new char[digitsNumber];
	}

	huffmanCoding(tree, digits, symbols);

	fin.clear();
	fin.seekg(0);

	fin.get(current);

	while (!fin.eof())
	{
		fout << symbols[current];
		fin.get(current);
	}

	fin.close();
	fout.close();

	deleteQueue(queue);
	deleteTree(tree);

	for (int i = 0; i < standartStringSize; i++)
	{
		delete[] symbols[i];
	}
	delete[] symbols;

	return 0;
}
