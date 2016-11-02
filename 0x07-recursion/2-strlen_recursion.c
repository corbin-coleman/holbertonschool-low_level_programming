/**
 * _strlen_recursion - Find the length of a string
 * @s: The string to find length of
 * Return: The length
 */
int _strlen_recursion(char *s)
{
	int l;

	l = 0;
	if (*s != 0)
	{
		l++;
		return (l + _strlen_recursion(s + 1));
	}
	return (l);
}
