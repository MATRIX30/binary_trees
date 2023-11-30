#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: returns the size of the tree
*/
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
	{
		return (0);
	}
	left_size = tree_size(tree->left);
	right_size = tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * tree_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @j: j of the current node
 * @size: size of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int tree_complete(const binary_tree_t *tree, size_t j, size_t size)
{
	if (tree == NULL)
		return (1);

	if (j >= size)
		return (0);

	return (tree_complete(tree->left, 2 * j + 1, size) &&
		tree_complete(tree->right, 2 * j + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, j = 0;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);

	return (tree_complete(tree, j, size));
}
