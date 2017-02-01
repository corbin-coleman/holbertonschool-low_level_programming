#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Run the program
 * @argc: Count of args given
 * @argv: Array of arg strings
 *
 * Return: 0 on success, print Error and exit with 98 if incorrect
 * number of args, exit with 99 if operator given is incorrect
 */
int main(int argc, char *argv[])
{
	int (*func)(int, int);
	int num1, num2, res;

	if (argc == 4)
	{
		if (argv[2][1] != '\0')
		{
			printf("Error\n");
			exit(99);
		}
		func = get_op_func(argv[2]);
		if (func == NULL)
		{
			printf("Error\n");
			exit(99);
		}
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		res = func(num1, num2);
		printf("%d\n", res);
		return (0);
	}
	else
	{
		printf("Error\n");
		exit(98);
	}
}
