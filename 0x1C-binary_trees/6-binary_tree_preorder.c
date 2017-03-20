#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a tree in the preorder style
 * @tree: The root node of the tree to traverse
 * @func: Pointer to the function to run on the node
 **/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		if (tree->left != NULL)
			binary_tree_preorder(tree->left, func);
		if (tree->right != NULL)
			binary_tree_preorder(tree->right, func);
	}
}
