#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a tree in level order, starts with root,
 * then left child, then right child
 * @tree: The tree to traverse
 * @func: Function to call on the tree
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (tree->parent == NULL)
		func(tree->n);
	if (tree->left != NULL)
		func(tree->left->n);
	if (tree->right != NULL)
		func(tree->right->n);
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
