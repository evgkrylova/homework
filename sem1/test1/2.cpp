#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the number of Petya's notes: ";
	int lengthPetya = 0;
	cin >> lengthPetya;

	cout << "Enter the list of Petya's notes' complexity: ";
	int* listPetya = new int[lengthPetya];
	for (int i = 0; i < lengthPetya; i++)
	{
		cin >> listPetya[i];
	}

	cout << "Enter the number of Vasya's notes: ";
	int lengthVasya = 0;
	cin >> lengthVasya;

	cout << "Enter the list of Vasya's notes' complexity: ";
	int* listVasya = new int[lengthVasya];
	for (int i = 0; i < lengthVasya; i++)
	{
		cin >> listVasya[i];
	}

	int indexTotal = 0;
	int indexPetya = 0;
	int indexVasya = 0;

	cout << "There is the total list of notes: \n";

	while ((indexPetya < lengthPetya) || (indexVasya < lengthVasya))
	{
		if (listPetya[indexPetya] > listVasya[indexVasya])
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
		}
		else if (listPetya[indexPetya] < listVasya[indexVasya])
		{
			cout << listVasya[indexVasya] << " ";
			indexVasya++;
		}
		else
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
			indexVasya++;
		}
		indexTotal++;
	}


	delete listPetya;
	delete listVasya;

	return 0;
}
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the number of Petya's notes: ";
	int lengthPetya = 0;
	cin >> lengthPetya;

	cout << "Enter the list of Petya's notes' complexity: ";
	int* listPetya = new int[lengthPetya];
	for (int i = 0; i < lengthPetya; i++)
	{
		cin >> listPetya[i];
	}

	cout << "Enter the number of Vasya's notes: ";
	int lengthVasya = 0;
	cin >> lengthVasya;

	cout << "Enter the list of Vasya's notes' complexity: ";
	int* listVasya = new int[lengthVasya];
	for (int i = 0; i < lengthVasya; i++)
	{
		cin >> listVasya[i];
	}

	int indexTotal = 0;
	int indexPetya = 0;
	int indexVasya = 0;

	cout << "There is the total list of notes: \n";

	while ((indexPetya < lengthPetya) || (indexVasya < lengthVasya))
	{
		if (listPetya[indexPetya] > listVasya[indexVasya])
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
		}
		else if (listPetya[indexPetya] < listVasya[indexVasya])
		{
			cout << listVasya[indexVasya] << " ";
			indexVasya++;
		}
		else
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
			indexVasya++;
		}
		indexTotal++;
	}


	delete listPetya;
	delete listVasya;

	return 0;
}
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the number of Petya's notes: ";
	int lengthPetya = 0;
	cin >> lengthPetya;

	cout << "Enter the list of Petya's notes' complexity: ";
	int* listPetya = new int[lengthPetya];
	for (int i = 0; i < lengthPetya; i++)
	{
		cin >> listPetya[i];
	}

	cout << "Enter the number of Vasya's notes: ";
	int lengthVasya = 0;
	cin >> lengthVasya;

	cout << "Enter the list of Vasya's notes' complexity: ";
	int* listVasya = new int[lengthVasya];
	for (int i = 0; i < lengthVasya; i++)
	{
		cin >> listVasya[i];
	}

	int indexTotal = 0;
	int indexPetya = 0;
	int indexVasya = 0;

	cout << "There is the total list of notes: \n";

	while ((indexPetya < lengthPetya) || (indexVasya < lengthVasya))
	{
		if (listPetya[indexPetya] > listVasya[indexVasya])
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
		}
		else if (listPetya[indexPetya] < listVasya[indexVasya])
		{
			cout << listVasya[indexVasya] << " ";
			indexVasya++;
		}
		else
		{
			cout << listPetya[indexPetya] << " ";
			indexPetya++;
			indexVasya++;
		}
		indexTotal++;
	}


	delete listPetya;
	delete listVasya;

	return 0;
}
