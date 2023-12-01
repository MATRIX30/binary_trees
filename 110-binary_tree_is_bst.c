#include "binary_trees.h"
#include<limits.h>
/**
 * check_bst - checks if tree is a binary search tree
 * @node: pointr to the root of the tree to check
 * @min: minimun value seen
 * @max: maximum value seen
 * Return: 1 if its BST or 0 otherwise
*/
int check_bst(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
	{
		return (1);
	}
	if (node->n <= min || node->n >= max)
	{
		return (0);
	}
	return (check_bst(node->left, min, node->n) &&
		   check_bst(node->right, node->n, max));
}
/**
 * binary_tree_is_bst - checks if tree is a binary search tree
 * @tree: pointr to the root of the tree to check
 * Return: 1 if its BST or 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (check_bst(tree, INT_MIN, INT_MAX) ? 1 : 0);
}
