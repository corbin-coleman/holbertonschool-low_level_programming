#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_numbers - Print n amount of numbers, separated by the separator string
 * @separator: The string to pring between numbers
 * @n: Number of numbers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int i;

	i = 0;
	va_start(nums, n);
	while (i < n)
	{
		printf("%d", va_arg(nums, int));
		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
		i++;
	}
	printf("\n");
	va_end(nums);
}
