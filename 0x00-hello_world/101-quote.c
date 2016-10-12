#include<stdio.h>
#include<unistd.h>

/**
 * main - run all functions
 *
 * Description: Print out statement w/o printf/puts
 * Return: Return 1 and exit
 */
int main(void)
{
	int l;

	l = sizeof("and that piece of art is useful - Dora Korpar, 2015-10-19\n");

	write(2,
	      "and that piece of art is useful - Dora Korpar, 2015-10-19\n", l);
	return (1);
}
