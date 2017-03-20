#include "binary_trees.h"

/**
 * binary_tree_nodes - Count up all non-leaf nodes in a tree
 * @tree: The tree to count nodes in
 * Return: Number of non-leaf nodes
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree != NULL && !(tree->left == NULL && tree->righ == NULL))
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	return (0);
}
