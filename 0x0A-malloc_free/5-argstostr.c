#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - Concatenate all arguments of a program
 * @ac: Arg count
 * @av: Array of arguments
 *
 * Return: Pointer to new string, NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k;

	if (ac == 0 || av == NULL)
		return (NULL);
	str = malloc(ac * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			str[k] = av[i][j];
			k++;
			j++;
		}
		str[k] = '\n';
		k++;
		i++;
	}
	return (str);
}
