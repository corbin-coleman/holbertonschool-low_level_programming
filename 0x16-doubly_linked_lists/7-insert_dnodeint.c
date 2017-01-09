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
	if (*head == NULL && idx != 0)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	if (*head != NULL)
	{
		while (current->prev != NULL)
			current = current->prev;
		while (current != NULL && pos < idx)
		{
			prev = current;
			current = current->next;
			pos++;
		}
		if (pos == idx)
		{
			new_node->n = n;
			new_node->prev = prev;
			prev->next = new_node;
			if (current != NULL)
				current->prev = new_node;
			new_node->next = current;
			if (idx != 0)
				prev->next = new_node;
			else
				*head = new_node;
		}
		return (new_node);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	*head = new_node;
	return (new_node);
}
