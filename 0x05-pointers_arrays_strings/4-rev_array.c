/**
 * reverse_array - Reverse contents of array
 * @a: The array to reverse
 * @n: The size of the array
 *
 * Return: Nothing
 */
void reverse_array(int *a, int n)
{
	int tmp[n];
	int i;

	i = 0;
	while (i < n)
	{
		tmp[i] = a[i];
		i++;
	}
	n--;
	i = 0;
	while (n >= 0)
	{
		a[n] = tmp[i];
		n--;
		i++;
	}
}
