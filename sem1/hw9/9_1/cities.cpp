#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "cities.h"
#include "list.h"
#include "listOfLists.h"

bool allCitiesAreVisited(bool *visitedCities, int numberOfCities)
{
	for (int i = 0; i < numberOfCities; i++)
	{
		if (!visitedCities[i])
		{
			return false;
		}
	}
	return true;
}

bool isInCountry(List *country, int city)
{
	int amount = size(country);

	for (int i = 0; i < amount; i++)
	{
		if (getValue(country, i) == city)
		{
			return true;
		}
	}

	return false;
}

void addNewCity(List *&country, Graph *graph, bool *visitedCities)
{
	int minimalRoadLength = 1000000;

	int citiesNumber = cardinality(graph);
	int **roads = edges(graph);

	int newCity = 0;
	for (int i = 0; i < citiesNumber; i++)
	{
		for (int j = 0; j < citiesNumber; j++)
		{
			if ((isInCountry(country, i)) && (!visitedCities[j]) && (roads[i][j] != 0) && (roads[i][j] < minimalRoadLength))
			{
				minimalRoadLength = roads[i][j];
				newCity = j;
			}
		}
	}

	if (minimalRoadLength != 1000000)
	{
		visitedCities[newCity] = true;
		add(country, newCity);
	}
}

ListOfLists *seizure(Graph *graph, int *capitals, int capitalsNumber)
{
	int citiesNumber = cardinality(graph);
	bool *visitedCities = new bool[citiesNumber];

	for (int i = 0; i < citiesNumber; i++)
	{
		visitedCities[i] = false;
	}

	for (int i = 0; i < capitalsNumber; i++)
	{
		visitedCities[capitals[i]] = true;
	}

	ListOfLists *countries = createListOfLists();
	for (int i = 0; i < capitalsNumber; i++)
	{
		List *newCountry = createList();
		add(newCountry, capitals[i]);
		addList(countries, newCountry);
	}

	while (!allCitiesAreVisited(visitedCities, citiesNumber))
	{
		for (int i = 0; i < capitalsNumber; i++)
		{
			List *currentCountry = getList(countries, i);
			addNewCity(currentCountry, graph, visitedCities);
		}
	}

	delete[] visitedCities;
	return countries;
}

void printCountries(ListOfLists *countries, int capitalsNumber)
{
	for (int i = 0; i < capitalsNumber; i++)
	{
		List *currentCountry = getList(countries, i);
		cout << "Cities of country number " << i + 1 << ":" << endl;
		for (int j = 0; j < size(currentCountry); j++)
		{
			cout << getValue(currentCountry, j) + 1 << " ";
		}
		cout << endl << endl;
	}
}
