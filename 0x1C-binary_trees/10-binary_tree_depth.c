#include "binary_trees.h"

/**
 * binary_tree_depth - Find the depth of the given node in a binary tree
 * @node: Node in the binary tree to find depth of
 * Return: 0 if node is NULL or if node->parent is NULL, 1 + the return of
 * a recursive call on the node->parent
 **/
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent != NULL)
		return (1 + binary_tree_depth(node->parent));
	return (0);
}
