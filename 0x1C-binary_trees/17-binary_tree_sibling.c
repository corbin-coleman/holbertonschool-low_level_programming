#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of the given node
 * @node: The node to the find the sibling of
 * Return: right_child if the left_child of the parent node is the
 * same as the given node, left_child if otherwise, NULL if node or
 * node->parent is NULL
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent, *left_child, *right_child;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	parent = node->parent;
	left_child = parent->left;
	right_child = parent->right;
	if (left_child == node)
		return (right_child);
	return (left_child);
}
