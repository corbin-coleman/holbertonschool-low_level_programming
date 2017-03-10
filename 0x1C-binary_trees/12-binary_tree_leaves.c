#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!(binary_tree_is_leaf(tree)))
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	return (1);
}
