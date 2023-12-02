#include "binary_trees.h"
#include<limits.h>
/**
 * maximum - function to return the maximum of 2 numbers
 * @a: first number
 * @b: second number
 * Return: the maximum of the numbers a and b
*/
int maximum(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

int height(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    return 1 + maximum(height(tree->left), height(tree->right));
}

int is_valid_avl_helper(const binary_tree_t *node) {
    if (node == NULL) {
        return 1;
    }

    int left_height = height(node->left);
    int right_height = height(node->right);

    if (abs(left_height - right_height) > 1) {
        return 0;
    }

    return is_valid_avl_helper(node->left) && is_valid_avl_helper(node->right);
}

int binary_tree_is_bst_helper(const binary_tree_t *node, int min, int max) {
    if (node == NULL) {
        return 1;
    }
    if (node->n <= min || node->n >= max) {
        return 0;
    }
    return binary_tree_is_bst_helper(node->left, min, node->n) && 
           binary_tree_is_bst_helper(node->right, node->n, max);
}

int binary_tree_is_avl(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    if (!binary_tree_is_bst_helper(tree, INT_MIN, INT_MAX)) {
        return 0;
    }
    return is_valid_avl_helper(tree) ? 1 : 0;
}
