#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_all - Print any type of given argument
 * @format: List of types of arguments being passed
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int i, len, print;

	i = len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f'
		    || format[i] == 's')
			len++;
		i++;
	}
	i  = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		print = 0;
		switch (format[i])
		{
		case 'c' :
			printf("%c", va_arg(list, int));
			print = 1;
			break;
		case 'i' :
			printf("%d", va_arg(list, int));
			print = 1;
			break;
		case 'f' :
			printf("%f", va_arg(list, double));
			print = 1;
			break;
		case 's' :
			printf("%s", va_arg(list, char *));
			print = 1;
			break;
		}
		if (print == 1 && format[i + 1] != '\0')
			printf(", ");
		i++;
	}
	printf("\n");
}
