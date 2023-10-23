#include <stdio.h>
#include "sort.h"

/**
 * p_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void p_list(const intlist_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}