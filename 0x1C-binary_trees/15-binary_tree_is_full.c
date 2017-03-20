#include "binary_trees.h"

/**
 * leaf_check - Check if node is a leaf
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
 * binary_tree_is_full - Check to see if a tree is full
 * @tree: The tree to check for
 * Return: 1 if full, 0 if not
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (leaf_check(tree))
		return (1);
	if (!(leaf_check(tree)) && (tree->left == NULL || tree->right == NULL))
		return (0);
	if (!(binary_tree_is_full(tree->left)) || !(binary_tree_is_full(tree->right)))
		return (0);
	return (1);
}
