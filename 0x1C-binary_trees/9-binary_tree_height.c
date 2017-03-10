#include "binary_trees.h"

size_t find_height(binary_tree_t *tree, size_t height)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (tree->left == NULL && tree->right == NULL)
		return (height);
	if (tree->left != NULL)
		left_height = find_height(tree->left, height + 1);
	if (tree->right != NULL)
		right_height = find_height(tree->right, height + 1);
	if (left_height < right_height)
		return (right_height);
	return (left_height);
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_height = find_height(tree->left, 1);
	if (tree->right != NULL)
		right_height = find_height(tree->right, 1);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
