#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - randomise a password for 101-crackme
 *
 * Return: 0
 */
int main(void)
{
	int unlock, passwd;

	srand(time(NULL));
	unlock = 2772;
	while (unlock >= 127)
	{
		passwd = (rand() % 126) + 1;
		printf("%c", passwd);
		unlock -= passwd;
	}

	printf("%c", unlock);
	return (0);
}
