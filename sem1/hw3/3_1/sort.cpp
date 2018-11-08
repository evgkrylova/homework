#include "sort.h"

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

