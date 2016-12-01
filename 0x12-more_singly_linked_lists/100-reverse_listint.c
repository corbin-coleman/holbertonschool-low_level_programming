#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverse a given list
 * @head: Pointer to a pointer to the list
 *
 * Return: Address of head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current;
	listint_t *next;

	current = *head;
	if (current == NULL)
		return (NULL);
	next = current->next;
	current->next = NULL;
	while (next != NULL)
	{
		current = next;
		next = next->next;
		current->next = *head;
		*head = current;
	}
	return (*head);
}
