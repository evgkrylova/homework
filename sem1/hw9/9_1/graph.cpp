#include <iostream>
#include <fstream>
#include "graph.h"
#include "list.h"

using namespace std;

Graph *createGraph()
{
	return new Graph{ 0, nullptr };
}

void deleteGraph(Graph *&graph)
{
	deleteArrayOfArrays(graph->edges, graph->cardinality);
	delete graph;
}

int cardinality(Graph *graph)
{
	return graph->cardinality;
}

int **edges(Graph *graph)
{
	return graph->edges;
}

Graph *readGraph(ifstream &fin, int cardinality, int edgesNumber)
{
	Graph *graph = new Graph;

	graph->edges = new int *[cardinality];
	for (int i = 0; i < cardinality; i++)
	{
		graph->edges[i] = new int[cardinality];
		for (int j = 0; j < cardinality; j++)
		{
			graph->edges[i][j] = 0;
		}
	}

	int i = 0;
	int j = 0;
	int edgeLength = 0;
	for (int index = 0; index < edgesNumber; index++)
	{
		fin >> i >> j >> edgeLength;
		graph->edges[i - 1][j - 1] = edgeLength;
		graph->edges[j - 1][i - 1] = edgeLength;
	}

	graph->cardinality = cardinality;

	return graph;
}

void printGraph(Graph *graph)
{
	std::cout << '\n';
	int cardinality = graph->cardinality;
	for (int i = 0; i < cardinality; i++)
	{
		for (int j = 0; j < cardinality; j++)
		{
			std::cout << graph->edges[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

