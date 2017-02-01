/**
 * _islower - check if letter is lowercase or not
 * @c: Letter to check case of
 *
 * Return: Return 1 if lower, return 0 if not lower
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
