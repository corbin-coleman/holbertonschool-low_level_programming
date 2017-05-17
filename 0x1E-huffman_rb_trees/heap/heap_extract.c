#include "heap.h"

/**
 * heap_extract - Get the root value of a tree from a heap
 * @heap: The heap structure containing the tree
 * Return: The data stored in the root node, NULL if it fails
 **/
void *heap_extract(heap_t *heap)
{
	if (heap == NULL || heap->root == NULL)
		return (NULL);
	return (heap->root->data);
}
