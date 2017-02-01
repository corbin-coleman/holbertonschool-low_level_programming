/**
 * _memset - Fill n bytes of memory area pointed to with constant byte
 * @s: Area pointed to
 * @b: Byte to fill it with
 * @n: Amount to fill it wih
 *
 * Return: Pointer to memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
