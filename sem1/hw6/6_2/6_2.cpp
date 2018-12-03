#include <iostream>
#include "binary.h"

using namespace std;

int main()
{
	int firstSummand = 0;
	cout << "Enter the first summand: ";
	cin >> firstSummand;

	int secondSummand = 0;
	cout << "Enter second summand: ";
	cin >> secondSummand;

	cout << endl;

	int *firstBinorySummand = getBinaryNotation(firstSummand);
	int *secondBinorySummand = getBinaryNotation(secondSummand);

	cout << "The binary notation of the first summand: ";
	printArray(firstBinorySummand, bitsNumber);
	cout << "The binary notation of the second summand: ";
	printArray(secondBinorySummand, bitsNumber);

	int *sum = getSumOfBinaryNotations(firstBinorySummand, secondBinorySummand);
	cout << endl;
	cout << "The sum in binary notation: ";
	printArray(sum, bitsNumber);
	cout << "The sum in decimal notation: ";
	cout << getDecimalNotation(sum);

	delete[] sum;
	delete[] firstBinorySummand;
	delete[] secondBinorySummand;

	return 0;
}

