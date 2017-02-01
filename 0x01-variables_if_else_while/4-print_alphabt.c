#include<stdio.h>

/**
 * main - Print alphabet w/o two letters
 *
 * Return: 0
 */
int main(void)
{
	char z = 'a';

	while (z <= 'z')
	{
		if (z != 'q' && z != 'e')
		{
			putchar(z);
		}
		z++;
	}
	putchar('\n');
	return (0);
}
