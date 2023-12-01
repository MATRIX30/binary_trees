#include "binary_trees.h"
/**
 * bst_search - searches for a value in BST
 * @tree: pointer to root node of tree to be search
 * @value: value to search in tree
 * Return: pointer to node containing the value or NULL if not found
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *element;

	if (tree == NULL)
	{
		return (NULL);
	}

	if (value == tree->n)
	{
		return ((bst_t *)tree);
	}
	if (value > tree->n)
	{
		element = bst_search(tree->right, value);
	}
	else
	{
		element = bst_search(tree->left, value);
	}

	return (element);
}
