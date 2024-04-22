#include <stdio.h>
#define MAX 5

int result[MAX];
int maxProfit = 0;
int maxWeight = 10;

int sum(int arr[])
{
	int sum = 0;

	for (int i = 0; i < MAX; i++)
		sum += arr[i];

	return sum;
}

void knapsack(int values[], int weights[])
{
	int n = 1 << MAX;

	for (int i = 0; i < MAX; i++)
	{
		int k = 0;
		int testValues[MAX] = {0, 0, 0, 0, 0};
		int testWeights[MAX] = {0, 0, 0, 0, 0};

		for (int j = 0; j < MAX; j++)
		{
			if (i & (1 << j))
			{
				testValues[k] = values[j];
				testWeights[k] = weights[j];
				k++;
			}
		}

		if (sum(testValues) > maxProfit && sum(testWeights) <= maxWeight)
		{
			maxProfit = sum(testValues);
			for (int j = 0, k = 0; k < MAX; k++)
			{
				if (testValues[k])
				{
					result[j] = testValues[k];
					j++;
				}
			}
		}
	}
}

void main()
{
	int values[] = {2, 3, 4, 5, 6};
	int weights[] = {1, 3, 5, 6, 7};
	knapsack(values, weights);

	printf("\nMax Profit: %d", maxProfit);
	printf("\nChosen Values: ");

	int length = sizeof(result) / sizeof(result[0]);
	for (int i = 0; i < length; i++)
	{
		if (result[i] == 0)
		{
			break;
		}
		printf("%d ", result[i]);
	}
	printf("\n");
}