/**
 * cap_string - Capitalize every word in a string
 * @s: String to capitalize words of
 *
 * Return: Pointer to string
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i] != 0)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (i == 0)
				s[i] -= 32;
			else if (s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1]
				 == '.' || s[i - 1] == '!' || s[i - 1] == '"'
				 || s[i - 1] == ')' || s[i -1] == '(' ||
				 s[i - 1] == '{' || s[i - 1] == '}' || s[i - 1]
				 == '\n' || s[i - 1] == 32 || s[i - 1] == '\t')
				s[i] -= 32;
		}
		i++;
	}
	return (s);
}
