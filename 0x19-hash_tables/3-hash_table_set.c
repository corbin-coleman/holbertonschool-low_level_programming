#include "hash_tables.h"

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	int pass_fail;

	pass_fail = 1;
	index = key_index((unsigned char *) key, ht->size);
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	if (ht->array[index] == NULL)
	{
		ht->array[index] = node;
		node->key = (char *) key;
		node->value = (char *) value;
		node->next = NULL;
	}
	else
		pass_fail = check_list((char *) key, ht, index, (char *) value);
	return (pass_fail);
}

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
			current_node->value = value;
			return (1);
		}
		current_node = current_node->next;
	}
	current_node = ht->array[index];
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->next = current_node;
	new_node->key = key;
	new_node->value = value;
	ht->array[index] = new_node;
	return (1);
}
