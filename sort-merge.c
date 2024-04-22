#include <stdio.h>

void printArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int A[], int aLen, int B[], int bLen, int C[], int cLen)
{
	int i = 0, j = 0, k = 0;

	while ((i < aLen) && (j < bLen))
	{
		if (A[i] < B[j])
			C[k] = A[i++];
		else
			C[k] = B[j++];
		k++;
	}

	if (i < aLen)
	{
		while (i < aLen)
		{
			C[k] = A[i++];
			k++;
		}
	}
	else
	{
		while (j < bLen)
		{
			C[k] = B[j++];
			k++;
		}
	}
}

void sort(int arr[], int len)
{
	if (len <= 1)
		return;

	int A[len / 2], B[len / 2];

	for (int i = 0; i < len / 2; i++)
		A[i] = arr[i];

	sort(A, len / 2);

	for (int i = len / 2; i < len; i++)
		B[i - len / 2] = arr[i];

	sort(B, len - len / 2);

	merge(A, len / 2, B, len - len / 2, arr, len);
}

void main()
{
	int arr[] = {4, 5, 3, 7, 2, 8, 6, 1, 9, 0};
	int len = 10;

	printf("\n--- INPUT ARRAY ---\n");
	printArr(arr, len);
	printf("\n--- SORTED ARRAY ---\n");
	sort(arr, len);
	printArr(arr, len);
}