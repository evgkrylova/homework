#include <iostream>

using namespace std;

int stringLength(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

bool isStringEmpty(char string[])
{
	int length = stringLength(string);
	for (int i = 0; i < length; i++)
	{
		if ((string[i] != ' ') && (string[i] != '\n') && (string[i] != '\t'))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	FILE *inputFile = fopen("input.txt", "r");
	const int stringLength = 10000;
	char currentString[10000];
	int counter = 0;

	while (fgets(currentString, stringLength, inputFile) != 0)
	{
		if (not isStringEmpty(currentString))
		{
			counter++;
		}
	}

	fclose(inputFile);

	if (counter == 0)
	{
		cout << "There are only empty strings in the file.";
	}
	else if (counter == 1)
	{
		cout << "There is one non-empty string in the file.";
	}
	else
	{
		cout << "There are " << counter << " non-empty strings in the file.";
	}

	return 0;
}
