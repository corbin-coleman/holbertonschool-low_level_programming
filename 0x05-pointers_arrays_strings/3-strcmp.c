/**
 * _strcmp - Compare two strings, output int based on comparison
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: Int -1 if s1 shorter, +1 if s1 is longer, 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i, l1, l2;

	i = l1 = l2 = 0;
	while (s1[l1] != 0)
		l1++;
	while (s2[l2] != 0)
		l2++;
	if (l1 >= l2)
	{
		while (s2[i] != 0)
		{
			if (s1[i] < s2[i])
				return (-1);
			else if (s1[i] > s2[i])
				return (1);
			else
				i++;
		}
	}
	else
	{
		while (s1[i] != 0)
		{
			if (s1[i] < s2[i])
				return (-1);
			else if (s1[i] > s2[i])
				return (1);
			else
				i++;
		}
	}
	return (0);
}
