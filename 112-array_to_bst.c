#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t len;
	bst_t *tree = NULL;

	len = 0;
	while (len < size)
	{
		bst_insert(&tree, array[len]);
		len += 1;
	}
	return (tree);
}
