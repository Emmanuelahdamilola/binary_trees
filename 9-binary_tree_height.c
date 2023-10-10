#include "binary_trees.h"

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree to calculate the height.
 *
 * Return: The height of the binary tree, 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;
    
	if (!tree)
		return 0;

       	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height) ? left_height : right_height;
}

