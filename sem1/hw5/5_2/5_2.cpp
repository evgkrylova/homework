#include <iostream>
#include <fstream>

using namespace std;

bool isLowercaseLetter(char symbol)
{
	int code = (int)(symbol);
	return (code >= (int)('a')) && (code <= (int)('z'));
}

bool isCapitalLetter(char symbol)
{
	int code = (int)(symbol);
	return (code >= (int)('A')) && (code <= (int)('Z'));
}

void cleanArray(bool *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = false;
	}
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	bool isWordRead = false;
	int const lettersAmount = 26;
	bool *letters = new bool[lettersAmount];

	for (int i = 0; i < lettersAmount; i++)
	{
		letters[i] = false;
	}
	char symbol = '\0';

	while (!fin.eof())
	{
		fin.get(symbol);
		int symbolNumber = (int)(symbol) - (isLowercaseLetter(symbol) ? (int)('a') : (int)('A'));

		if ((isCapitalLetter(symbol)) || ((isLowercaseLetter(symbol)) & (!letters[symbolNumber])))
		{
			letters[symbolNumber] = true;
			cout << symbol;
			isWordRead = false;
		}

		if (((isspace(symbol)) || (!isprint(symbol)) || (symbol == '-') || (symbol == '’')) & (!isWordRead))
		{
			cleanArray(letters, lettersAmount);
			cout << endl;
			isWordRead = true;
		}
	}

	fin.close();
	delete[] letters;

	return 0;
}

