#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse the tree using inorder logic
 * @tree: The tree to traverse through
 * @func: The function to call on the nodes
 **/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		if (tree->left != NULL)
			binary_tree_inorder(tree->left, func);
		func(tree->n);
		if (tree->right != NULL)
			binary_tree_inorder(tree->right, func);
	}
}
