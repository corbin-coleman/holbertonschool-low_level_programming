#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeaddress - Add a node to a list with
 * @head: Pointer to the pointer of the start of the list
 * @address: The address of another list's node
 *
 * Return: Address of new node, NULL if it fails
 */
listadd_t *add_nodeaddress(listadd_t **head, const listint_t *address)
{
	listadd_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->address = address;
	new->next = *head;
	*head = new;
	return (new);
}


/**
 * print_listint_safe - Print out a given list, but only once if it loops
 * @head: Pointer to the start of the list
 *
 * Return: Number of nodes, if it fails print 98
 */
size_t print_listint_safe(const listint_t *head)
{
	listadd_t *newhead;
	listadd_t *checker;
	unsigned int count;

	count = 0;
	newhead = NULL;
	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		add_nodeaddress(&newhead, head);
		checker = newhead;
		while (checker != NULL)
		{
			if (head->next == checker->address)
			{
				head = head->next;
				printf("-> [%p] %d\n", (void *)head, head->n);
				exit(98);
			}
			checker = checker->next;
		}
		head = head->next;
		count++;
	}
	return (count);
}
