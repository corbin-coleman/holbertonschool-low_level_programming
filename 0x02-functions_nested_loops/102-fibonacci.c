#include <stdio.h>

/**
 * main - Print first 50 Fibonacci numbers
 *
 * Return: Return 0
 */
int main(void)
{
	long long int f, s, t, p;

	p = 0;
	f = 0;
	s = 1;
	t = 0;
	while (t <= 50)
	{
		p = f + s;
		printf("%lld", p);
		if (t != 50)
		{
			printf(", ");
		}
		f = s;
		s = p;
		t++;
	}
	printf("\n");
	return 0;
}
