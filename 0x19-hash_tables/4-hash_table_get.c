#include "hash_tables.h"

/**
 * hash_table_get - Find the value in a hash table using a key
 * @ht: The hash table to look through
 * @key: The key to find the value for
 * Return: The value found, or NULL if no value found
 **/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (ht == NULL)
		return (NULL);
	index = key_index((unsigned char *) key, ht->size);
	current_node = ht->array[index];
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}
