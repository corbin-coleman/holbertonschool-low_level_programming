#include <stdlib.h>
#include "lists.h"

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;

	count = 0;
	while (count != index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		count++;
	}
	return (head);
}
