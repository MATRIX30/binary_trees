#include "binary_trees.h"
/**
 * find_min - Finds the minimum root
 * @tree: pointer to the tree
 * Return: the min number
 */

bst_t *find_min(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - removes a node from BST
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removeal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = find_min(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
