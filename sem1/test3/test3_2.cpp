#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int n = 0;
	int m = 0;
	fin >> n >> m; //??????? ???????
	int **matrix = readMatrix(fin, n, m);

	printPoints(matrix, n, m);
	deleteMatrix(matrix, n, m);

	return 0;
}

