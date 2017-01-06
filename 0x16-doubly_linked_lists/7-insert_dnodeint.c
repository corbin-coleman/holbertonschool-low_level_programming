#include "lists.h"
/**
  * *insert_dnodeint_at_idx - Insert a new node into a doubly
  * linked list at a given index
  * @head: Double pointer to the start of the list
  * @idx: Index to insert new node at
  * @n: Value to assign to new node
  * Return: Address of the new node, NULL if it fails
  */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **head, unsigned int idx, int n)
{
	unsigned int pos;
	dlistint_t *new_node;
	dlistint_t *current;
	dlistint_t *prev;

	pos = 0;
	current = *head;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	while (current != NULL && pos < idx)
	{
		current = current->next;
		pos++;
	}
	if (pos == idx)
	{
		prev = current->prev;
		new_node->n = n;
		new_node->prev = current->prev;
		current->prev = new_node;
		new_node->next = current;
		prev->next = new_node;
		return (new_node);
	}
	return (NULL);
}
