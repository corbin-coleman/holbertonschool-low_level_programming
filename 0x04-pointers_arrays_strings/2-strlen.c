/**
 * _strlen - Return the length of a given string
 * @s: Pointer to the string
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		i++;
	}
	return (i);
}
