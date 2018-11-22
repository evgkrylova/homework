#include <iostream>
#include "matrix.h"

using namespace std;

void segmentOfSpiralRound(int &changingIndex, int currentColmnIndex, int currentRowIndex, bool direction, int steps, int **matrix)
{
	for (int i = 0; i < steps; i++)
	{
		if (direction)
			changingIndex++;
		else
			changingIndex--;
		cout << matrix[currentRowIndex][currentColmnIndex] << " ";
	}
}

void spiralRoundAndPrint(int **matrix, int size)
{
	int const centralRowIndex = size / 2;
	int const centralColmnIndex = centralRowIndex;
	cout << matrix[centralRowIndex][centralColmnIndex] << " ";
	int currentRowIndex = centralRowIndex;
	int currentColmnIndex = centralColmnIndex;
	int steps = 1;
	bool direction = true;
	while (steps < size)
	{

		for (int i = 0; i < steps; i++)
		{
			if (direction)
				currentColmnIndex++;
			else
				currentColmnIndex--;
			cout << matrix[currentRowIndex][currentColmnIndex] << " ";
		}

		direction = !direction;

		for (int i = 0; i < steps; i++)
		{
			if (direction)
				currentRowIndex++;
			else
				currentRowIndex--;
			cout << matrix[currentRowIndex][currentColmnIndex] << " ";
		}

		steps++;
	}

	for (int i = 1; i < size; i++)
	{
		cout << matrix[size - 1][i] << " ";
	}
}

int main()
{
	int order = 0;
	cout << "Enter the order of a square matrix: ";
	cin >> order;

	
	if (order % 2 == 0)
	{
		cout << "Programme cannot make a round of the matrix because it is of the even order.";
		return 0;
	}

	int **squareMatrix = createMatrix(order, order);
	fillMatrix(squareMatrix, order, order);
	spiralRoundAndPrint(squareMatrix, order);
	deleteMatrix(squareMatrix, order, order);

	return 0;
}
