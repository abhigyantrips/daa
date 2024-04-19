#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void main()
{
	int a = 12;
	int b = 24;

	printf("GCD is: %d", gcd(a, b));
}