#include <stdio.h>
#define MAX 10

void linearSearch(int arr[], int key);
void binarySearch(int arr[], int key, int low, int high);

void main()
{
	int linearArr[] = {1, 4, 6, 2, 5, 8, 7, 3, 9, 0};
	int binaryArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	linearSearch(linearArr, 8);
	binarySearch(binaryArr, 16, 0, MAX);
}

void linearSearch(int arr[], int key)
{
	for (int i = 0; i < MAX; i++)
	{
		if (key == arr[i])
		{
			printf("\nLinear Search found key at index %d.", i);
			return;
		}
	}
	printf("\nLinear Search couldn't find key.");
}

void binarySearch(int arr[], int key, int low, int high)
{
	if (low > high)
	{
		printf("\nBinary Search couldn't find key.");
		return;
	}

	int mid = (low + high) / 2;

	if (arr[mid] == key)
	{
		printf("\nBinary Search found key at index %d.", mid);
		return;
	}
	else if (arr[mid] > key)
		binarySearch(arr, key, low, mid + 1);
	else
		binarySearch(arr, key, mid + 1, high);
}