/**
 * _isupper - Find if a given letter is upper case
 * @c: the given letter
 *
 * Return: Return 1 if c is uppercase, 0 if otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
