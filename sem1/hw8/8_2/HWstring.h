#pragma once

struct String
{
	int length;
	char *symbols;
};

String *createString();
void readString(String *string);
void deleteString(String *string);

String *clone(String *string);
String *concatenate(String *firstString, String *secondString);
bool areEqual(String *firstString, String *secondString);
int length(String *string);
bool isEmpty(String *string);
String *getSubstring(String *string, int begin, int end);
char *convertToChar(String *string);

void printString(String *string);
