#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs right rotation of binary tree
 * @tree: pointer to the root node of tree to rotate
 * Return: pointer to the new root node of the tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (tree->left == NULL)
	{
		return (NULL);
	}
	tmp = tree->left;
	tree->left = tmp->right;
	if (tmp->right != NULL)
		tmp->right->parent = tree;
	tmp->right = tree;
	tmp->parent = tree->parent;
	tree->parent = tmp;
	return (tmp);
}
