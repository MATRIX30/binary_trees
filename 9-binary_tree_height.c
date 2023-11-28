#include "binary_trees.h"
/**
 * maximum - function to return the maximum of 2 numbers
 * @a: first number
 * @b: second number
 * Return: the maximum of the numbers a and b
*/
size_t maximum(size_t a, size_t b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of tree
 * Return: the height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + maximum(left_height, right_height));
}
