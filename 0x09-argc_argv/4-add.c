#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Print result of adding given arguments
 * @argc: Number of arguments
 * @argv: Arguments recieved
 *
 * Return: 0 on success, 1 if theres a nondigit arg
 */
int main(int argc, char *argv[])
{
	int sum;

	sum = 0;
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	while (argc--)
	{
		if(isalpha(*argv[argc]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[argc]);
	}
	printf("%d\n", sum);
	return (0);
}
