#include "binary_trees.h"

/**
 * struct binary_tree_list - List of nodes from a binary tree
 * @node: The node from the binary tree
 * @next: The next node in the list
 **/
typedef struct binary_trees_list
{
	binary_tree_t *node;
	struct binary_trees_list *next;
} binary_tree_list;

/**
 * free_lists - Free a binary_tree_list list
 * @head: The list to free
 **/
void free_lists(binary_tree_list *head)
{
	binary_tree_list *kill_node;

	while (head)
	{
		kill_node = head;
		head = head->next;
		free(kill_node);
	}
}

/**
 * find_ancestor - Look through two lists to find the common element
 * @first: The first list
 * @second: The second list
 * Return: Address to the common node, NULL if no common node found
 **/
binary_tree_t *find_ancestor(binary_tree_list *first, binary_tree_list *second)
{
	binary_tree_list *second_head;

	second_head = second;
	while (first != NULL)
	{
		second = second_head;
		while (second != NULL)
		{
			if (first->node == second->node)
				return (first->node);
			second = second->next;
		}
		first = first->next;
	}
	return (NULL);
}

/**
 * add_binary_list_node - Add a node to a list to hold the nodes of binary tree
 * @head: Head of the list to add to
 * @bt_node: Node from the binary tree to store
 * Return: Address of node added, NULL if it failed
 **/
binary_tree_list *add_binary_list_node(binary_tree_list **head, binary_tree_t
				       *bt_node)
{
	binary_tree_list *new_node, *walker;

	walker = *head;
	new_node = malloc(sizeof(binary_tree_list));
	if (new_node == NULL)
		return (NULL);
	new_node->node = bt_node;
	new_node->next = NULL;
	if (walker != NULL)
	{
		while (walker->next != NULL)
			walker = walker->next;
		walker->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: Pointer to first node
 * @second: Pointer to second node
 * Return: Pointer to the lowesto common ancestor node, NULL if no common
 * ancestor found
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_list *first_head, *second_head;
	const binary_tree_t *first_walker, *second_walker;
	binary_tree_t *ancestor;

	first_head = second_head = NULL;
	if (first == NULL || second == NULL)
		return (NULL);
	first_walker = first;
	second_walker = second;
	while (first_walker != NULL)
	{
		add_binary_list_node(&first_head,
				     (binary_tree_t *) first_walker);
		first_walker = first_walker->parent;
	}
	while (second_walker != NULL)
	{
		add_binary_list_node(&second_head,
				     (binary_tree_t *) second_walker);
		second_walker = second_walker->parent;
	}
	ancestor = find_ancestor(first_head, second_head);
	free_lists(first_head);
	free_lists(second_head);
	return (ancestor);
}
