#include <iostream>

using namespace std;

void quickSort(int *numbers, int left, int right)
{
	int comparing;
	int leftHold = left;
	int rightHold = right;
	comparing = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= comparing) && (left < right))
			right--;
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
	int* a = new int[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = i;
	}
	a[0] = 4;
	a[1] = 1;
	a[2] = 6;
	a[3] = 5;
	quickSort(a, 0, 3);
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
