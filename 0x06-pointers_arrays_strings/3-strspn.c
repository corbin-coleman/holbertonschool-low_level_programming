/**
 * _strspn - Find length of string that consists only of chosen bytes
 * @s: String to search
 * @accept: The acceptable bytes string can contain
 *
 * Return: Length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, l, j, a;

	i = l = 0;
	while (s[i] != 0)
	{
		j = 0;
		a = 0;
		while (accept[j] != 0)
		{
			if (s[i] != accept[j])
			{
				j++;
			}
			else if (s[i] == accept[j])
			{
				a++;
				l++;
				j++;
			}
		}
		if (a == 0)
			return (l);
		i++;
	}
	return (l);
}
