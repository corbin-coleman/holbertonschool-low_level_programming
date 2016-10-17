#include <stdio.h>

/**
 * main - Print all multiples of 3 & 9 below 1024
 *
 * Return: Return 0
 */
int main(void)
{
	int n, x;

	while (n < 1024)
	{
		if ((n % 3) == 0 || (n % 5) == 0)
		{
			x += n;
		}
		n++;
	}
	printf("%d\n", n);
	return (0);
}
