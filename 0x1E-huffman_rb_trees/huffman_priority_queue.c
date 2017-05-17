#include "huffman.h"

/**
 * huffman_priority_queue - Create a priority queue using the frequency of
 * the data in a symbol_t struct
 * @data: An array of data in the symbol_t
 * @freq: An array of frequencies of that data
 * @size: The size of the two arrays
 * Return: A heap structure with a priority queue in it, NULL if it fails
 **/
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	symbol_t *new_symbol;
	heap_t *priority_queue_heap;
	binary_tree_node_t *node_inserted, *nested;
	size_t i;

	priority_queue_heap = heap_create(NULL);
	if (priority_queue_heap == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		new_symbol = symbol_create(data[i], freq[i]);
		if (new_symbol == NULL)
			return (NULL);
		nested = binary_tree_node(NULL, new_symbol);
		if (nested == NULL)
			return (NULL);
		node_inserted = heap_insert(priority_queue_heap, nested);
		if (node_inserted == NULL)
			return (NULL);
	}
	return (priority_queue_heap);
}
