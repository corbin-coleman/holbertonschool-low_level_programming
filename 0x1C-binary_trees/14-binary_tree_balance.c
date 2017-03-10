#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	left_height = right_height = 0;
	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_height = find_height(tree->left, 1);
	if (tree->right != NULL)
		right_height = find_height(tree->right, 1);
	return (left_height - right_height);
}
