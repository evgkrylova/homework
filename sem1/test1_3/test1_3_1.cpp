#include <iostream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	char currentSymbol = '\0';
	char nextSymbol = '\0';
	while (fin.peek() != EOF)
	{
		fin.get(currentSymbol);
		if (currentSymbol == '/')
		{
			fin.get(nextSymbol);

			if (nextSymbol == '*')
			{
				while ((currentSymbol != '*') || (nextSymbol != '/'))
				{
					currentSymbol = nextSymbol;
					fin.get(nextSymbol);
				}
				continue;
			}
			
			if (nextSymbol == '/')
			{
				do
				{
					fin.get(currentSymbol);
					cout << currentSymbol;
				} while (currentSymbol != '\n');
			}
		}
	}
	fin.close();
	return 0;
}

