#include "binary_trees.h"

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent, *parent, *left_uncle, *right_uncle;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);
	parent = node->parent;
	grandparent = parent->parent;
	left_uncle = grandparent->left;
	right_uncle = grandparent->right;
	if (left_uncle == parent)
		return (right_uncle);
	return (left_uncle);
}
