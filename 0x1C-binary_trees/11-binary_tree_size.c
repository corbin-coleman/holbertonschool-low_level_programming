#include "binary_trees.h"

/**
 * binary_tree_size - Find the total number of nodes in a binary tree
 * @tree: Tree to find size of
 * Return: 0 if tree is NULL, 1 + recursive calls on tree->left && tree->right
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
