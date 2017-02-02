#include "hash_tables.h"

/**
 * hash_table_print - Print all keys and values in a hash table
 * @ht: The hash table to print
 **/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index, print_com;
	hash_node_t *current_node;

	if (ht == NULL)
		return;
	index = print_com = 0;
	printf("{");
	while (index < ht->size)
	{
		current_node = ht->array[index];
		while (current_node != NULL)
		{
			if (print_com > 0)
				printf(", ");
			printf("'%s': '%s'", current_node->key, current_node->value);
			print_com++;
			current_node = current_node->next;
		}
		index++;
	}
	printf("}\n");
}
