#include "binary_trees.h"

/**
 * binary_tree_height - Find the height of the longest branch in a binary tree
 * @tree: The tree to find the height of
 * Return: left_height if left branch is bigger, right_height if right branch
 * is bigger, 0 if tree is NULL or tree is a leaf
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
