#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	static int opCount = 1;

	if (n == 0 || n == 1)
	{
		printf("\nOperation Count: %d", opCount);
		opCount = 1;
		return 1;
	}

	opCount++;

	return n * factorial(n - 1);
}

void main()
{
	int n = 5;

	printf("\nFactorial of %d: %d", n, factorial(n));
}