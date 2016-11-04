#include <stdio.h>

/**
 * main - Print the name of the executable file
 *
 * Return: 0 for succesful exit
 */
int main(int argc __attribute__((unused)),char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
