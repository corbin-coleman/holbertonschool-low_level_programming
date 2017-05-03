#include "heap.h"

/**
 * binary_tree_node - Create a node for a binary tree for a heap
 * @parent: The parent node of the node to create
 * @data: The data to store in the node created
 * Return: Address of new node, or NULL if it fails
 **/
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;
	return (new_node);
}
