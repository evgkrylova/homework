#include <iostream>
#include "list.h"
#include "PhoneBook.h"

using namespace std;

int main()
{
	PhoneBook *book = createPhoneBook();
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
		switch (choice)
		{
		case 1:
			addSubscriber(book);
			break;
		case 2:
			getNumber(book);
			break;
		case 3:
			getName(book);
			break;
		case 4:
			saveBookToFile(book);
			break;
		}
		cout << "The process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deletePhoneBook(book);	
	return 0;
}

