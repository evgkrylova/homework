#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int **createEmptyIntMatrix(int n, int m)
{
	int **matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = -1;
		}
	}

	return matrix;
}

bool **createEmptyBoolMatrix(int n, int m)
{
	bool **matrix = new bool*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = false;
		}
	}

	return matrix;
}

Map *createEmptyMap(int n, int m)
{
	Map *map = new Map{ n, m, nullptr };
	int **body = new int*[n];

	for (int i = 0; i < n; i++)
	{
		body[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			body[i][j] = -1;
		}
	}

	map->body = body;

	return map;
}

void deleteIntMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void deleteBoolMatrix(bool **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void deleteMap(Map *map)
{
	int n = map->n;

	deleteIntMatrix(map->body, n);
	deleteBoolMatrix(map->isVisited, n);
	deleteIntMatrix(map->distance, n);
	deleteIntMatrix(map->previousInXAxis, n);
	deleteIntMatrix(map->previousInYAxis, n);

	delete map;
}

Map *readMap(ifstream &fin, int n, int m)
{
	Map *map = new Map{ n, m, nullptr };
	int **body = new int*[n];

	for (int i = 0; i < n; i++)
	{
		body[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fin >> body[i][j];
		}
	}

	map->body = body;
	map->isVisited = createEmptyBoolMatrix(n, m);
	map->distance = createEmptyIntMatrix(n, m);
	map->previousInXAxis = createEmptyIntMatrix(n, m);
	map->previousInYAxis = createEmptyIntMatrix(n, m);

	return map;
}

void printMap(Map *map)
{
	int n = map->n;
	int m = map->m;

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map->body[i][j] << ' ';
		}

		cout << endl;
	}
}

