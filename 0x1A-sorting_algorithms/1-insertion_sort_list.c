#include "sort.h"
/**
 *
 *
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *walker;
	listint_t *bkwdwalker;
	listint_t *prevbkwd;

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
