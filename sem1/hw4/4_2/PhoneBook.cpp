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

void getNumber(PhoneBook *phoneBook)
{
	List *book = phoneBook->body;

	char* name = new char[100];
	cout << "Enter the name whose number you wnat to know: ";
	cin >> name;
	if (getNumberByName(book, name))
	{
		cout << "This person's number: " << getNumberByName(book, name) << endl;
		return;
	}
	cout << "There is not this person in the phone book.\n";
}

void getName(PhoneBook *phoneBook)
{
	List *book = phoneBook->body;

	char* number = new char[100];
	cout << "Enter the number to know who owns it: ";
	cin >> number;
	if (getNameByNumber(book, number))
	{
		cout << "The owner of the number: " << getNameByNumber(book, number) << endl;
		return;
	}
	cout << "There is not this number in the phone book.\n";
}

void addSubscriber(PhoneBook *phoneBook)
{
	List *book = phoneBook->body;

	char* name = new char[100];
	cout << "Enter the name of subscriber you want to add: ";
	cin >> name;

	char* number = new char[100];
	cout << "Enter the number of subscriber you want to add: ";
	cin >> number;

	addToList(book, name, number);
}

void getBookFromFile(PhoneBook *phoneBook)
{
	List *book = phoneBook->body;

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

		addToList(book, name, number);
		char* space = new char[1];
		fin.getline(space, 1);
	}
	fin.close();
}

void saveBookToFile(PhoneBook *phoneBook)
{
	List *book = phoneBook->body;

	ofstream fout;
	fout.open("input.txt");

	for (int i = 0; i < listSize(book); i++)
	{
		fout << getNameByIndex(book, i) << endl;
		fout << getNumberByIndex(book, i) << endl << endl;
	}
	fout.close();
}

