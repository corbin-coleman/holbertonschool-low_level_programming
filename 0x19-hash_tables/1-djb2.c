#include "hash_tables.h"

/**
 * hash_djb2 - Create the hash value for the given string
 * @str: The string to create a hash value for
 * Return: The hash value created
 **/
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
