#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_strings - Print out all given strings
 * @separator: String to print between other strings
 * @n: Number of strings being printed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list words;
	char *word;
	unsigned int i;

	va_start(words, n);
	i = 0;
	while (i < n)
	{
		word = va_arg(words, char *);
		if (word != NULL)
			printf("%s", word);
		else
			printf("(nil)");
		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
		i++;
	}
	printf("\n");
	va_end(words);
}
