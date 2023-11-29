#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;
	binary_tree_t *tmp;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left != NULL)
	{
		tmp = tree->left;
		while (tmp != NULL)
		{
			left_height += 1;
			tmp = tmp->left;
		}
	}
	if (tree->right != NULL)
	{
		tmp = tree->right;
		while (tmp != NULL)
		{
			right_height += 1;
			tmp = tmp->right;
		}
	}
	return (left_height - right_height);
}
