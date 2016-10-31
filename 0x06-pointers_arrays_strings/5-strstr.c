/**
 * _strstr - Find first occurence of given string in another string
 * @haystack: String to search through
 * @needle: String to search for
 *
 * Return: Pointer to beginning of located string
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;
	char *f;

	i = 0;
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			f = &haystack[i];
			while (needle[j] == haystack[i])
			{
				j++;
				i++;
				if (needle[j] == 0)
					return (f);
			}
			if (needle[j] == 0)
				return (f);
		}
		i++;
	}
	if (*haystack == *needle)
	{
		f = &haystack[0];
		return (f);
	}
	else
		return (0);
}
