#include "binary_trees.h"

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree->right != NULL)
		binary_tree_delete(tree->right);
	if (tree->left != NULL)
		binary_tree_delete(tree->left);
	free(tree);
}
