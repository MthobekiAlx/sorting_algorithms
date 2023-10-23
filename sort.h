#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct intlist_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct intlist_s
{
	const int n;
	struct intlist_s *prev;
	struct intlist_s *next;
} intlist_t;

/* Printing helper functions */
void p_array(const int *array, size_t size);
void p_list(const intlist_t *list);

/* Sorting algoritms */
void _bubble_sort(int *array, size_t size); //bubble_Sort
void insertion_sortlist(intlist_t **list); //insterion_shorlist
void select_sort(int *array, size_t size); //selection_list
void q_sort(int *array, size_t size); //quick sort
void S_sort(int *array, size_t size); //shell sort
void c_sort_list(intlist_t **list); //cocktail sort
void count_sort(int *array, size_t size); // counting sort
void m_sort(int *array, size_t size); // merge sort
void h_sort(int *array, size_t size); //heap sort
void r_sort(int *array, size_t size); //raddix sort
void b_sort(int *array, size_t size); // bitonic sort
void q_sorthoare(int *array, size_t size); //quick sort hoare

#endif /* SORT_H */
