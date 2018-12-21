#include <iostream>
#include <fstream>

using namespace std;

bool isCorrectNode(bool *path, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!path[i])
		{
			return false;
		}
	}
	return true;
}


int findBegin(int **matrix, int n, int index)
{
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][index] == 1)
		{
			return i;
		}
	}

	return 0;
}

void findPaths(int **matrix, bool *pathExists, int startPoint, int m, int n, int current)
{
	for (int i = 0; i < m; i++)
	{
		if (matrix[startPoint][i] == -1)
		{
			int begin = findBegin(matrix, n, i);
			if (!pathExists[begin])
			{
				pathExists[begin] = true;
				findPaths(matrix, pathExists, begin, m, n, current);
			}
		}
	}
}

void printNodes(int **matrix, bool *pathExists, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			pathExists[i] = false;
		}

		findPaths(matrix, pathExists, i, m, n, i);
		pathExists[i] = true;
		if (isCorrectNode(pathExists, n))
		{
			cout << "Number of city : " << i << endl;
		}
	}
}

int **readMatrix(ifstream &fin, int n, int m)
{
	int **body = new int*[n];

	for (int i = 0; i < n; i++)
	{
		body[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			int path = 0;
			fin >> path;
			body[i][j] = path;
		}
	}

	return body;
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int n = 0;
	int m = 0;
	fin >> n >> m;

	bool *pathExists = new bool[n];

	int **matrix = readMatrix(fin, n, m);

	printNodes(matrix, pathExists, n, m);

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	delete[] pathExists;
	fin.close();
	return 0;
}

