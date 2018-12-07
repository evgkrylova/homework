#include <iostream>
#include "HWstring.h"

using namespace std;

int main()
{
	String *string = createString();
	String *secondString = createString();

	cout << "Hello. This programme works with data structures called 'String'.\n";
	cout << "Enter the command if you want:\n\t 0 - to exit;\n";
	cout << "\t 1 - to enter the string.\n";
	cout << "Your command: ";

	int choice = -1;
	cin >> choice;

	if (!choice)
	{
		return 0;
	}

	cout << "\nEnter the string: ";
	readString(string);

	cout << "Enter the command if you want:\n\t 0 - to exit;\n";
	cout << "\t 1 - to print the string;\n";
	cout << "\t 2 - to print the length of the string;\n";
	cout << "\t 3 - to clone the string and print the result;\n";
	cout << "\t 4 - to enter one more string and concatenate it with the first one;\n";
	cout << "\t 5 - to enter one more string and compare it with the first one;\n";
	cout << "\t 6 - to print a substring.\n";
	cout << "\nYour command: ";

	cin >> choice;
	

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "String: ";
			printString(string);
			break;
		case 2:
			cout << "Length: " << length(string);
			break;
		case 3:
			cout << "Clone: ";
			printString(clone(string));
			break;
		case 4:
			cout << "Enter the second string: ";
			readString(secondString);
			cout << "Concatination: ";
			printString(concatenate(string, secondString));
			break;
		case 5:
			cout << "Enter the second string: ";
			readString(secondString);
			cout << "Result of comparing: strings are ";
			if (!areEqual(string, secondString))
			{
				cout << "not ";
			}
			cout << "the same.";
			break;
		case 6:
			int firstSymbol = -1;
			cout << "Enter a number of the first symbol: ";
			cin >> firstSymbol;
			int lastSymbol = -1;
			cout << "Enter a number of the last symbol: ";
			cin >> lastSymbol;
			cout << "Substring: ";
			printString(getSubstring(string, firstSymbol, lastSymbol));
			break;
		}

		cout << "\nThe process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deleteString(string);
	return 0;
}

