#include "regex.h"

/**
 * regex_match - Checks if a string matches a regular expression
 * @str: String to scan
 * @pattern: Regular expression
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (pattern[1] == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		while (*str != '\0' && (*pattern == '.' || *str == *pattern))
		{
			str++;
			if (regex_match(str, pattern + 2))
				return (1);
		}
		return (0);
	}

	if (*str != '\0' && (*pattern == '.' || *str == *pattern))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
