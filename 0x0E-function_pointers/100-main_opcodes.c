#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the opcodes of the function
 * @argc: Number of args given
 * @argv: Argument of number of bytes to print
 *
 * Return: 0 on success, Print Error for errors, exit value 1 if
 * incorrect # of args, exit value 2 if number of bytes is negative
 */
int main(int argc, char *argv[])
{
	char *add;
	int i, bytes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	add = (char *)&main;
	bytes = atoi(argv[1]);
	i = 0;
	while (i < bytes - 1)
	{
		printf("%02hhx ", add[i]);
		i++;
	}
	printf("%02hhx\n", add[i]);
	return (0);
}
