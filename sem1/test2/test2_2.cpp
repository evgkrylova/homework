#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool isDigit(char c)
{
	int code = (int)(c);
	if (code >= (int)('0') && code <= (int)('9'))
	{
		return true;
	}
	return false;
}

bool dateExists(int day, int month, int year)
{
	if ((year % 4 == 0) && (day == 29) && (month == 2))
	{
		return true;
	}

	if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day <= 31))
	{
		return true;
	}

	if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day <= 30))
	{
		return true;
	}

	if ((day <= 28) && (month == 2))
	{
		return true;
	}

	return false;
}

bool isDate(char *word)
{
	if (strlen(word) == 10)
	{
		if ((isDigit(word[0]) && isDigit(word[1]) && isDigit(word[3]) && isDigit(word[4]) && isDigit(word[6]) && isDigit(word[7]) && isDigit(word[8]) && isDigit(word[9])) && ((word[2] == '.') && (word[5] == '.')))
		{
			int day = ((int)(word[0]) - (int)('0')) * 10 + ((int)(word[1]) - (int)('0'));
			int month = ((int)(word[3]) - (int)('0')) * 10 + ((int)(word[4]) - (int)('0'));
			int year = ((int)(word[8]) - (int)('0')) * 10 + ((int)(word[9]) - (int)('0'));
			if (dateExists(day, month, year))
			{
				return true;
			}
		}
	}
	return false;
}

char *minimal(char *min, char *current)
{
	int minDay = ((int)(min[0]) - (int)('0')) * 10 + ((int)(min[1]) - (int)('0'));
	int currentDay = ((int)(current[0]) - (int)('0')) * 10 + ((int)(current[1]) - (int)('0'));

	int minMonth = ((int)(min[3]) - (int)('0')) * 10 + ((int)(min[4]) - (int)('0'));
	int currentMonth = ((int)(current[3]) - (int)('0')) * 10 + ((int)(current[4]) - (int)('0'));

	int minYear = ((int)(min[6]) - (int)('0')) * 1000 + ((int)(min[7]) - (int)('0')) * 100 + ((int)(min[8]) - (int)('0')) * 10 + ((int)(min[9]) - (int)('0'));
	int currentYear = ((int)(current[6]) - (int)('0')) * 1000 + ((int)(current[7]) - (int)('0')) * 100 + ((int)(current[8]) - (int)('0')) * 10 + ((int)(current[9]) - (int)('0'));

	if (minYear < currentYear)
	{
		return min;
	}

	if (minYear > currentYear)
	{
		return current;
	}

	if (minYear == currentYear)
	{
		if (minMonth < currentMonth)
		{
			return min;
		}

		if (minMonth > currentMonth)
		{
			return current;
		}

		if (minMonth == currentMonth)
		{
			if (minDay < currentDay)
			{
				return min;
			}

			if (minDay > currentDay)
			{
				return current;
			}
		}
	}
	return current;
}

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int const maxLength = 10000;
	int const dateLength = 10;

	char *word = new char[maxLength];
	char *minimalDate = new char[dateLength];
	bool index = true;
	bool isSomethingAlreadyTested = false;

	while (fin.peek() != EOF)
	{
		fin >> word;
		if (isDate(word))
		{
			if (index)
			{
				minimalDate = word;
				index = !index;
				continue;
			}
			minimalDate = minimal(minimalDate, word);
		}
	}

	fin.close();

	if (index)
	{
		cout << "There is no date in the file." << endl;
		return 0;
	}

	cout << "Minimum date is: ";
	for (int i = 0; i < dateLength; ++i)
	{
		cout << minimalDate[i];
	}
	cout << endl;

	delete[] word;
	delete[] minimalDate;

	return 0;
}

