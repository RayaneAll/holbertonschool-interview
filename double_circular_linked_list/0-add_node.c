#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Creates a new list node
 * @str: string to copy into the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->prev = new;
	new->next = new;
	return (new);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: pointer to the head of the list
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);
	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		*list = new;
		return (new);
	}
	last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - Adds a node to the beginning of a double circular list
 * @list: pointer to the head of the list
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (!list)
		return (NULL);
	new = add_node_end(list, str);
	if (!new)
		return (NULL);
	*list = new;
	return (new);
}
