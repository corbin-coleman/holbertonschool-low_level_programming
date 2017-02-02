#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table and an array of given size
 * @size: Size of the array to create
 * Return: The pointer to the new hash table
 **/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(size * sizeof(hash_node_t *));
	if (ht->array == NULL)
		return (NULL);
	ht->size = size;
	return (ht);
}
