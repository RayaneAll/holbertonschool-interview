#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 *
 * Return: size of the tree
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_at_index - returns the node at a given 1-based index
 * @root: pointer to the root node
 * @index: index in level-order traversal
 *
 * Return: pointer to the node, or NULL on failure
 */
static heap_t *get_node_at_index(heap_t *root, size_t index)
{
	size_t bit;
	heap_t *node;

	if (root == NULL || index == 0)
		return (NULL);

	node = root;
	for (bit = 1; bit <= index; bit <<= 1)
		;
	bit >>= 2;

	while (bit != 0 && node != NULL)
	{
		if (index & bit)
			node = node->right;
		else
			node = node->left;
		bit >>= 1;
	}

	return (node);
}

/**
 * heapify_up - restores max-heap order by bubbling up
 * @node: pointer to the inserted node pointer
 */
static void heapify_up(heap_t **node)
{
	heap_t *current;
	int temp;

	if (node == NULL || *node == NULL)
		return;

	current = *node;
	while (current->parent != NULL && current->parent->n < current->n)
	{
		temp = current->parent->n;
		current->parent->n = current->n;
		current->n = temp;
		current = current->parent;
	}
	*node = current;
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to store in the new node
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	size_t index;
	heap_t *parent;
	heap_t *new_node;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	index = size + 1;
	parent = get_node_at_index(*root, index / 2);
	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (index % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(&new_node);

	return (new_node);
}
