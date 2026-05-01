#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @array: array to print after the swap
 * @size: full size of the array
 * @first: first index
 * @second: second index
 */
static void swap_ints(int *array, size_t size, size_t first, size_t second)
{
	int tmp;

	if (first == second)
		return;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
	print_array(array, size);
}

/**
 * sift_down - restores max heap order below a root
 * @array: array heap
 * @size: full size of the array
 * @root: root index of the subtree
 * @end: exclusive end index of the heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child;
	size_t swap;

	while ((root * 2) + 1 < end)
	{
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 < end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		swap_ints(array, size, root, swap);
		root = swap;
	}
}

/**
 * build_heap - builds a max heap in an array
 * @array: array to transform into a heap
 * @size: size of the array
 */
static void build_heap(int *array, size_t size)
{
	size_t start;

	start = (size - 2) / 2;
	while (1)
	{
		sift_down(array, size, start, size);
		if (start == 0)
			break;
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	build_heap(array, size);

	end = size - 1;
	while (end > 0)
	{
		swap_ints(array, size, 0, end);
		sift_down(array, size, 0, end);
		end--;
	}
}
