#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent != NULL)
		return (1 + binary_tree_depth(node->parent));
	return (0);
}
