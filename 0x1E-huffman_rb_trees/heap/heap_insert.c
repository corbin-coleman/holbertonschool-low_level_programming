#include "heap.h"

/**
 * find_parent - Find the parent of the node being inserted
 * @heap: The heap structure containing the binary tree, and its size
 * Return: The parent node of the node being inserted
 **/
binary_tree_node_t *find_parent(heap_t *heap)
{
	binary_tree_node_t *parent;
	size_t row, pos;

	row = 1;
	while ((row * 2) <= heap->size + 1)
	{
		row *= 2;
	}
	pos = heap->size + 1;
	parent = heap->root;

	while (row > 2)
	{
		if (pos >= row)
			pos -= row;

		if (pos < row / 2)
			parent = parent->left;
		else
			parent = parent->right;

		row /= 2;
	}

	return (parent);
}

void swap_nodes(binary_tree_node_t *new_node, binary_tree_node_t *parent,
		int (*data_cmp)(void *, void *), heap_t *heap)
{
	binary_tree_node_t *grandparent, *temp;

	while (data_cmp(parent->data, new_node->data) > 0)
	{
		grandparent = parent->parent;
		new_node->parent = grandparent;
		parent->parent = new_node;
		if (parent->left == new_node)
		{
			temp = parent->right;
			parent->left = new_node->left;
			parent->right = new_node->right;
			new_node->right = temp;
			new_node->left = parent;
		}
		if (parent->right == new_node)
		{
			temp = parent->left;
			temp->parent = new_node;
			parent->left = new_node->left;
			parent->right = new_node->right;
			new_node->left = temp;
			new_node->right = parent;
		}
		if (grandparent)
		{
			if (grandparent->left == parent)
				grandparent->left = new_node;
			else
				grandparent->right = new_node;
		}
		parent = grandparent;
		if (parent == NULL)
		{
			heap->root = new_node;
			break;
		}
	}
}

/**
 * heap_insert - Insert a node into a binary tree heap
 * @heap: The heap structure with the tree
 * @data: Data for the new node
 * Return: Address of new node, NULL if it fails
 **/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *parent, *new_node;

	if (heap == NULL)
		return (NULL);

	if (heap->size == 0)
	{
		heap->root = binary_tree_node(NULL, data);
		heap->size++;
		return (heap->root);
	}


	parent = find_parent(heap);
	if (parent->left == NULL)
	{
		parent->left = binary_tree_node(parent, data);
		new_node = parent->left;
	}
	else
	{
		parent->right = binary_tree_node(parent, data);
		new_node = parent->right;
	}
	heap->size++;
	swap_nodes(new_node, parent, heap->data_cmp, heap);
	return (new_node);
}
