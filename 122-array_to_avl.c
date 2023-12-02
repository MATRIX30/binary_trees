#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to insert elements in avl tree
 * @size: array size
 * Return: the resultant avl tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t n, m = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (n = 0; n < size; n++)
	{
		for (m = 0; m < n; m++)
		{
			if (array[m] == array[n])
				break;
		}
		if (m == n)
		{
			if (avl_insert(&root, array[n]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
