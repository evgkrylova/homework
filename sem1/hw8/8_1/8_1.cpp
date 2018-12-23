#include <iostream>
#include "list.h"

using namespace std;

struct Student
{
	int number;
	Student *whoCopiedFrom;
};

const int amountOfCleverStudents = 3;

int findAuthorNumber(Student *student)
{
	while (student->whoCopiedFrom)
	{
		student = student->whoCopiedFrom;
	}
	return student->number;
}

bool isStudentClever(Student *student)
{
	return ((student->number >= 1) && (student->number <= 3));
}

int main()
{
	int totalAmount = 0;
	cout << "Enter the amount of students: ";
	cin >> totalAmount;

	Student **listOfStudents = new Student*[totalAmount];
	List *toExpelling = createList();

	listOfStudents[0] = new Student{ 1, nullptr };
	listOfStudents[1] = new Student{ 2, nullptr };
	listOfStudents[2] = new Student{ 3, nullptr };

	for (int i = amountOfCleverStudents; i < totalAmount; i++)
	{
		listOfStudents[i] = new Student{ i, nullptr };
	}

	for (int i = amountOfCleverStudents; i < totalAmount; i++)
	{
		int number = -1;
		cout << endl << "Enter the number of the current student: ";
		cin >> number;

		int numberOfOriginal = 0;
		cout << "Enter the number of student who he/she has copied from: ";
		cin >> numberOfOriginal;

		if (numberOfOriginal == -1)
		{
			add(toExpelling, number);
		}
		else
		{
			listOfStudents[number - 1]->whoCopiedFrom = listOfStudents[numberOfOriginal - 1];
		}
	}

	for (int i = 0; i < totalAmount; i++)
	{
		if ((listOfStudents[i]->whoCopiedFrom) || (isStudentClever(listOfStudents[i])))
		{
			cout << endl << "The number of student: " << i + 1 << endl;
			cout << "The original solve: " << findAuthorNumber(listOfStudents[i]) << endl;

		}
	}

	if (size(toExpelling))
	{
		cout << endl << "These students should be expelled: ";
		print(toExpelling);
	}

	for (int i = 0; i < totalAmount; i++)
	{
		delete listOfStudents[i];
	}
	delete[] listOfStudents;

	deleteList(toExpelling);
	return 0;
}

