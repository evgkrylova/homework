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
};

Map *createEmptyMap(int n, int m);
Map *readMap(ifstream &fin, int n, int m);
void deleteMap(Map *map);
void printMap(Map *map);
