#include <iostream>
#include <fstream>
#include "matrix.h"
#include "aStar.h"

using namespace std;

void deleteNeighbours(Coordinates *&left, Coordinates *&right, Coordinates *&top, Coordinates *&bottom)
{
	delete left;
	delete right;
	delete top;
	delete bottom;
}

int absoluteValue(int number)
{
	if (number > 0)
	{
		return number;
	}
	return (-1) * number;
}

int heuristic(Coordinates *start, Coordinates *destination)
{
	return absoluteValue(start->x - destination->x) + absoluteValue(start->x - destination->y);
}

int heuristic(int x, int y, Coordinates *destination)
{
	return absoluteValue(x - destination->x) + absoluteValue(y - destination->y);
}

bool isCoordinatesCorrect(Map *map, Coordinates *point)
{
	int x = point->x;
	int y = point->y;
	return ((x >= 0) && (x < map->n) && (y >= 0) && (y < map->m));
}

bool isCoordinatesCorrect(Map *map, int x, int y)
{
	return ((x >= 0) && (x < map->n) && (y >= 0) && (y < map->m));
}

void calculateNextStepDistance(Map *&map, Coordinates *start, Coordinates *destination)
{
	int x1 = start->x;
	int y1 = start->y;

	int x2 = destination->x;
	int y2 = destination->y;

	if ((isCoordinatesCorrect(map, destination)) && (map->body[y2][x2] != 1))
	{
		int destinationDistance = map->distance[y2][x2];
		int startDistance = map->distance[y1][x1];

		if ((destinationDistance == -1) || (destinationDistance > startDistance + 1))
		{
			map->distance[y2][x2] = startDistance + 1;

			map->previousInXAxis[y2][x2] = x1;
			map->previousInYAxis[y2][x2] = y1;
		}
	}
}

void calculateDistance(Map *&map, Coordinates *current)
{
	Coordinates *left = new Coordinates{ current->x - 1, current->y };
	Coordinates *right = new Coordinates{ current->x + 1, current->y };
	Coordinates *top = new Coordinates{ current->x, current->y + 1 };
	Coordinates *bottom = new Coordinates{ current->x, current->y - 1 };

	calculateNextStepDistance(map, current, left);
	calculateNextStepDistance(map, current, right);
	calculateNextStepDistance(map, current, top);
	calculateNextStepDistance(map, current, bottom);

	deleteNeighbours(left, right, top, bottom);
}

void calculateNextStep(Map *map, Coordinates *&current, Coordinates *last, int x, int y, Coordinates *destination, int &minimalDistance)
{
	if ((isCoordinatesCorrect(map, x, y)) && (map->body[y][x] != 1))
	{
		int lastDistance = map->distance[last->y][last->x];
		int heuristicForNext = heuristic(x, y, destination);
		int nextDistance = lastDistance + heuristicForNext + 1;

		if ((!map->isVisited[y][x]) && (minimalDistance > nextDistance))
		{
			minimalDistance = nextDistance;
			current->x = x;
			current->y = y;
			return;
		}
	}
}

void calculateWay(Map *map, Coordinates *&current, Coordinates *last, Coordinates *&destination, int &minimalDistance)
{
	calculateNextStep(map, current, last, last->x - 1, last->y, destination, minimalDistance);
	calculateNextStep(map, current, last, last->x + 1, last->y, destination, minimalDistance);
	calculateNextStep(map, current, last, last->x, last->y + 1, destination, minimalDistance);
	calculateNextStep(map, current, last, last->x, last->y - 1, destination, minimalDistance);
}

void aStar(Map *map, Coordinates *start, Coordinates *destination)
{
	bool **isVisited = map->isVisited;
	int **body = map->body;
	int **distance = map->distance;
	int **previousInXAxis = map->previousInXAxis;
	int **previousInYAxis = map->previousInYAxis;

	int x1 = start->x;
	int y1 = start->y;

	int x2 = destination->x;
	int y2 = destination->y;

	int n = map->n;
	int m = map->m;

	map->isVisited[y1][x1] = true;
	map->distance[y1][x1] = 0;
	calculateDistance(map, start);

	Coordinates *current = new Coordinates{ y1, x1 };
	bool isPathFound = false;
	const int defaultMinimum = 100000;
	int minimalDistance = 0;

	while ((!isPathFound) && (minimalDistance < defaultMinimum))
	{
		int minimalDistance = defaultMinimum;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Coordinates *last = new Coordinates{ j, i };
				if (map->isVisited[i][j])
				{
					calculateWay(map, current, last, destination, minimalDistance);
				}
				delete last;
			}
		}

		if ((current->x == destination->x) && (current->y == destination->y))
		{
			isPathFound = true;
		}			

		else
		{
			if (map->isVisited[current->y][current->x] == true)
			{
				break;
			}
			map->isVisited[current->y][current->x] = true;
			calculateDistance(map, current);
		}
	}

	if (!isPathFound)
		cout << "There is no path on this map.\n";
	else
	{
		cout << "Length of path is " << map->distance[destination->y][destination->x]; 
	}

	delete current;
}

Coordinates *createCoordinates(int x, int y)
{
	return new Coordinates{ x, y };
}

void deleteCoordinates(Coordinates *coordinates)
{
	delete coordinates;
}

