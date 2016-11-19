#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

void print_string(va_list args)
{
	char *string;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(nil)";
	printf("%s", string);
}

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_all - Print any type of given argument
 * @format: List of types of arguments being passed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	print_form_t print_form[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};
	int i, j;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (*print_form[j].c == format[i])
			{
				print_form[j].f(args);
				printf(", ");
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
