#include "binary_trees.h"
/**
 * binary_tree_delete - deletes a binary tree
 * @tree: pointer to binary tree to be deleted
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	/* base case*/
	if (tree->left == NULL && tree->right == NULL)
	{
		if (tree->parent == NULL)
		{
			free(tree);
		}
		else
		{
			if (tree->parent->left == tree)
			{
				tree->parent->left = NULL;
			}
			else
			{
				tree->parent->right = NULL;
			}
			free(tree);
		}
	}
	else
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
	}
}
