#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * _max - goes through a binary tree cheking ropt as _max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are _max, 0 in other cases
 **/
int _max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = _max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = _max(tree->right);
	}
	return (temp1 && temp2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS otherwise 0
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (_max(tree));
}
