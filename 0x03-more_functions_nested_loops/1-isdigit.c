/**
 * _isdigit - Check if input is a number
 * @c: Given input to check
 *
 * Return: 1 if a number, 0 if otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
