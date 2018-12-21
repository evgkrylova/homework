#pragma once

struct String
{
	int length;
	char *symbols;
};

String *createString(char *symbols);
void readString(String *&string);
void deleteString(String *&string);

String *clone(String *string);
bool areEqual(String *firstString, String *secondString);
int length(String *string);
bool isEmpty(String *string);
String *getSubstring(String *string, int begin, int end);
char *convertToChar(String *string);
int stringLength(String *string);
char getChar(String *string, int index);

void printString(String *string);
