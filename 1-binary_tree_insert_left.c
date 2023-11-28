#include "binary_trees.h"
/**
 * binary_tree_insert_left - function to insert a node to  right
 * child of another node
 * @parent: parent node
 * @value: int value of node to insert
 * Return: pointer to created node or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left = new_node;
		new_node->left->parent = new_node;
	}
	else
	{
		parent->left = new_node;
	}
	return (new_node);

}
