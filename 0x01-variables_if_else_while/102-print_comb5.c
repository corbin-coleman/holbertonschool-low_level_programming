#include<stdio.h>
/**
 * main - print two two digit combos
 *
 * Return: 0
 */
int main(void)
{
	int i = 0, j = 0;
	int f, s, t, l;

	while (i < 100)
	{
		f = i / 10;
		s = i % 10;
		j = 0;
		while (j < 100)
		{
			t = j / 10;
			l = j % 10;
			if (i < j && i != j)
			{
				putchar(f + '0');
				putchar(s + '0');
				putchar(' ');
				putchar(t + '0');
				putchar(l + '0');
				if (i == 98 && j == 99)
				{
					break;
				}
				putchar(',');
				putchar(' ');
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
