#include "binary_trees.h"

/**
 * find_height - Find the height of the given tree
 * @tree: The tree to find the height of
 * @height: Current height of the tree
 * Return: The height of the taller branch of the tree
 **/
int find_height(binary_tree_t *tree, int height)
{
	int left_height, right_height;

	left_height = right_height = 0;
	if (tree->left == NULL && tree->right == NULL)
		return (height);
	if (tree->left != NULL)
		left_height = find_height(tree->left, height + 1);
	if (tree->right != NULL)
		right_height = find_height(tree->right, height + 1);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_balance - Find the balance factor of given tree
 * @tree: The tree to find the balance of
 * Return: The difference of the left_height and right_height of the tree
 **/
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
