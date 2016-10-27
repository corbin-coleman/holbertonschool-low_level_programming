/**
 * string_toupper - Convert all lowercase letters to uppercase
 * @s: String to capitalize
 *
 * Return: Pointer to string;
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != 0)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}
