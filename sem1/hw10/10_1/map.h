#pragma once

using namespace std;

struct Map
{
	int n;
	int m;
	int **body;
	bool **isVisited;
	int **distance;
	int **previousInXAxis;
	int **previousInYAxis;
	bool **path;
};

struct Coordinates
{
	int x = 0;
	int y = 0;
};

Coordinates *createCoordinates(int x, int y);
bool isCoordinatesCorrect(Map *map, Coordinates *point);
bool isCoordinatesCorrect(Map *map, int x, int y);
bool areCoordinatesEqual(Coordinates *a, Coordinates *b);

Map *createEmptyMap(int n, int m);
Map *readMap(ifstream &fin, int n, int m);
void deleteMap(Map *map);
void printMap(Map *map);

void printPath(Map *map, Coordinates *start, Coordinates *destination);
