#include "binary_trees.h"

/**
 * leaf_check - Check if a node is a leaf
 * @node: Node to check
 * Return: 1 if leaf, 0 if not
 **/
int leaf_check(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_is_complete - Check if a tree is complete
 * @tree: The root of the tree to check
 * Return: 1 if tree is complete, 0 if it's not complete
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *left_child, *right_child;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_child = tree->left;
	right_child = tree->right;
	if (right_child != NULL)
	{
		if ((right_child->left != NULL && right_child->right != NULL) &&
		    (left_child->left == NULL || left_child->right == NULL))
			return (0);
	}
	if (left_child != NULL)
	{
		if ((left_child->left != NULL && left_child->right != NULL) &&
		    (right_child->left == NULL || right_child->right == NULL))
			return (0);
	}
	if (leaf_check(right_child) && leaf_check(left_child))
		return (1);
	return (binary_tree_is_complete(left_child) &&
		binary_tree_is_complete(right_child));
}
