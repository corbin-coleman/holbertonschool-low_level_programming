#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!(binary_tree_is_leaf(tree)) && (tree->left == NULL || tree->right == NULL))
		return (0);
	if (binary_tree_is_leaf(tree->right) && binary_tree_is_leaf(tree->left))
		return (1);
	if (!(binary_tree_is_full(tree->left)) || !(binary_tree_is_full(tree->right)))
		return (0);
	return (1);
}
