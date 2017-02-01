#include "lists.h"
/**
  * delete_dnodeint_at_index - Delete a node at a given
  * index in a doubly linked list
  * @head: Double pointer to first node in the list
  * @index: The index to delete the node at
  * Return: 1 if it's successful, -1 if it failed
  */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int pos;
	dlistint_t *current;
	dlistint_t *kill_node;

	if (*head == NULL)
		return (-1);
	pos = 0;
	current = *head;
	while (current->prev != NULL)
		current = current->prev;
	while (current != NULL && pos < index)
	{
		current = current->next;
		pos++;
	}
	if (pos < index)
		return (-1);
	if (pos == 0 && current->next != NULL)
	{
		kill_node = current;
		current = current->next;
		current->prev = NULL;
		*head = current;
		free(kill_node);
		return (1);
	}
	else if (pos > 0)
	{
		kill_node = current;
		current = current->prev;
		current->next = kill_node->next;
		free(kill_node);
	}
	else
	{
		*head = current->next;
		free(current);
	}
	return (1);
}
