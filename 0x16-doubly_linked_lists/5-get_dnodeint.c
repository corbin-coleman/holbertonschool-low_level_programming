#include "lists.h"
/**
  * *get_dnodeint_at_index - Find node at given index in a doubly linked list
  * @head: Pointer to the first node in the list
  * @index: The index of the node to return
  * Return: Address of the node on success, NULL if node doesn't exist
  */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int pos;

	if (head == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;
	if (index == 0)
		return (head);
	pos = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		pos++;
		if (pos == index)
			return (current);
	}
	return (NULL);
}
