#include <stdio.h>
#include "menger.h"

/**
 * pow3 - computes 3 raised to n
 * @n: exponent
 *
 * Return: 3^n
 */
static int pow3(int n)
{
	int result = 1;

	while (n-- > 0)
		result *= 3;

	return (result);
}

/**
 * is_hole - checks if coordinates are inside an empty sponge zone
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 1 if empty zone, 0 otherwise
 */
static int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}

	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the sponge to draw
 */
void menger(int level)
{
	int size;
	int y;
	int x;

	if (level < 0)
		return;

	size = pow3(level);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
