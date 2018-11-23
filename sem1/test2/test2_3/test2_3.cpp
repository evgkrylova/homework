#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	cout << "Enter the number 'a': ";
	cin >> a;
	cout << "Enter the number 'b': ";
	cin >> b;

	ifstream fin;
	fin.open("f.txt");
	
	int number = 0;
	List *firstOrder = createList();
	List *secondOrder = createList();
	List *thirdOrder = createList();

	while (fin.peek() != EOF)
	{
		fin >> number;

		if (number < a)
		{
			add(firstOrder, number);
		}
		else if ((number >= a) && (number <= b))
		{
			add(secondOrder, number);
		}
		else
		{
			add(thirdOrder, number);
		}
	}

	fin.close();
	ofstream fout;
	fout.open("g.txt");

	print(firstOrder, fout);
	print(secondOrder, fout);
	print(thirdOrder, fout);

	fout.close();
	deleteList(firstOrder);
	deleteList(secondOrder);
	deleteList(thirdOrder);

    return 0;
}

