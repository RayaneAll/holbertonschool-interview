#include "slide_line.h"

/**
 * slide_left - slides and merges an integer line to the left
 * @line: line to process
 * @size: number of elements in line
 */
static void slide_left(int *line, size_t size)
{
	size_t i;
	size_t write = 0;
	int previous = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		if (previous == 0)
			previous = line[i];
		else if (previous == line[i])
		{
			line[write++] = previous * 2;
			previous = 0;
		}
		else
		{
			line[write++] = previous;
			previous = line[i];
		}
	}

	if (previous != 0)
		line[write++] = previous;

	while (write < size)
		line[write++] = 0;
}

/**
 * slide_line - slides and merges a line to left or right
 * @line: line to process
 * @size: number of elements in line
 * @direction: slide direction (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}

	for (i = 0; i < size / 2; i++)
	{
		int tmp = line[i];

		line[i] = line[size - 1 - i];
		line[size - 1 - i] = tmp;
	}

	slide_left(line, size);

	for (i = 0; i < size / 2; i++)
	{
		int tmp = line[i];

		line[i] = line[size - 1 - i];
		line[size - 1 - i] = tmp;
	}

	return (1);
}
