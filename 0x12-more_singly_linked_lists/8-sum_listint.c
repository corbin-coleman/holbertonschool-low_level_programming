#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - Add up all the data, integers, from a list
 * @head: Pointer to the start of the list
 *
 * Return: The sum of all data, 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
