#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end, *current;

	if (list == NULL)
		return (NULL);

	start = list;
	end = list->express;

	while (end != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
		if (end->n >= value)
			break;
		start = end;
		end = end->express;
	}

	if (end == NULL)
	{
		end = start;
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       start->index, end->index);

	current = start;
	while (current != NULL && current->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
