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
	int min;

	for (int i = 0; i < MAX - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < MAX; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		if (min != i)
			swap(&arr[i], &arr[min]);
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