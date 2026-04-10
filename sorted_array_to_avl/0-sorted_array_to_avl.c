#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_avl_node - creates an AVL node
 * @parent: parent of the node
 * @value: value to store in the node
 *
 * Return: pointer to created node, or NULL on failure
 */
static avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - builds an AVL subtree from a sorted subarray
 * @array: source sorted array
 * @left: left bound index (inclusive)
 * @right: right bound index (inclusive)
 * @parent: parent node
 *
 * Return: pointer to subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, int left, int right, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (left > right)
		return (NULL);

	mid = left + (right - left) / 2;
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, left, mid - 1, root);
	root->right = build_avl(array, mid + 1, right, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of array
 * @size: number of elements in array
 *
 * Return: pointer to AVL root, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
