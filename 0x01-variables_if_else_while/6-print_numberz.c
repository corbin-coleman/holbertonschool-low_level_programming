#include<stdio.h>

/**
 * main - print numbers w/ putchar
 *
 * Return: 0
 */
int main(void)
{
	int n = 48;

	while (n <= 57 && n >= 48)
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
