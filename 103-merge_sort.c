#include "sort.h"

void m_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void m_sort_recurs(int *subarr, int *buff, size_t front, size_t back);
void m_sort(int *array, size_t size);

/**
 * m_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void m_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	p_array(subarr + front, mid - front);

	printf("[right]: ");
	p_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	p_array(subarr + front, back - front);
}

/**
 * m_sort_recurs - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void m_sort_recurs(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		m_sort_recurs(subarr, buff, front, mid);
		m_sort_recurs(subarr, buff, mid, back);
		m_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * m_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void m_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	m_sort_recurs(array, buff, 0, size);

	free(buff);
}
