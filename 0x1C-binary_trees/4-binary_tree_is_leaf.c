#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Find if a node of a tree is a leaf
 * @node: The node to check
 * Return: 1 if it's a leaf, 0 if it's not
 **/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
