/**
 * _strchr - Find given char in a string
 * @s: string to search
 * @c: char to search for
 *
 * Return: Pointer to first instance of c
 */

char *_strchr(char *s, char c)
{
	char *f;
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			f = &s[i];
			return (f);
		}
		i++;
	}
	return NULL;
}
