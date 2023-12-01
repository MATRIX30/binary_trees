#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *t2;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	t2 = *tree;

	while (t2 != NULL)
	{
		if (t2->n == value)
			return (NULL);
		if (t2->n > value)
		{
			if (t2->left == NULL)
			{
				t2->left = binary_tree_node(t2, value);
				return (t2->left);
			}
			t2 = t2->left;
		}
		if (t2->n < value)
		{
			if (t2->right == NULL)
			{
				t2->right = binary_tree_node(t2, value);
				return (t2->right);
			}
			t2 = t2->right;
		}
	}
	return (NULL);
}
