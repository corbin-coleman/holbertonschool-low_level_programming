#include "hash_tables.h"

/**
 * hash_table_print - Print all keys and values in a hash table
 * @ht: The hash table to print
 **/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (ht == NULL)
		return;
	index = 0;
	printf("{");
	while (index < ht->size)
	{
		current_node = ht->array[index];
		while (current_node != NULL)
		{
			printf("'%s': '%s'", current_node->key, current_node->value);
			if (!(index != (ht->size - 1) && current_node->next != NULL))
				printf(", ");
			current_node = current_node->next;
		}
		index++;
	}
	printf("}\n");
}
