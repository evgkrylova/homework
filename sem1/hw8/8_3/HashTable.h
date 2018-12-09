#pragma once

struct Bucket
{
	String *word;
	int sameOnesNumber;
	int attemptsNumber;
};

struct HashTable
{
	Bucket **bucket;
	int wordsNumber = 0;
};

HashTable *createHashTable();
void deleteHashTable(HashTable *table);

int hashKey(String *string);
void quadraticProbing(int &key, int attemptNumber);

double loadFactor(HashTable *table);
double averageAttemptsNumber(HashTable *table);
int maximumAttemptsNumber(HashTable *table);
void printWordsWithMaximumAttemptsNumber(HashTable *table);

int wordsNumber(HashTable *table);
int emptyBucketsCellsNumber(HashTable *table);

bool isWordInTable(HashTable *table, String *string);
void addWord(HashTable *table, String *string);


void printHashTable(HashTable *table);

