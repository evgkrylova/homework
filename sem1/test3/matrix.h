#pragma once

using namespace std;

int **readMatrix(ifstream &fin, int n, int m);
int minimalInRow(int *row, int m);
int maximalInColumn(int **matrix, int n, int m, int columnNumber);
int *minimalInRows(int **matrix, int n, int m);
int *maximalInColumns(int **matrix, int n, int m);
int maximalInArray(int *array, int size);
int minimalInArray(int *array, int size);

void printPoints(int **matrix, int n, int m);
void deleteMatrix(int **matrix, int n, int m);
