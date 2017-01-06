#include "lists.h"
/**
  * *add_dnodeint_end - Add a node to the end of a doubly linked list
  * @head: Pointer to the pointer to the first node of the list
  * @n: The value to store in the new node
  * Return: Address of the new node on success, NULL if it fails
  */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *current;

	current = *head;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	if (current == NULL)
	{
		new_node->next = *head;
		new_node->n = n;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		while (current != NULL && current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
		new_node->n = n;
		new_node->next = NULL;
	}
	return (new_node);
}
