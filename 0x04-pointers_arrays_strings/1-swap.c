/**
 * swap_int - Swap the value of two ints using pointers
 * @a: First pointer to variable to swap
 * @b: Second pointer to variable to swap
 *
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
