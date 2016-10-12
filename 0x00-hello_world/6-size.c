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

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(i));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(l));
	printf("Size of a long long int: %lu byte(s)\n",
	       (unsigned long)sizeof(ll));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));

	return (0);
}
