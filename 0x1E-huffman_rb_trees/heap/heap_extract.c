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
 * swap_left - Swap nodes to the left
 * @root: The current node you're on
 * @swap_node: The node being swapped with
 **/
void swap_left(binary_tree_node_t *root, binary_tree_node_t *swap_node)
{
	binary_tree_node_t *temp_node;

	swap_node->parent = root->parent;
	root->left = swap_node->left;
	swap_node->left = root;
	temp_node = swap_node->right;
	if (root->right != NULL)
		root->right->parent = swap_node;
	if (temp_node != NULL)
		temp_node->parent = root;
	swap_node->right = root->right;
	root->right = temp_node;
	root->parent = swap_node;
}

/**
 * swap_right - Swap nodes to the left
 * @root: The current node you're on
 * @swap_node: The node being swapped with
 **/
void swap_right(binary_tree_node_t *root, binary_tree_node_t *swap_node)
{
	binary_tree_node_t *temp_node;

	swap_node->parent = root->parent;
	root->right = swap_node->right;
	swap_node->right = root;
	temp_node = swap_node->left;
	if (root->left != NULL)
		root->left->parent = swap_node;
	if (temp_node != NULL)
		temp_node->parent = root;
	swap_node->left = root->left;
	root->left = temp_node;
	root->parent = swap_node;
}

/**
 * assign_parent - Assigns the parent of the current root properly
 * @swap_node: The node being swapped with
 * @parent: The parent to the root node
 * @root: The root node being swapped
 **/
void assign_parent(binary_tree_node_t *swap_node, binary_tree_node_t *parent,
		   binary_tree_node_t *root)
{
	if (parent->left == root)
		parent->left = swap_node;
	else
		parent->right = swap_node;
}

/**
 * swap_down - Swap the root node down if it's larger than nodes below
 * @heap: heap containing the binary tree to swap through
 **/
void swap_down(heap_t *heap)
{
	binary_tree_node_t *root, *swap_node;
	int (*data_cmp)(void *, void *);
	int left_cmp, right_cmp;

	root = heap->root;
	data_cmp = heap->data_cmp;
	left_cmp = right_cmp = 0;
	if (root->left != NULL)
		left_cmp = data_cmp(root->data, root->left->data);
	if (root->right != NULL)
		right_cmp = data_cmp(root->data, root->right->data);
	while (left_cmp > 0 || right_cmp > 0)
	{
		if (left_cmp > 0)
		{
			swap_node = root->left;
			if (root->parent == NULL)
				heap->root = swap_node;
			else
				assign_parent(swap_node, root->parent, root);
			swap_left(root, swap_node);
		}
		else if (right_cmp > 0)
		{
			swap_node = root->right;
			if (root->parent == NULL)
				heap->root = swap_node;
			else
				assign_parent(swap_node, root->parent, root);
			swap_right(root, swap_node);
		}
		left_cmp = right_cmp = 0;
		if (root->left != NULL)
			left_cmp = data_cmp(root->data, root->left->data);
		if (root->right != NULL)
			right_cmp = data_cmp(root->data, root->right->data);
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
	swap_down(heap);
	data = extract_node->data;
	free(extract_node);
	heap->size--;
	return (data);
}
