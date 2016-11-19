#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * format_len - Get the len of valid chars in formatter
 * @format: Formatter string
 *
 * Return: Length
 */
int format_len(const char * const format)
{
	int i, len;

	i = len = 0;
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			len++;
			break;
		case 'i':
			len++;
			break;
		case 'f':
			len++;
			break;
		case 's':
			len++;
			break;
		}
		i++;
	}
	return (len);
}

/**
 * print_all - Print any type of given argument
 * @format: List of types of arguments being passed
 */
void print_all(const char * const format, ...)
{
	va_list list;
	char *word;
	int i, len, print, lenc;

	len = format_len(format);
	i = lenc = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		print = 0;
		switch (format[i])
		{
		case 'c':
			printf("%c", (char)va_arg(list, int));
			lenc++;	print = 1;
			break;
		case 'i':
			printf("%d", va_arg(list, int));
			lenc++;	print = 1;
			break;
		case 'f':
			printf("%f", va_arg(list, double));
			lenc++; print = 1;
			break;
		case 's':
			word = va_arg(list, char *);
			if (word == NULL)
				word = "(nil)";
			printf("%s", word);
			lenc++;
			print = 1;
			break;
		}
		if (print == 1 && format[i + 1] != '\0' && lenc != len)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(list);
}
