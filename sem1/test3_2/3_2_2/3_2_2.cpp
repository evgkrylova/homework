#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

int main() 
{
	Queue *queue = createQueue();

	cout << "Hello. It is programme called 'Priority queue'.\n";
	cout << "Enter:   0 - if you want to exit;\n";
	cout << "\t 1 - if you want to add an element;\n";
	cout << "\t 2 - if you want to get an element with maximal priority;\n";
	cout << "\nYour command: ";

	int choice = -1;
	cin >> choice;

	int element = 0;
	int priority = 0;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			
			cout << "Enter new element: ";
			cin >> element;

			cout << "Enter its priority: ";
			cin >> priority;

			enqueue(element, priority, queue);
			break;

		case 2:
			cout << "Element with maximal priority: " << dequeue(queue);
			cout << endl;
			break;
		}

		cout << "The process was successfully completed.\n\nYour next command: ";
		cin >> choice;
	}

	deleteQueue(queue);

	return 0;
}
