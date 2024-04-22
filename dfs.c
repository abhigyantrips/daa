#include <stdio.h>
#define MAX 4

int graph[MAX][MAX] = {
	{0, 1, 1, 0},
	{1, 0, 0, 0},
	{1, 1, 0, 1},
	{1, 1, 1, 0},
};
int visited[MAX] = {0, 0, 0, 0};

void dfs(int i)
{
	printf("%d ", i);
	visited[i] = 1;
	for (int j = 0; j < MAX; j++)
	{
		if (graph[i][j] && !visited[j])
			dfs(j);
	}
}

void main()
{
	for (int i = 0; i < MAX; i++)
	{
		if (!visited[i])
			dfs(i);
	}
}