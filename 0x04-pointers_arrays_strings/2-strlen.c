/**
 * _strlen - Return the length of a given string
 * @s: Pointer to the string
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int len, i;

	len = 0;
	for (i = 0; i < *(s + i); i++)
	{
		len++;
	}
	return (len);
}
