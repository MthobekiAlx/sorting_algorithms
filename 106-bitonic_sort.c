/*
 * File: 106-b_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swaps_int(int *a, int *b);
void b_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void b_sequence(int *array, size_t size, size_t start, size_t seq, char flow);
void b_sort(int *array, size_t size);

/**
 * swaps_int - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swaps_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * b_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void b_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swaps_int(array + i, array + i + jump);
		}
		b_merge(array, size, start, jump, flow);
		b_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * b_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void b_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		p_array(array + start, seq);

		b_sequence(array, size, start, cut, UP);
		b_sequence(array, size, start + cut, cut, DOWN);
		b_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		p_array(array + start, seq);
	}
}

/**
 * b_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void b_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	b_sequence(array, size, 0, size, UP);
}
