#include <stdio.h>

void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

void sort(int arr[], int n)
{
	int output[n + 1];
	int max = getMax(arr, n);
	int count[max + 1];

	for (int i = 0; i <= max; i++) // initialize to zero
		count[i] = 0;

	for (int i = 0; i < n; i++) // store count of each element
		count[arr[i]]++;

	for (int i = 1; i <= max; i++) // find cumulative frequency
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--; // decrease count for same numbers
	}

	for (int i = 0; i < n; i++) // store sorted elements back into array
		arr[i] = output[i];
}

void main()
{
	int arr[] = {4, 5, 0, 4, 9, 7, 9, 2, 0, 3};
	int n = 10;

	printf("\n--- INPUT ARRAY ---\n");
	printArr(arr, n);
	printf("\n--- SORTED ARRAY ---\n");
	sort(arr, n);
	printArr(arr, n);
}