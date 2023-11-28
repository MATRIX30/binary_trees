#include "binary_trees.h"
/**
 * binary_tree_insert_right - adds node to the right of binary tree
 * @parent: parent node
 * @value: int value of node to insert
 * Return: pointer to created node or NULL on failure
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = binary_tree_node(parent, value);
	if (parent == NULL  || new_node == NULL)
	{
		return (NULL);
	}

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right = new_node;
		new_node->right->parent = new_node;
	}
	else
	{
		parent->right = new_node;
	}
	return (new_node);
}
