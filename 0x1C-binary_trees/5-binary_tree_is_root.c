#include "binary_trees.h"

/**
 * binary_tree_is_root - See if the given node is the root of a tree
 * @node: Node to check
 * Return: 1 if it's a root, 0 if not
 **/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
