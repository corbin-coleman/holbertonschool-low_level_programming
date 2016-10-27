/**
 * _strncpy - Copy src string to dest, but only the n total of bytes
 * @dest: Where you are copying to
 * @src: The string being copied
 * @n: Number of bytes to copy
 *
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, ls;

	i = ls = 0;
	while (src[ls] != '\0')
	{
		ls++;
	}
	if (ls < n)
	{
		while (i < ls)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
