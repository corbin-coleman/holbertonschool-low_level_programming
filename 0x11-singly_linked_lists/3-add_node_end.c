#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node_end - Add a new element to a list_t list at the end
 * @head: Pointer to pointer to start of the list
 * @str: String to copy to str element of list_t item
 *
 * Return: Address of new element, NULL if fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *current;
	unsigned int i;

	i = 0;
	if (*head == NULL)
	{
		new = malloc(sizeof(list_t));
		if (new == NULL)
			return (NULL);
		new->next = NULL;
		*head = new;
		new->str = strdup(str);
		while (str[i] != '\0')
			i++;
		new->len = i;
	}
	else
	{
		current = *head;
		while (1)
		{
			if (current->next == NULL)
				break;
			current = current->next;
		}
		new = malloc(sizeof(list_t));
		if (new == NULL)
			return (NULL);
		new->next = NULL;
		current->next = new;
		new->str = strdup(str);
		while (str[i] != '\0')
			i++;
		new->len = i;
	}
	return (new);
}
