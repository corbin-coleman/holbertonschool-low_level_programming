#include "hash_tables.h"

/**
 * key_index - Find the index of the key using it's hash value and array size
 * @key: The key to find the index for
 * @size: Size of the array for the hash table
 * Return: The index found
 **/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index, hash;

	hash = hash_djb2(key);
	index = hash % size;
	return (index);
}
