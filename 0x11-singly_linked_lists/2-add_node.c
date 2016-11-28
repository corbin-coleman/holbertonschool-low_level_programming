#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node - Add an element to a list at the front of the list
 * @head: Pointer to the pointer to the start of the list
 * @str: Pointer to the string to be put into the element of the list
 *
 * Return: Address of new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int i;

	i = 0;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	while (str[i] != '\0')
		i++;
	new->len = i;
	new->next = *head;
	*head = new;
	return (*head);
}
