#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HWstring.h"

using namespace std;

const int maxWordLength = 256;

bool isLetter(char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
	{
		return true;
	}
	return false;
}

void readWord(ifstream &fin, HashTable *table)
{
	char *word = new char[maxWordLength];
	int index = 0;
	char currentSymbol = '\0';

	while ((!fin.eof()) && (isLetter(fin.peek()) || index == 0))
	{
		fin.get(currentSymbol);
		if (isLetter(currentSymbol))
		{
			word[index] = currentSymbol;
			index++;
		}
	}

	if (index > 0)
	{
		addWord(table, new String{ index, word });
	}

	else
	{
		delete[] word;
	}
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	HashTable *table = createHashTable();

	while (!fin.eof())
	{
		readWord(fin, table);
	}

	int choice = -1;
	cout << "Enter the command if you want:\n\t 0 - to exit;\n";
	cout << "\t 1 - to print 'load factor';\n";
	cout << "\t 2 - to print the maximum of words' numbers of attempts while adding;\n";
	cout << "\t 3 - to print these words;\n";
	cout << "\t 4 - to print the average of these values;\n";
	cout << "\t 5 - to print how many different words file includes;\n";
	cout << "\t 6 - to print the number of empty buckets cells in the Hash Table\n";
	cout << "\nYour command: ";
	cin >> choice;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "Load factor: " << loadFactor(table);
			break;
		case 2:
			cout << "Maximum of attempts: " << maximumAttemptsNumber(table);
			break;
		case 3:
			cout << "Words with maximum of attempts: ";
			printWordsWithMaximumAttemptsNumber(table);
			break;
		case 4:
			cout << "Average of attempts: " << averageAttemptsNumber(table);
			break;
		case 5:
			cout << "Number of words: " << wordsNumber(table);
			break;
		case 6:
			cout << "Number of empty buckets' cells: " << emptyBucketsCellsNumber(table);
			break;
		}

		cout << "\nThe process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deleteHashTable(table);
	fin.close();

	return 0;
}
