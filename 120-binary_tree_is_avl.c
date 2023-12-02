#include "binary_trees.h"
#include<limits.h>
/**
 * maximum - function to return the maximum of 2 numbers
 * @a: first number
 * @b: second number
 * Return: the maximum of the numbers a and b
*/
int maximum(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

/**
 * height- returns height of tree
 * @tree: pointer to root node
 * Return: the height of tree
*/
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + maximum(height(tree->left), height(tree->right)));
}

/**
 * valid_avl - checks for validity of avl
 * @node: pointer to root of tree
 * Return: height of tree
*/
int valid_avl(const binary_tree_t *node)
{
	int left_height, right_height;

	if (node == NULL)
	{
		return (1);
	}

	left_height = height(node->left);
	right_height = height(node->right);

	if (abs(left_height - right_height) > 1)
	{
		return (0);
	}

	return (valid_avl(node->left) && valid_avl(node->right));
}

/**
 * is_bst - checks for validity of avl
 * @node: pointer to root of tree
 * @min: minimum
 * @max: maximum
 * Return: 1 if valid 0 otherwise
*/
int is_bst(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);
	if (node->n <= min || node->n >= max)
		return (0);
	return (is_bst(node->left, min, node->n) &&
		   is_bst(node->right, node->n, max));
}
/**
 * binary_tree_is_avl - checks if a tree is an avl
 * @tree: pointer to root of tree
 * Return: 1 if its avl else 0
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (!is_bst(tree, INT_MIN, INT_MAX))
	{
		return (0);
	}
	return (valid_avl(tree) ? 1 : 0);
}
