#pragma once
#include "matrix.h"

struct Coordinates
{
	int x = 0;
	int y = 0;
};

Coordinates *createCoordinates(int x, int y);
void aStar(Map *map, Coordinates *start, Coordinates *destination);
void deleteCoordinates(Coordinates *coordinates);
bool isCoordinatesCorrect(Map *map, Coordinates *point);
