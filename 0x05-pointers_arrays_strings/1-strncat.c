#include <stdio.h>
/**
 * _strncat - Concatenates two strings
 * @dest: The string being added to
 * @src: The string that is being added
 * @n: Number of chars to print from src
 *
 * Return: Pointer to dest string
 */
char *_strncat(char *dest, char *src, int n)
{
	int l1, l2, len;

	l1 = l2 = 0;
	while (dest[l1] != '\0')
	{
		l1++;
	}
	while (src[l2] != '\0')
	{
		l2++;
	}
	len = l2;
	l2 = 0;
	while (l2 < len && l2 < n)
	{
		dest[l1] = src[l2];
		l1++;
		l2++;
	}
	return (dest);
}
