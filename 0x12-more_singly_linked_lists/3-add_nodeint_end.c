#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Add a new listint_t node to the end of a list
 * @head: Pointer to the pointer to the start of the list
 * @n: The number to assign to integer value of the node
 *
 * Return: Address of the new node, NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	while (current != NULL && current->next != NULL)
		current = current->next;
	if (current != NULL)
		current->next = new;
	else
		*head = new;
	return (new);
}
