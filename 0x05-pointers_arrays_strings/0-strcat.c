#include <stdio.h>
/**
 * _strcat - Concatenates two strings
 * @dest: The string being added to
 * @src: The string that is being added
 *
 * Return: Pointer to dest string
 */
void *_strcat(char *dest, char *src)
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
	while (l2 < len)
	{
		dest[l1] = src[l2];
		l1++;
		l2++;
	}
	return (dest);
}
