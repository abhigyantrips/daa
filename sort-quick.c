#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = start - 1;

	for (int j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	i++;
	swap(&arr[i], &arr[end]);

	return i;
}

void sort(int arr[], int start, int end)
{
	if (end <= start)
		return;

	int pivot = partition(arr, start, end);
	sort(arr, start, pivot - 1);
	sort(arr, pivot + 1, end);
}

void main()
{
	int arr[] = {4, 5, 3, 7, 2, 8, 6, 1, 9, 0};
	int len = 10;

	printf("\n--- INPUT ARRAY ---\n");
	printArr(arr, len);
	printf("\n--- SORTED ARRAY ---\n");
	sort(arr, 0, len - 1);
	printArr(arr, len);
}