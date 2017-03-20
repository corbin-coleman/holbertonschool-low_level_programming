#include "binary_trees.h"
#include "15-binary_tree_is_full.c"


int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_is_full(tree));
}
