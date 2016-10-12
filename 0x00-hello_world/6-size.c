#include<stdio.h>

/**
 * main - Run main function
 *
 * Description: Run printf multiple times to print size of different types
 * Return: Return 0 to exit function
 */
int main(void)
{
	int i;
	char c;
	long int l;
	long long int ll;
	float f;

	printf("The size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("The size of an int: %lu byte(s)\n", (unsigned long)sizeof(i));
	printf("The size of a long int: %lu byte(s)\n", (unsigned long)sizeof(l));
	printf("The size of a long long int: %lu byte(s)\n",
	       (unsigned long)sizeof(ll));
	printf("The size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));

	return (0);
}
