#include "sort.h"

void swaps_nodeahead(intlist_t **list, intlist_t **tail, intlist_t **shaker);
void swaps_nodeabehind(intlist_t **list, intlist_t **tail, intlist_t **shaker);
void c_sort_list(intlist_t **list);

/**
 * swaps_nodeahead - Swap a node in a intlist_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swaps_nodeahead(intlist_t **list, intlist_t **tail, intlist_t **shaker)
{
	intlist_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swaps_nodeabehind - Swap a node in a intlist_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swaps_nodeabehind(intlist_t **list, intlist_t **tail, intlist_t **shaker)
{
	intlist_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * c_sort_list - Sort a intlist_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a intlist_t doubly-linked list.
 */
void c_sort_list(intlist_t **list)
{
	intlist_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swaps_nodeahead(list, &tail, &shaker);
				p_list((const intlist_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swaps_nodeabehind(list, &tail, &shaker);
				p_list((const intlist_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
