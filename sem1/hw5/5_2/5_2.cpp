#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	bool spaceWasDone = false;
	int const lettersAmount = 26;
	bool *letters = new bool[lettersAmount];

	for (int i = 0; i < lettersAmount; i++)
	{
		letters[i] = false;
	}

	while (!fin.eof())
	{
		char symbol = '_';
		fin.get(symbol);
		int code = (int)(symbol);

		if ((code >= (int)('A')) & (code <= (int)('Z')))
		{
			letters[code - (int)('A')] = true;
			cout << symbol;
			spaceWasDone = false;
		}

		if (((code >= (int)('a')) & (code <= (int)('z'))) & (!letters[code - (int)('a')]))
		{
			letters[code - (int)('a')] = true;
			cout << symbol;
			spaceWasDone = false;
		}

		if (((symbol == ' ') || (symbol == '\n') || (symbol == '\t') || (symbol == '-')) & (!spaceWasDone))
		{
			for (int i = 0; i < lettersAmount; i++)
			{
				letters[i] = false;
			}
			cout << endl;
			spaceWasDone = true;
		}
	}

	fin.close();
	delete[] letters;

	return 0;
}
