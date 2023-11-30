#include "binary_trees.h"
#include <stdio.h>
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
 * tree_leaves - counts the number of leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the nubmer of leaves
 * Return: the number of leaves in the tree
*/
int tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	return (tree_leaves(tree->left) + tree_leaves(tree->right));
}

/**
 * _pow - computers base to a power
 * @base: base
 * @power: power
 * Return: base ^ power
*/
int _pow(int base, int power)
{
	int res = 1;

	while (power > 0)
	{
		res *= base;
		power = power - 1;
	}
	return (res);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: root node of the tree to check
 * Return: 1 if perfect or 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* approach compute the height of the tree and number of leave nodes*/
	/* make sure leave nodes = 2^h if yes its a perfect tree */
	int leave_nodes, height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	leave_nodes = tree_leaves(tree);
	height = tree_height(tree) - 1;
	return ((leave_nodes == _pow(2, height) ? 1 : 0));
}
