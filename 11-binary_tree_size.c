#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree (number of nodes).
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The size of the binary tree, 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (!tree)
		return (0);
	size = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (size);
}
