#include <iostream>
#include <fstream>
#include "map.h"

using namespace std;

Coordinates *createCoordinates(int x, int y)
{
	return new Coordinates{ x, y };
}

bool isCoordinatesCorrect(Map *map, Coordinates *point)
{
	int x = point->x;
	int y = point->y;
	return ((x >= 0) && (x < map->m) && (y >= 0) && (y < map->n));
}

bool isCoordinatesCorrect(Map *map, int x, int y)
{
	return ((x >= 0) && (x < map->m) && (y >= 0) && (y < map->n));
}

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
	deleteBoolMatrix(map->path, n);

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
	map->path = createEmptyBoolMatrix(n, m);

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

void printPath(Map *map, Coordinates *start, Coordinates *destination)
{
	cout << "The path: " << endl;

	for (int i = 0; i < map->n; i++)
	{
		for (int j = 0; j < map->m; j++)
		{
			if (map->path[i][j])
			{
				cout << "* ";
			}
			else if (i == start->y && j == start->x)
			{
				cout << "s ";
			}
			else if ((i == destination->y) && (j == destination->x))
			{
				cout << "d ";
			}
			else
			{
				cout << map->path[i][j] << ' ';
			}
		}
		cout << endl;
	}
}

bool areCoordinatesEqual(Coordinates *a, Coordinates *b)
{
	int x1 = a->x;
	int y1 = a->y;

	int x2 = b->x;
	int y2 = b->y;

	return ((x1 == x2) && (y1 == y2));
}
