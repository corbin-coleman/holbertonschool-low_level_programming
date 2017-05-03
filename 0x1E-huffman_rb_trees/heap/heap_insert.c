#include "heap.h"

/**
 * add_node - Put the node in the tree, recursively
 * @parent: Potential parent of the new node
 * @node: Node to insert
 * Return: Address of the new node, NULL if it fails
 **/
binary_tree_node_t *add_node(binary_tree_node_t **parent,
			     binary_tree_node_t *new_node,
			     int (*data_cmp)(void *, void *))
{
	if (*parent == NULL)
	{
		new_node->parent = *parent;
		*parent = new_node;
		return (new_node);
	}
	if (data_cmp((*parent)->data, new_node->data) > 0)
	{
		(*parent)->parent = new_node;
		new_node->parent = NULL;
		new_node->left = *parent;
		*parent = new_node;
		return (new_node);
	}
	if ((*parent)->left == NULL)
	{
		(*parent)->left = new_node;
		new_node->parent = *parent;
		return (new_node);
	}
	if ((*parent)->right == NULL)
	{
		(*parent)->right = new_node;
		new_node->parent = *parent;
		return (new_node);
	}
	if ((*parent)->left->left == NULL || (*parent)->left->right == NULL)
	{
		return (add_node(&(*parent)->left, new_node, data_cmp));
	}
	return (add_node(&(*parent)->right, new_node, data_cmp));
}



/**
 * heap_insert - Insert a node into a binary tree heap
 * @heap: The heap to insert into
 * @data: Data for the new node
 * Return: Address of new node, or NULL if it fails
 **/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node;

	if (heap == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (add_node(&heap->root, new_node, heap->data_cmp));
}
