#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge Sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *work_array;

	if (size < 2)
		return;

	work_array = malloc(sizeof(int) * size);
	if (!work_array)
		return;

	merge_sort_recursive(array, work_array, 0, size - 1);
	free(work_array);
}

/**
 * merge - merges two sub-arrays into one sorted array
 *
 * @array: original array
 * @work_array: array to work on
 * @left_start: starting index of the left sub-array
 * @left_end: ending index of the left sub-array
 * @right_start: starting index of the right sub-array
 * @right_end: ending index of the right sub-array
 */
void merge(int *array, int *work_array, size_t left_start, size_t left_end,
		   size_t right_start, size_t right_end)
{
	size_t i, j, k;
	size_t left_size = left_end - left_start + 1;
	size_t right_size = right_end - right_start + 1;

	i = left_start;
	j = right_start;
	k = left_start;

	while (i < left_start + left_size && j < right_start + right_size)
	{
		if (work_array[i] <= work_array[j])
			array[k++] = work_array[i++];
		else
			array[k++] = work_array[j++];
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_work_array(work_array, left_start, left_end);

	while (i < left_start + left_size)
		array[k++] = work_array[i++];

	printf("[right]: ");
	print_work_array(work_array, right_start, right_end);

	while (j < right_start + right_size)
		array[k++] = work_array[j++];

	printf("[Done]: ");
	print_work_array(array, left_start, right_end);
}

/**
 * merge_sort_recursive - applies the merge sort algorithm recursively
 *
 * @array: original array
 * @work_array: array to work on
 * @start: starting index
 * @end: ending index
 */
void merge_sort_recursive(int *array, int *work_array, size_t start,
						  size_t end)
{
	size_t middle = (start + end + 1) / 2;

	if (start < end)
	{
		copy_array(array, work_array, start, end);
		merge_sort_recursive(work_array, array, start, middle - 1);
		merge_sort_recursive(work_array, array, middle, end);
		merge(array, work_array, start, middle - 1, middle, end);
	}
}

/**
 * copy_array - copies an array
 *
 * @src: source array
 * @dest: destination array
 * @start: starting index
 * @end: ending index
 */
void copy_array(int *src, int *dest, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
		dest[i] = src[i];
}

/**
 * print_work_array - prints an array
 *
 * @array: array to print
 * @start: starting index
 * @end: ending index
 */
void print_work_array(const int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
		printf("%d%s", array[i], i != end ? ", " : "\n");
}
