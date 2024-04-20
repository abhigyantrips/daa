#include <stdio.h>
#define MAX 10

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArr(int arr[])
{
	for (int i = 0; i < MAX; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sort(int arr[])
{
	int swapped;

	for (int i = 0; i < MAX; i++)
	{
		swapped = 0;

		for (int j = 0; j < MAX - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}

void main()
{
	int arr[] = {4, 5, 3, 7, 2, 8, 6, 1, 9, 0};

	printf("\n--- INPUT ARRAY ---\n");
	printArr(arr);
	printf("\n--- SORTED ARRAY ---\n");
	sort(arr);
	printArr(arr);
}