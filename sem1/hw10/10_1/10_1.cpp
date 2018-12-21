#include <iostream>
#include <fstream>
#include "matrix.h"
#include "aStar.h"

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int n = 0;
	int m = 0;
	fin >> n >> m;
	Map *map = readMap(fin, n, m);

	fin.close();
	
	int x = 0;
	int y = 0;
	cout << "Enter coordinates of the start point: ";
	cin >> x >> y;
	Coordinates *start = createCoordinates(x - 1, y - 1);

	while (!isCoordinatesCorrect(map, start))
	{
		delete start;
		cout << "Coordinates are not correct for this map.\n\n";
		cout << "Enter coordinates of the start point: ";
		cin >> x >> y;
		start = createCoordinates(x - 1, y - 1);
	}

	cout << "Enter coordinates of the destination point: ";
	cin >> x >> y;
	Coordinates *destination = createCoordinates(x - 1, y - 1);

	while (!isCoordinatesCorrect(map, destination))
	{
		delete destination;
		cout << "Coordinates are not correct for this map.\n\n";
		cout << "Enter coordinates of the destination point: ";
		cin >> x >> y;
		destination = createCoordinates(x - 1, y - 1);
	}

	aStar(map, start, destination);
	cout << endl;

	deleteMap(map);
	deleteCoordinates(start);
	deleteCoordinates(destination);

	return 0;
}
