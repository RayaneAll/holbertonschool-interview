#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return: Height of the tree, or -1 if tree is NULL.
 */
static int binary_tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_is_bst - Checks if a tree is a valid BST.
 *
 * @tree: Pointer to the root node.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
static int binary_tree_is_bst(const binary_tree_t *tree, long min, long max)
{
	if (tree == NULL)
		return (1);

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (0);

	if (!binary_tree_is_bst(tree->left, min, (long)tree->n))
		return (0);

	if (!binary_tree_is_bst(tree->right, (long)tree->n, max))
		return (0);

	return (1);
}

/**
 * binary_tree_check_avl - Checks if a tree is balanced.
 *
 * @tree: Pointer to the root node.
 *
 * Return: 1 if the tree is AVL balanced, 0 otherwise.
 */
static int binary_tree_check_avl(const binary_tree_t *tree)
{
	int left_height;
	int right_height;
	int difference;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	difference = left_height - right_height;

	if (difference < -1 || difference > 1)
		return (0);

	if (!binary_tree_check_avl(tree->left))
		return (0);

	if (!binary_tree_check_avl(tree->right))
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree, -2147483649L, 2147483648L))
		return (0);

	return (binary_tree_check_avl(tree));
}
