#include <iostream>
#include "matrix.h"

using namespace std;

int **createMatrix(int rows, int columns)
{
	int **matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[columns];
	return matrix;
}

void fillMatrix(int **matrix, int rows, int columns)
{
	cout << "Enter the matrix: \n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void deleteMatrix(int **matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
