#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long divisor = 1;
	unsigned long leading;
	unsigned long trailing;

	while (n / divisor >= 10)
		divisor *= 10;

	while (n >= 10)
	{
		leading = n / divisor;
		trailing = n % 10;

		if (leading != trailing)
			return (0);

		n = (n % divisor) / 10;
		divisor /= 100;
	}

	return (1);
}
