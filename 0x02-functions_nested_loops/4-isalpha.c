/**
 * _isalpha - Check to see if input is a letter
 *
 * Return: Return 1 if a letter, return 0 if otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	else
		return 0;
}
