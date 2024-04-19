#include <stdio.h>

void towers(int n, char src, char aux, char dest)
{
	if (n == 1)
	{
		printf("\nmove disk 1 from %c to %c", src, dest);
		return;
	}

	towers(n - 1, src, dest, aux);
	printf("\nmove disk %d from %c to %c", n, src, dest);
	towers(n - 1, aux, src, dest);
}

void main()
{
	int n;

	printf("Enter number of disks: ");
	scanf("%d", &n);
	towers(n, 'A', 'B', 'C');
}