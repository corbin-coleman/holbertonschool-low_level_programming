#include "heap.h"

/**
 * delete_tree - Delete a binary tree
 * @tree: The root of the tree to delete
 * @free_data: Function to delete data in tree
 **/
void delete_tree(binary_tree_node_t *tree, void (*free_data)(void *))
{
	if (tree != NULL)
	{
		if (tree->right != NULL)
			delete_tree(tree->right, free_data);
		if (tree->left != NULL)
			delete_tree(tree->left, free_data);
		if (free_data != NULL)
			free_data(tree->data);
		free(tree);
	}
}


/**
 * heap_delete - Delete an entire heap structure
 * @heap: The heap structure to delete
 * @free_data: The function to free data in binary tree
 **/
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap != NULL)
	{
		if (heap->root != NULL)
			delete_tree(heap->root, free_data);
		free(heap);
	}
}
