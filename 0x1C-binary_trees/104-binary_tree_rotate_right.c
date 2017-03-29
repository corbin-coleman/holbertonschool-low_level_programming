#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotate the given node to the left
 * @tree: The given node to tree to rotate
 * Return: The new root of the tree, NULL if it fails
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->left;
	tree->left = tree->parent->right;
	tree->parent->right = tree;
	tree->parent->parent = NULL;
	return (tree->parent);
}
