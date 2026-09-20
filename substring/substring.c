#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * str_len - Returns the length of a string
 * @s: The string to measure
 *
 * Return: Length of the string
 */
static int str_len(char const *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * word_index - Finds the index of a word in the words array
 * @words: Array of words to search in
 * @nb_words: Number of words in the array
 * @word: Word to find
 * @word_len: Length of each word
 * @used: Array tracking which words have been used
 *
 * Return: Index of the word if found and not used, -1 otherwise
 */
static int word_index(char const **words, int nb_words,
		char const *word, int word_len, int *used)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (!used[i] && strncmp(words[i], word, word_len) == 0)
			return (i);
	}
	return (-1);
}

/**
 * check_window - Checks if substring at position pos is valid
 * @s: The main string
 * @pos: Starting position to check
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_window(char const *s, int pos, char const **words,
		int nb_words, int word_len)
{
	int *used;
	int i;
	int idx;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		idx = word_index(words, nb_words,
				s + pos + i * word_len, word_len, used);
		if (idx == -1)
		{
			free(used);
			return (0);
		}
		used[idx] = 1;
	}
	free(used);
	return (1);
}

/**
 * find_substring - Finds all substrings that are concatenations of all words
 * @s: The string to scan
 * @words: Array of words all substrings must be a concatenation of
 * @nb_words: Number of elements in the array words
 * @n: Address to store the number of elements in the returned array
 *
 * Return: Allocated array of indices, or NULL if no solution found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len;
	int word_len;
	int total_len;
	int *result;
	int pos;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	s_len = str_len(s);
	word_len = str_len(words[0]);
	total_len = word_len * nb_words;

	if (s_len < total_len)
		return (NULL);

	result = malloc((s_len - total_len + 1) * sizeof(int));
	if (!result)
		return (NULL);

	for (pos = 0; pos <= s_len - total_len; pos++)
	{
		if (check_window(s, pos, words, nb_words, word_len))
		{
			result[*n] = pos;
			(*n)++;
		}
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
