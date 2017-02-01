/**
 * _strlen - Return the length of a given string
 * @s: Pointer to the string
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int i;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
