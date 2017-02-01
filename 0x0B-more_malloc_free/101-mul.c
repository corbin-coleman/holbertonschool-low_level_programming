#include <stdlib.h>
#include "holberton.h"

/**
 * print_str - Print a given string
 * @str: String to print
 */
void print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
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
	exit(98);
}

/**
 * rev_string - Reverse the given string
 * @s: The string to reverse
 * @size: Size of string to revers;
 * Return: Nothing
 */
void rev_string(char *s, int size)
{
	char *str;
	int i, r;

	str = malloc(size);
	if (str == NULL)
		print_err();
	i = 0;
	while (*(s + i) != 0)
	{
		str[i] = *(s + i);
		i++;
	}
	r = i - 1;
	i = 0;
	while (r > 0)
	{
		*(s + r) = str[i];
		r--;
		i++;
	}
	*(s + r) = str[i];
	free(str);
}

/**
 * str_len - Find the length of a given string
 * @str: String to find the length of
 *
 * Return: Length of the string
 */
unsigned int str_len(char *str)
{
	unsigned int i;

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
 *
 * Return: Pointer to char array
 */
char *mul(char *num1, char *num2, int len1, int len2)
{
	int i, prod, j, carry, k, digit, reslen;
	char *res;

	reslen = len1 + len2 + 1;
	res = malloc(reslen * sizeof(char));
	if (res == NULL)
		print_err();
	res = init(res, reslen);
	i = len2 - 1; carry = k = digit = 0;
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
			k++; j--;
		}
		i--; digit++;
	}
	if (res[k] == '0')
		res[k] = '\0';
	else
		res[k + 1] = '\0';
	return (res);
}

/**
 * remove_zeroes - Remove zeroes from num
 * @str: String to remove zeroes from
 * @len: Length of string
 *
 * Return: Pointer to new string
 */
char *remove_zeroes(char *str, int len)
{
	int i, j;
	char *nstr;

	i = 0;
	while (str[i] == '0' && str[i] != '\0')
	{
		i++;
	}
	if (len - i == 0)
	{
		nstr = malloc(2 * sizeof(*nstr));
		nstr[0] = '0';
		nstr[1] = '\0';
		return (nstr);
	}
	else
		len -= i;
	nstr = malloc(len * sizeof(*nstr) + 1);
	j = 0;
	while (j < len)
	{
		nstr[j] = str[i];
		j++;
		i++;
	}
	nstr[j] = '\0';
	return (nstr);
}

/**
 * check_zero - Check to see if the number is zero or if zeroes need to be gone
 * @str: Str to check for zeroes
 * @len: len of string
 *
 * Return: Pointer to new num string
 */
char *check_zero(char *str, int len)
{
	char *num;
	int i;

	if (str[0] == '0' && len != 1)
		num = remove_zeroes(str, len);
	else if (str[0] == '0' && len == 1)
	{
		num = malloc(len + 1);
		if (num == NULL)
			print_err();
		num[0] = '0';
		num[1] = '\0';
	}
	else
	{
		num = malloc(len + 1);
		if (num == NULL)
			print_err();
		i = 0;
		while (i < len)
		{
			num[i] = str[i];
			i++;
		}
		num[i] = '\0';
	}
	return (num);
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
	int len1, len2, anslen;
	char *ans, *num1, *num2;

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
	num1 = check_zero(argv[1], len1);
	if (*num1 == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	num2 = check_zero(argv[2], len2);
	if (*num2 == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	len1 = str_len(num1);
	len2 = str_len(num2);
	if (len1 > len2)
		ans = mul(num1, num2, len1, len2);
	else
		ans = mul(num2, num1, len2, len1);
	anslen = str_len(ans);
	rev_string(ans, anslen);
	print_str(ans);
	free(ans); free(num1); free(num2);
	return (0);
}
