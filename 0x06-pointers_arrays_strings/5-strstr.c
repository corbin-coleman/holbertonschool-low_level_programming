/**
 * _strstr - Find first occurence of given string in another string
 * @haystack: String to search through
 * @needle: String to search for
 *
 * Return: Pointer to beginning of located string
 */

char *_strstr(char *haystack, char *needle)
{
	char *f;
	int i, stop, j;

	i = stop = 0;
	while (haystack[i] != 0)
	{
		stop = i;
		if (haystack[i] == needle[0])
		{
			stop = i;
			j = 0;
			f = &haystack[i];
			while (haystack[i] == needle[j] && haystack[i] != 0
			       && needle[j] != 0)
			{
				i++;
				j++;
			}
			if (needle[j] == 0)
				return (f);
		}
		i = stop + 1;
	}
	return (0);
}
