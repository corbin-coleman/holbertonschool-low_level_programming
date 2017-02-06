#include "hash_tables.h"

/**
 * hash_table_set - Put a value into the hash table
 * @ht: The hash table struct
 * @key: The key used to find the value
 * @value: The value to add
 * Return: 1 on success, 0 on fail
 **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	int pass_fail;

	if (ht == NULL)
		return (0);
	pass_fail = 1;
	index = key_index((unsigned char *) key, ht->size);
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	if (ht->array[index] == NULL)
	{
		ht->array[index] = node;
		node->key = strdup(key);
		if (node->key == NULL)
			return (0);
		node->value = strdup(value);
		if (node->value == NULL)
			return (0);
		node->next = NULL;
	}
	else
		pass_fail = check_list((char *) key, ht, index, (char *) value);
	return (pass_fail);
}

/**
 * check_list - check a list at the key's index for the key
 * @key: Key to look for
 * @ht: Hash table to look through
 * @index: Index of the hashed key value
 * @value: The value associated with the key to add
 * Return: 1 on success, 0 for failure
 **/
int check_list(char *key, hash_table_t *ht,
	       unsigned long int index, char *value)
{
	hash_node_t *current_node;
	hash_node_t *new_node;

	current_node = ht->array[index];
	while (current_node != NULL)
	{
		if (strcmp(key, current_node->key) == 0)
		{
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->next;
	}
	current_node = ht->array[index];
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->next = current_node;
	new_node->key = strdup(key);
	if (new_node->key == NULL)
		return (0);
	new_node->value = strdup(value);
	if (new_node->value == NULL)
		return (0);
	ht->array[index] = new_node;
	return (1);
}
