#include <stdio.h>
#define MAX 5

void search(int arr[], int key, int low, int high)
{
	if (low > high)
	{
		printf("Binary Search: Key not found.");
		return;
	}

	int mid = (low + high) / 2;

	if (arr[mid] == key)
	{
		printf("Binary Search: Key @ index %d", mid);
		return;
	}
	else if (arr[mid] > key)
		search(arr, key, mid + 1, high);
	else
		search(arr, key, low, mid + 1);
}

void main()
{
	int arr[MAX] = {1, 3, 5, 7, 9};

	search(arr, 7, 0, MAX + 1);
}