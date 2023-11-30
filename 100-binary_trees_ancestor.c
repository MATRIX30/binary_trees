#include "binary_trees.h"
/**
 * binary_trees_ancestor -- calculates the ancestors of 2 nodes
 * @first: first node
 * @second: second node
 * Return: Ancestor if found and NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second) {
	const binary_tree_t *tmp1 = first;
	const binary_tree_t *tmp2 = second;

	while (tmp1)
	{
		tmp2 = second;
		while (tmp2)
		{
			if (tmp1 == tmp2)
			{
				return ((binary_tree_t *)tmp1);
			}
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
