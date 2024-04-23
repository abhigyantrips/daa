#include <stdio.h>
#define MAX 5

int graph[MAX][MAX] = {
	{1, 0, 1, 1, 0},
	{0, 1, 1, 1, 0},
	{1, 1, 1, 0, 0},
	{1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0},
};
int visited[MAX] = {0, 0, 0, 0, 0};

int queue[MAX] = {0, 0, 0, 0, 0};
int front = 0;
int rear = 0;

void bfs(int i)
{
	for (int j = 0; j < MAX; j++)
	{
		if (graph[i][j] && !visited[j])
		{
			visited[j] = 1;
			printf("%d ", j);
			queue[rear++] = j;
		}
	}

	if (front <= rear)
		bfs(queue[front++]);
}

void main()
{
	printf("0 ");
	visited[0] = 1;
	bfs(0);
}