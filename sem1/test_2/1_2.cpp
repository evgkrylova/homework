#include <iostream>
#include <fstream>

using namespace std;

int strlen(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}

	return counter;
}


void counterOfLetters(int *&symbols, char string[])
{
	int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		int element = string[i];
		if (((int)(element) >= 97) && ((int)(element) <= 122))
		{
			symbols[(int)(string[i]) - 97]++;
		}
	}
}

int main()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");

	const int stringLength = 10000;
	char string[stringLength];

	int *letters = new int[26];
	for (int i = 0; i < 26; i++)
	{
		letters[i] = 0;
	}

	while (fin.getline(string, stringLength))
	{
		counterOfLetters(letters, string);
	}

	for (int i = 0; i < 26; i++)
	{
		if (letters[i] != 0)
		{
			fout << (char)(i + 97) << ": " << letters[i] << endl;
		}
	}

	fout.close();
	fin.close();

	delete[] letters;

	return 0;
}
