/**
 * _atoi - Find and print the first number in a string as an int
 * @s: String to convert to int
 *
 * Return: The int
 */
int _atoi(char *s)
{
	int i, n, m, p;

	i = n = m = p = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '-')
			m++;
		else if (*(s + i) == '+')
			p++;
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			while (*(s + i) >= '0' && *(s + i) <= '9')
			{
				n = (n * 10) + (*(s + i) - '0');
				i++;
			}
			if (m > p)
				n *= -1;
			return (n);
		}
		i++;
	}
	return (0);
}
