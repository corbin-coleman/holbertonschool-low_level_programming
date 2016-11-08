#include <stdlib.h>

/**
 * _strdup - Return pointer to a new string that duplicates given string,
 * allocate mem w/ malloc
 * @str: String to duplicate
 *
 * Return: Pointer to new string, NULL if failed to make memory
 */
char *_strdup(char *str)
{
	char *nstr;
	int i, len;

	i = len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	nstr = malloc(len * sizeof(*str));
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		nstr[i] = str[i];
		i++;
	}
	return (nstr);
}
