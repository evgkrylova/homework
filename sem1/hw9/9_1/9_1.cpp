#include <iostream>
#include <fstream>
#include "graph.h"
#include "cities.h"
#include "list.h"
#include "listOfLists.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int citiesNumber = 0;
	int roadsNumber = 0;
	fin >> citiesNumber >> roadsNumber;
	Graph *graph = readGraph(fin, citiesNumber, roadsNumber);

	int capitalsNumber = 0;
	fin >> capitalsNumber;
	int *capitals = new int[capitalsNumber];

	for (int i = 0; i < capitalsNumber; i++)
	{
		int capital = 0;
		fin >> capital;
		capitals[i] = capital - 1;
	}

	fin.close();

	ListOfLists *countries = seizure(graph, capitals, capitalsNumber);
	printCountries(countries, capitalsNumber);

	deleteGraph(graph);
	delete[] capitals;

	return 0;
}

