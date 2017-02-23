#include "sort.h"

/**
 * insertion_sort_list - Move a node forward until the one in front is smaller
 * @list: The pointer to the start of the list
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *walker;
	listint_t *bkwdwalker;
	listint_t *prevbkwd;

	if (list == NULL || *list == NULL)
		return;
	walker = *list;
	walker = walker->next;
	while (walker != NULL)
	{
		bkwdwalker = walker;
		walker = walker->next;
		while (bkwdwalker->prev != NULL)
		{
			prevbkwd = bkwdwalker->prev;
			if (bkwdwalker->n < prevbkwd->n)
			{
				prevbkwd->next = bkwdwalker->next;
				if (bkwdwalker->next != NULL)
				{
					bkwdwalker->next->prev = prevbkwd;
				}
				bkwdwalker->next = prevbkwd;
				bkwdwalker->prev = prevbkwd->prev;
				if (bkwdwalker->prev == NULL)
				{
					*list = bkwdwalker;
				}
				else
					prevbkwd->prev->next = bkwdwalker;
				prevbkwd->prev = bkwdwalker;
				print_list(*list);
			}
			else
				break;
		}
	}
}
