#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the leaves in a tree
 * @tree: Tree to count leaves in
 * Return: Number of leaves
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!(tree->left == NULL && tree->right == NULL))
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	return (1);
}
