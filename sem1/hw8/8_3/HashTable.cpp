#include <iostream>
#include "HashTable.h"
#include "HWstring.h"

const int hashTableSize = 1024;
const int primeNumber = 19;

HashTable *createHashTable()
{
	return new HashTable{ new Bucket*[hashTableSize] {nullptr}, 0 };
}

void deleteHashTable(HashTable *table)
{
	if (!table)
	{
		return;
	}

	if (table->bucket)
	{
		for (int i = 0; i < hashTableSize; ++i)
		{
			if (table->bucket[i])
			{
				deleteString(table->bucket[i]->word);
				delete table->bucket[i];
			}
		}
		delete[] table->bucket;
	}
	delete table;
}

int hashKey(String *string)
{
	int key = 0;

	for (int i = 0; i < length(string); i++)
	{
		char currentSymbol = string->symbols[i];
		key = (key * primeNumber + currentSymbol) % hashTableSize;
	}

	return key;
}

void quadraticProbing(int &key, int attemptNumber)
{
	key = (key + attemptNumber * attemptNumber) % hashTableSize;
}

double loadFactor(HashTable *table)
{
	return (double)table->wordsNumber / hashTableSize;
}

int maximumAttemptsNumber(HashTable *table)
{
	if (!table || !table->bucket)
	{
		return 0;
	}

	int currentMaximum = 0;

	for (int i = 0; i < hashTableSize; i++)
	{
		if (table->bucket[i])
		{
			int currentAttemptsNumber = table->bucket[i]->attemptsNumber;
			currentMaximum = (currentMaximum < currentAttemptsNumber) ? currentAttemptsNumber : currentMaximum;
		}
	}

	return currentMaximum;
}

double averageAttemptsNumber(HashTable *table)
{
	int attemptsSum = 0;

	for (int i = 0; i < hashTableSize; i++)
	{
		if (table->bucket[i])
		{
			attemptsSum += table->bucket[i]->attemptsNumber;
		}
	}

	return (double)attemptsSum / table->wordsNumber;
}

void printWordsWithMaximumAttemptsNumber(HashTable *table)
{
	int maximum = maximumAttemptsNumber(table);

	for (int i = 0; i < hashTableSize; ++i)
	{
		if ((table->bucket[i]) && (table->bucket[i]->attemptsNumber == maximum))
		{
			std::cout << '\n';
			String *string = table->bucket[i]->word;
			printString(string);
		}
	}
}

int wordsNumber(HashTable *table)
{
	return table->wordsNumber;
}

int emptyBucketsCellsNumber(HashTable *table)
{
	return hashTableSize - table->wordsNumber;
}

bool isWordInTable(HashTable *table, String *string)
{
	int key = hashKey(string);
	String *storingWord = table->bucket[key]->word;

	int attemptNumber = 1;
	do
	{
		quadraticProbing(key, attemptNumber);
		attemptNumber++;
		storingWord = table->bucket[key]->word;
	} while (!areEqual(storingWord, string) && !isEmpty(storingWord));

	return areEqual(storingWord, string);
}

void addWord(HashTable *table, String *string)
{
	int key = hashKey(string);

	if (!table->bucket[key])
	{
		table->bucket[key] = new Bucket{ nullptr, 0, 0 };
		table->bucket[key]->word = string;
		table->bucket[key]->sameOnesNumber++;
		table->bucket[key]->attemptsNumber++;
		table->wordsNumber++;

		return;
	}

	if (areEqual(table->bucket[key]->word, string))
	{
		table->bucket[key]->sameOnesNumber++;
		deleteString(string);
		return;
	}

	int attemptNumber = 1;
	do
	{
		quadraticProbing(key, attemptNumber);
		attemptNumber++;
	} while (!isEmpty(table->bucket[key]->word));

	table->bucket[key]->word = string;
	table->bucket[key]->sameOnesNumber++;
	table->bucket[key]->attemptsNumber += attemptNumber;
	table->wordsNumber++;
}


void printHashTable(HashTable *table)
{
	for (int i = 0; i < hashTableSize; ++i)
	{
		if (table->bucket[i])
		{
			std::cout << '\n';
			printString(table->bucket[i]->word);
			std::cout << ": " << table->bucket[i]->sameOnesNumber;
		}
	}
}

