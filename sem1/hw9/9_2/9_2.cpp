#include <iostream>
#include <fstream>
#include "AVLTree.h"
#include "queue.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	ofstream fout;
	fout.open("output.txt");

	const int standartSize = 256;

	Queue *queue = createQueue();
	int *string = new int[standartSize];

	for (int i = 0; i < standartSize; i++)
	{
		string[i] = 0;
	}

	char current = 0;
	while (!fin.eof())
	{
		fin.get(current);

		if (!fin.eof())
		{
			string[(int)(current)]++;
		}
	}

	for (int i = 0; i < standartSize; i++)
	{
		if (string[i] != 0)
		{
			AVLTreeNode *node = createAVLTreeNode(i, nullptr, nullptr);
			addToQueue(node, string[i], queue);
		}
	}

	AVLTree *tree = spliceOfNodes(queue);
	printTreeInStorageOrder(tree, fout);
	fout << '\n';

	const int digitsNumber = 9;
	char digits[digitsNumber];
	char **symbols = new char *[standartSize];

	for (int i = 0; i < standartSize; i++)
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

	for (int i = 0; i < standartSize; i++)
	{
		delete[] symbols[i];
	}
	delete[] symbols;

	return 0;
}
