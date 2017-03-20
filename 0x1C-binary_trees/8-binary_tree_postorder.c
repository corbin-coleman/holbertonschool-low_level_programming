#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse tree using postorder logic
 * @tree: The tree to traverse
 * @func: Function to call on each node
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		if (tree->left != NULL)
			binary_tree_postorder(tree->left, func);
		if (tree->right != NULL)
			binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
