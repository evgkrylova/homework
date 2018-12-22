#pragma once
#include "list.h"
#include "listOfLists.h"

bool allCitiesAreVisited(bool *visitedCities, int numberOfCities);
bool isInCountry(List *country, int city);
void addNewCity(List *&country, Graph *graph, bool *visitedCities);
ListOfLists *seizure(Graph *graph, int *capitals, int capitalsNumber);
void printCountries(ListOfLists *countries, int capitalsNumber);

