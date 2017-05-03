#include "heap.h"

/**
 * heap_create - Create a heap data structure
 * @data_cmp: A function to compare data
 * Return: The address of the heap created, or NULL if it fails
 **/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	heap = malloc(sizeof(heap_t));
	if (heap == NULL)
		return (NULL);
	heap->root = NULL;
	heap->size = 0;
	heap->data_cmp = data_cmp;
	return (heap);
}
