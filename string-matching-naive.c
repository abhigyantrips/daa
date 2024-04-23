#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void match(char *text, char *pattern)
{
	int m = strlen(text);
	int n = strlen(pattern);

	for (int i = 0; i < m - n + 1; i++)
	{
		int j;
		for (j = 0; j < n; j++)
			if (text[i + j] != pattern[j])
				break;

		if (j == n)
			printf("\nPattern found at index %d", i);
	}
}

void main()
{
	char text[] = "This is a test";
	char pattern[] = "tes";

	match(text, pattern);
}