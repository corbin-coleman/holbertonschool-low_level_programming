#include "lists.h"
/**
  * free_dlistint - Free a doubly linked list
  * @head: Pointer to the first node in the list
  */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *kill_node;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
			kill_node = head;
			head = head->next;
			free(kill_node);
		}
	}
}
