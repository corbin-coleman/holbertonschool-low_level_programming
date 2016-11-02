/**
 * prime_check - Check if number is prime
 * @n: Number to check
 * @f: Number to check against
 *
 * Return: 1 if prime, 0 if otherwise
 */
int prime_check(int n, int f)
{
	if (n % f == 0 && f != (n / 2))
		return (0);
	else if (f >= (n / 2))
		return (1);
	else
		return (prime_check(n, f + 1));
}
/**
 * is_prime_number - Find if a given number is prime
 * @n: Number to check
 *
 * Return: 1 if prime, 0 if otherwise
 */
int is_prime_number(int n)
{
	if (n > 1)
		return (prime_check(n, 2));
	else if (n < 0)
		return (0);
	return (0);
}
