#include "heap.h"

/**
 * find_last_node - Finds the last node in a complete binary tree
 * @root: Root of the binary tree
 * @size: Size of the binary tree
 * Return: The last node in the binary tree
 **/
binary_tree_node_t *find_last_node(binary_tree_node_t *root, size_t size)
{
	size_t row, pos;

	row = 1;
	pos = size;
	while ((row * 2) <= size)
	{
		row *= 2;
	}

	while (row > 1)
	{
		if (pos >= row)
			pos -= row;
		if (pos < row / 2)
			root = root->left;
		else
			root = root->right;
		row /= 2;
	}

	return (root);
}

/**
 * swap_down - Swap the root node down if it's larger than nodes below
 * @root: The root of the binary tree to swap through
 **/
void swap_down(binary_tree_node_t *root, int (*data_cmp)(void *, void *))
{
	void *temp_data;
	int left_cmp, right_cmp;

	left_cmp = right_cmp = 0;
	if (root == NULL)
		return;
	if (root->left != NULL)
		left_cmp = data_cmp(root->data, root->left->data);
	if (root->right != NULL)
		right_cmp = data_cmp(root->data, root->right->data);

	temp_data = root->data;
	if (left_cmp > 0)
	{
		root->data = root->left->data;
		root->left->data = temp_data;
		swap_down(root->left, data_cmp);
	}
	else if (right_cmp > 0)
	{
		root->data = root->right->data;
		root->right->data = temp_data;
		swap_down(root->right, data_cmp);
	}
}

/**
 * heap_extract - Get the root value of a tree from a heap
 * @heap: The heap structure containing the tree
 * Return: The data stored in the root node, NULL if it fails
 **/
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *last_node, *extract_node;
	void *data;

	if (heap == NULL || heap->root == NULL)
		return (NULL);
	extract_node = heap->root;
	last_node = find_last_node(heap->root, heap->size);
	last_node->left = extract_node->left;
	last_node->right = extract_node->right;
	if (last_node->parent->left == extract_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	last_node->parent = NULL;
	heap->root = last_node;
	swap_down(heap->root, heap->data_cmp);
	data = extract_node->data;
	free(extract_node);
	heap->size--;
	return (data);
}
