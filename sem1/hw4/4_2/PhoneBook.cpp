#include <iostream>
#include <fstream>
#include "list.h"
#include "PhoneBook.h"

using namespace std;

PhoneBook *createPhoneBook()
{
	PhoneBook *phoneBook = new PhoneBook{ nullptr };
	List *list = createList();
	phoneBook->body = list;
	return phoneBook;
}

void deletePhoneBook(PhoneBook *phoneBook)
{
	deleteList(phoneBook->body);
	delete phoneBook;
}

void getNumber(PhoneBook *phoneBook)
{
	char* name = new char[100];
	cout << "Enter the name whose number you wnat to know: ";
	cin >> name;

	if (getNumberByName(phoneBook->body, name))
	{
		cout << "This person's number: " << getNumberByName(phoneBook->body, name) << endl;
		delete[] name;
		return;
	}

	delete[] name;
	cout << "There is not this person in the phone book.\n";
}

void getName(PhoneBook *phoneBook)
{
	char* number = new char[100];
	cout << "Enter the number to know who owns it: ";
	cin >> number;

	if (getNameByNumber(phoneBook->body, number))
	{
		cout << "The owner of the number: " << getNameByNumber(phoneBook->body, number) << endl;
		delete[] number;
		return;
	}

	delete[] number;
	cout << "There is not this number in the phone book.\n";
}

void addSubscriber(PhoneBook *phoneBook)
{
	char* name = new char[100];
	cout << "Enter the name of subscriber you want to add: ";
	cin >> name;

	char* number = new char[100];
	cout << "Enter the number of subscriber you want to add: ";
	cin >> number;

	addToList(phoneBook->body, name, number);
}

void getBookFromFile(PhoneBook *phoneBook)
{
	ifstream fin;
	fin.open("input.txt");

	if (!fin)
	{
		return;
	}

	while (!(fin.eof()))
	{
		char* name = new char[100];
		fin.getline(name, 100);

		char* number = new char[100];
		fin.getline(number, 100);

		addToList(phoneBook->body, name, number);
		char space = '\0';
		fin.get(space);
	}

	fin.close();
}

void saveBookToFile(PhoneBook *phoneBook)
{
	ofstream fout;
	fout.open("input.txt");

	for (int i = 0; i < listSize(phoneBook->body); i++)
	{
		fout << getNameByIndex(phoneBook->body, i) << endl;
		fout << getNumberByIndex(phoneBook->body, i) << endl << endl;
	}

	fout.close();
}

