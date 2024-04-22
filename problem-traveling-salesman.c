#include <stdio.h>
#define N 4

int minDist = 1000;
int totalDist = 0;
int graph[N][N] = {
	{0, 4, 2, 5},
	{3, 0, 1, 6},
	{4, 7, 0, 1},
	{4, 7, 9, 0},
};

void TSP(int path[], int visited[], int minPath[], int n)
{
	// exit case
	if (n == 0)
	{
		// add up all the distances
		totalDist = 0;
		for (int i = 0; i < N - 1; i++)
			totalDist += graph[path[i]][path[i + 1]];
		totalDist += graph[path[N - 1]][path[0]]; // return to start

		// if this distance is less than minDist, replace new minimum path
		if (totalDist < minDist)
		{
			minDist = totalDist;
			for (int i = 0; i < N; i++)
				minPath[i] = path[i];
		}

		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			path[n - 1] = i;
			visited[i] = 1;

			TSP(path, visited, minPath, n - 1);

			visited[i] = 0;
		}
	}
}

void main()
{
	int path[N], visited[N], minPath[N];

	for (int i = 0; i < N; i++)
		path[i] = visited[i] = minPath[i] = 0;

	TSP(path, visited, minPath, N);

	printf("\nMinimum distance: %d", minDist);
	printf("\nMinimum path: ");

	for (int i = 0; i < N; i++)
		printf("%d ", minPath[i] + 1);
	printf("\n");
}