#include <stdio.h>

/**
 * main - print the number of arguments received
 *
 * Return: 0 for successful exit
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
