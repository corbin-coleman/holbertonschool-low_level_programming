#include "hash_tables.h"

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *kill_node, *current;
	unsigned long int i;

	i = 0;
	while (i < ht->size)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			kill_node = current;
			current = current->next;
			free(kill_node->key);
			free(kill_node->value);
			free(kill_node);
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
