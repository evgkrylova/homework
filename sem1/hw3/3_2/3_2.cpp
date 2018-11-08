#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
	char firstString[100000];
	cout << "Enter the first string: ";
	cin >> firstString;

	char secondString[100000];
	cout << "Enter the second string: ";
	cin >> secondString;

	int firstLength = strlen(firstString);
	int secondLength = strlen(secondString);

	if (firstLength != secondLength)
	{
		cout << "These stings are not anagrams.";
		return 0;
	}

	int* firstList = new int[firstLength];
	for (int i = 0; i < firstLength; i++)
	{
		firstList[i] = (int)(firstString[i]);
	}
	int* secondList = new int[secondLength];
	for (int i = 0; i < secondLength; i++)
	{
		secondList[i] = (int)(secondString[i]);
	}
	quickSort(firstList, 0, firstLength - 1);
	quickSort(secondList, 0, secondLength - 1);
	int i = 0;
	while ((firstList[i] == secondList[i]) && (i < firstLength))
	{
		i++;
	}
	if (i == firstLength)
	{
		cout << "These stings are anagrams.";
	}
	else 
	{
		cout << "These stings are not anagrams.";
	}

	delete[] firstList;
	delete[] secondList;

	return 0;
}

