#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: the array of integers
 * @size: number of elements in the array
 *
 * Return: the maximum value
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Sorts array by a specific digit using counting sort
 * @array: the array of integers
 * @size: number of elements in the array
 * @exp: the current significant digit (1, 10, 100, ...)
 * @output: temporary output array
 */
static void counting_sort_digit(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;
	int digit;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}
	for (digit = 1; digit < 10; digit++)
		count[digit] += count[digit - 1];
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers using LSD radix sort
 * @array: the array of integers
 * @size: number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
