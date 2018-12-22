#pragma once

using namespace std;

struct Graph {
	int cardinality;
	int **edges;
};

Graph *createGraph();
void deleteGraph(Graph *&graph);

Graph *readGraph(ifstream &file, int cardinality, int edgesNumber);

int **edges(Graph *graph);
int cardinality(Graph *graph);

void printGraph(Graph *graph);
