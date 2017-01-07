#include "lists.h"
/**
  * sum_dlistint - Add up all the values stored in the list
  * @head: Pointer to the start of the list
  * Return: Sum of all values, 0 if list is empty
  */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}
	return (sum);
}
