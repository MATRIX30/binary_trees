#include "binary_trees.h"
/**
 * maximum - function to return the maximum of 2 numbers
 * @a: first number
 * @b: second number
 * Return: the maximum of the numbers a and b
*/
int maximum(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of tree
 * Return: the height of the tree
*/
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return (1 + maximum(left_height, right_height));
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height - right_height);
}
