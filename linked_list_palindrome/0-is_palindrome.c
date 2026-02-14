#include "lists.h"

/**
 * compare_nodes - compare nodes from both ends of a list recursively
 * @left: pointer to current left-side node pointer
 * @right: current right-side node
 *
 * Return: 1 if nodes match as palindrome, 0 otherwise
 */
static int compare_nodes(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);

	if (compare_nodes(left, right->next) == 0)
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;
	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of head node
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *left;

	if (head == NULL || *head == NULL)
		return (1);

	left = *head;
	return (compare_nodes(&left, *head));
}
