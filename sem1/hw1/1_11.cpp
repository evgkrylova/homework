#include <iostream>

using namespace std;

void quickSort(int *numbers, int left, int right)
{
	int leftHold = left;
	int rightHold = right;
	int comparing = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= comparing) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= comparing) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = comparing;
	comparing = left;
	left = leftHold;
	right = rightHold;
	if (left < comparing)
		quickSort(numbers, left, comparing - 1);
	if (right > comparing)
		quickSort(numbers, comparing + 1, right);
}

int main()
{
	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;

	int list[100000];
	cout << "Enter elements of the list: ";
	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}

	quickSort(list, 0, size - 1);

	cout << "Sorted version of this list: ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	return 0;
}
