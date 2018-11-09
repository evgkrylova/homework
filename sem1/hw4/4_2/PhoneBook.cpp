#include <iostream>
#include <fstream>
#include "list.h"
#include "PhoneBook.h"

using namespace std;

void getNumber(List *book)
{
	char* name = new char[100];
	cout << "Enter the name whose number you wnat to know: ";
	cin >> name;
	cout << "This person's number: " << getNumberByName(book, name) << endl;
}

void getName(List *book)
{
	char* number = new char[100];
	cout << "Enter the number to know who owns it: ";
	cin >> number;
	cout << "The owner of the number: " << getNameByNumber(book, number) << endl;
}

void addSubscriber(List *book)
{
	char* name = new char[100];
	cout << "Enter the name of subscriber you want to add: ";
	cin >> name;

	char* number = new char[100];
	cout << "Enter the number of subscriber you want to add: ";
	cin >> number;

	addToList(book, name, number);
}

void getBookFromFile(List *book)
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

		addToList(book, name, number);
		char* space = new char[1];
		fin.getline(space, 1);
	}
	fin.close();
}

void saveBookToFile(List *book)
{
	ofstream fout;
	fout.open("output.txt");
	
	for (int i = 0; i < listSize(book); i++)
	{
		fout << getNameByIndex(book, i) << endl;
		fout << getNumberByIndex(book, i) << endl << endl;
	}
	fout.close();
}

