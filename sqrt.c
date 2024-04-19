#include <stdio.h>

int squareRoot(int n)
{
	if (n < 0)
		// error case
		return -1;

	if (n == 0 || n == 1)
		return n;

	int i = 1;

	while (i * i < n)
		i++;

	if (i * i == n)
		return i;
	else
		// not found case
		return -2;
}

void main()
{
	int n = 16;
	int root = squareRoot(n);

	if (root == -1)
		printf("\nERROR | Negative input.");
	else if (root == -2)
		printf("\nERROR | Not found.");
	else
		printf("\nSquare root: %d", root);
}