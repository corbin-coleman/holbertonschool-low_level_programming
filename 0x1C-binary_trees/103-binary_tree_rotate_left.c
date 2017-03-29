#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotate the given node to the left
 * @tree: The given node to tree to rotate
 * Return: The new root of the tree, NULL if it fails
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->right;
	tree->right = tree->parent->left;
	tree->parent->left = tree;
	if (tree->right != NULL)
		tree->right->parent = tree;
	tree->parent->parent = NULL;
	return (tree->parent);
}
