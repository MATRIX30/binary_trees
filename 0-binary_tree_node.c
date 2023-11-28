#include "binary_trees.h"
/**
* binary_tree_node - function to create a binary tree node
* @parent: pointer to the parent node
* @value: int value held by the node
* Return: pointer to the newly created node if sucessfull Null otherwise
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	/*if allocation space for new_node fails*/
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
