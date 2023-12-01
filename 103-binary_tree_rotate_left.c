#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs left rotation of binary tree
 * @tree: pointer to the root node of tree to rotate
 * Return: pointer to the new root node of the tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (tree->right == NULL)
	{
		return (NULL);
	}
	tmp = tree->right;
	tree->right = tmp->left;
	if (tmp->left != NULL)
		tmp->left->parent = tree;
	tmp->left = tree;
	tmp->parent = tree->parent;
	tree->parent = tmp;
	return (tmp);
}
