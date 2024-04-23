#include <stdio.h>
#define MAX 10

void printArr(int arr[])
{
	for (int i = 0; i < MAX; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sort(int arr[])
{
	int i, j, key;
	for (i = 1; i < MAX; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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