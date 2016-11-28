#include <stdio.h>

void printStatement(void) __attribute__ ((constructor));

/**
 * printStatement - Print out a statment, before main function
 */
void printStatement(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
