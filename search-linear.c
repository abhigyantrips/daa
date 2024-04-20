#include <stdio.h>
#define MAX 5

void search(int arr[], int key)
{
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i] == key)
		{
			printf("Linear Search: Key @ index %d", i);
			return;
		}
	}

	printf("Linear Search: Key not found.");
}

void main()
{
	int arr[MAX] = {5, 7, 2, 4, 9};

	search(arr, 9);
}