#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a given string
 * @str: String to print
 */
void print_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * rev_string - Reverse the given string
 * @s: The string to reverse
 *
 * Return: Nothing
 */
void rev_string(char *s)
{
	char str[10000];
	int i, r;

	i = 0;
	while (*(s + i) != 0)
	{
		str[i] = *(s + i);
		i++;
	}
	r = i - 1;
	i = 0;
	while (r >= 0)
	{
		*(s + r) = str[i];
		r--;
		i++;
	}
}

/**
 * print_err - Print the word "Error"
 */
void print_err(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}

/**
 * str_len - Find the length of a given string
 * @str: String to find the length of
 *
 * Return: Length of the string
 */
int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * init - Initialize an array with 0
 * @arr: The array to initialize
 * @size: Size of the array
 *
 * Return: Pointer to array
 */
char *init(char *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = '0';
		i++;
	}
	return (arr);
}

/**
 * _isstrdigit - Check if input is only numbers
 * @str: Given input to check
 *
 * Return: 1 if a number, 0 if otherwise
 */
int _isstrdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * mul - Multiply two strings together
 * @num1: The first number, as a string
 * @num2: The second number, as a string
 * @len1: The length of the first string
 * @len2: The length of the second string
 */
void mul(char *num1, char *num2, int len1, int len2)
{
	int i, prod, j, carry, k, digit;
	char *res;

	res = malloc((len1 + len2) * sizeof(char));
	if (res == NULL)
	{
		print_err();
		exit(98);
	}
	res = init(res, (len1 + len2));
	i = len2 - 1;
	carry = k = digit = 0;
	while (i >= 0 && k < (len1 + len2))
	{
		j = len1 - 1;
		k = digit;
		while (j >= 0)
		{
			carry = 0;
			prod = (num1[j] - '0') * (num2[i] - '0');
			if (prod > 9)
				carry += prod / 10;
			prod = prod % 10;
			if (((res[k] - '0') + prod) > 9)
			{
				carry += 1;
				res[k] += (prod - 10);
			}
			else
				res[k] += prod;
			res[k + 1] += carry;
			k++;
			j--;
		}
		i--;
		digit++;
	}
	if (res[k] == '0')
		res[k] = '\0';
	rev_string(res);
	print_str(res);
	free(res);
}

/**
 * main - Run all necessary functions to multply two strings as numbers
 * @argc: Number of args
 * @argv: Value of args
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int len1, len2;

	if (argc != 3)
	{
		print_err();
		exit(98);
	}
	if (_isstrdigit(argv[1]) == 0 || _isstrdigit(argv[2]) == 0)
	{
		print_err();
		exit(98);
	}
	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	if (len1 > len2)
		mul(argv[1], argv[2], len1, len2);
	else
		mul(argv[2], argv[1], len2, len1);
	return (0);
}
