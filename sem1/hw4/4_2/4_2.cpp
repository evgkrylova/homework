#include <iostream>
#include "list.h"
#include "PhoneBook.h"

using namespace std;

int main()
{
	List *book = createList();
	getBookFromFile(book);

	cout << "Hello. It is programme called 'Phone Book'.\n";
	cout << "Enter:   0 - if you want to exit;\n";
	cout << "\t 1 - if you want to add a subscriber;\n";
	cout << "\t 2 - if you want to get a number by the name;\n";
	cout << "\t 3 - if you want to get a name by the number;\n";
	cout << "\t 4 - if you want to save the book.\n";
	cout << "\nYour command: ";

	int choice = -1;
	cin >> choice;

	while (choice != 0)
	{
		if (choice == 1)
		{
			addSubscriber(book);
		}
		else if (choice == 2)
		{
			getNumber(book);
		}
		else if (choice == 3)
		{
			getName(book);
		}
		else 
		{
			saveBookToFile(book);
		}
		cout << "The process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	return 0;
}

