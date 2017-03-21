#include "binary_trees.h"

/**
 * find_height - Find height of a binary tree
 * @tree: Tree to find the height of
 * Return: left_height if left branch is bigger, right_height if right branch
 * is bigger, 0 if tree is NULL or tree is a leaf
 **/
size_t find_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_height = find_height(tree->left) + 1;
	right_height = find_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_is_perfect - Check if the given tree is perfect
 * @tree: Tree to check
 * Return: 1 if full, 0 if not
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_height = find_height(tree->left);
	right_height = find_height(tree->right);
	if (left_height != right_height)
		return (0);
	if (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right))
		return (1);
	return (0);
}
