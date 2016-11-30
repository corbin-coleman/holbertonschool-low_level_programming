#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Print out a given list, but only once if it loops
 * @head: Pointer to the start of the list
 *
 * Return: Number of nodes, if it fails print 98
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *addresses[100000];
	int count, i, j;

	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	i = 0;
	while (head != NULL)
	{
		j = 0;
		printf("[%p] %d\n", (void *)head, head->n);
		addresses[i] = head;
		i++;
		while (j < i)
		{
			if (head->next == addresses[j])
			{
				head = head->next;
				printf("-> [%p] %d\n", (void *)head, head->n);
				exit(98);
			}
			j++;
		}
		head = head->next;
		count++;
	}
	return (count);
}
