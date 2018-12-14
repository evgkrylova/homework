#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int **readMatrix(ifstream &fin, int n, int m)
{
	
	int **matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			fin >> matrix[i][j];
		}
	}

	return matrix;
}

int minimalInRow(int *row, int m)
{
	return minimalInArray(row, m);
}

int maximalInColumn(int **matrix, int n, int m, int columnNumber)
{
	int maximal = matrix[0][columnNumber];
	for (int i = 1; i < m; i++)
	{
		int current = matrix[0][columnNumber];
		if (current > maximal)
		{
			maximal = current;
		}
	}

	return maximal;
}

int *minimalInRows(int **matrix, int n, int m)
{
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = minimalInRow(matrix[i], m);
	}

	return array;
}

int *maximalInColumns(int **matrix, int n, int m)
{
	int *array = new int[n];
	for (int j = 0; j < m; j++)
	{
		array[j] = maximalInColumn(matrix, n, m, j);
	}

	return array;
}

int maximalInArray(int *array, int size)
{
	int maximal = array[0];
	for (int i = 1; i < size; i++)
	{
		int current = array[i];
		if (maximal < current)
		{
			maximal = current;
		}
	}
	return maximal;
}

int minimalInArray(int *array, int size)
{
	int minimal = array[0];
	for (int i = 1; i < size; i++)
	{
		int current = array[i];
		if (minimal > current)
		{
			minimal = current;
		}
	}
	return minimal;
}

void printPoints(int **matrix, int n, int m)
{
	int *maximals = maximalInColumns(matrix, n, m);
	int *minimals = minimalInRows(matrix, n, m);

	int maximalOfMinimals = maximalInArray(minimals, n);
	int minimalOfMaximals = minimalInArray(maximals, m);

	if (minimalOfMaximals != maximalOfMinimals)
	{
		cout << "There is no special point in matrix.";
		return;
	}

	cout << "Special point: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (minimals[i] == maximalOfMinimals)
		{
			for (int j = 0; j < m; j++)
			{
				if (maximals[j] == minimalOfMaximals)
				{
					cout << i << " " << j << endl;
				}
			}
		}
	}
}

void deleteMatrix(int **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

